#include "pch.h"

#include "Debug.h"
#include "SayaApi.h"
#include "Title.h"

constexpr auto AnnictRecorderWindowClass = L"AnnictRecorder Window";
constexpr auto AnnictRecorderTimerId = 1;
constexpr auto AnnictRecorderTimerIntervalMs = 60 * 1000;
constexpr auto AnnictTokenMaxLength = 64;

class CAnnictRecorderPlugin final : public TVTest::CTVTestPlugin
{
    wchar_t m_iniFileName[MAX_PATH]{};
    HWND m_hWnd{};
    TVTest::ProgramInfo m_lastProgram{};
    YAML::Node m_definitions{};
    std::mutex m_mutex;

    wchar_t m_annictToken[AnnictTokenMaxLength]{};
    bool m_isReady = false;
    bool m_isEnabled = false;

    void Enable();
    static void Disable();
    void LoadConfig();
    void CheckCurrentProgram();

    static LRESULT CALLBACK EventCallback(UINT Event, LPARAM lParam1, LPARAM lParam2, void* pClientData);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    /*
     * プラグインのバージョンを返す
     */
    DWORD GetVersion() override
    {
        // TVTest API 0.0.12 以上
        return TVTEST_PLUGIN_VERSION_(0, 0, 12);
    }

    /*
     * プラグインの情報を返す
     */
    bool GetPluginInfo(TVTest::PluginInfo* pInfo) override
    {
        pInfo->Type = TVTest::PLUGIN_TYPE_NORMAL;
        pInfo->pszPluginName = L"Annict Recorder";
        pInfo->pszCopyright = L"© 2021 Nep";
        pInfo->pszDescription = L"視聴したアニメの視聴記録を自動で Annict に送信します。";

        return true;
    }

    /*
     * プラグインの初期化を行う
     * プラグインがロードされたときの処理を記述する (ロード != 有効化であることに注意)
     */
    bool Initialize() override
    {
        // TVTest イベントコールバックの設定
        m_pApp->SetEventCallback(EventCallback, this);

        // ウィンドウクラスの登録
        WNDCLASS wc;
        wc.style = 0;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = g_hinstDLL;
        wc.hIcon = nullptr;
        wc.hCursor = nullptr;
        wc.hbrBackground = nullptr;
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = AnnictRecorderWindowClass;
        if (::RegisterClass(&wc) == 0)
        {
            return false;
        }

        // ウィンドウの作成
        m_hWnd = ::CreateWindowEx(
            0, AnnictRecorderWindowClass, nullptr, WS_POPUP,
            0, 0, 0, 0, HWND_MESSAGE, nullptr, g_hinstDLL, this
        );
        if (m_hWnd == nullptr)
        {
            return false;
        }

        return true;
    }

    /*
     * プラグインの終了処理を行う
     */
    bool Finalize() override
    {
        // タイマー・ウィンドウの破棄
        ::KillTimer(m_hWnd, AnnictRecorderTimerId);
        ::DestroyWindow(m_hWnd);

        return true;
    }
};

/*
 * プラグインのインスタンスを作成する
 */
TVTest::CTVTestPlugin* CreatePluginClass()
{
    return new CAnnictRecorderPlugin;
}

/*
 * プラグインが有効化されたときの処理を記述する
 */
void CAnnictRecorderPlugin::Enable()
{
    // デバッグコンソールの初期化
#ifdef _DEBUG
    CreateConsole();
#endif

    // 設定の読み込み
    LoadConfig();
}

/*
 * プラグインが無効化されたときの処理を記述する
 */
void CAnnictRecorderPlugin::Disable()
{
    // デバッグコンソールの破棄
#ifdef _DEBUG
    DestroyConsole();
#endif
}

/*
 * 設定を読み込む
 */
void CAnnictRecorderPlugin::LoadConfig()
{
    ::GetModuleFileName(g_hinstDLL, m_iniFileName, MAX_PATH);
    ::PathRenameExtension(m_iniFileName, L".ini");

    ::GetPrivateProfileString(L"Annict", L"Token", L"", m_annictToken, AnnictTokenMaxLength, m_iniFileName);

    m_definitions = Saya::LoadSayaDefinitions();
    m_pApp->AddLog(
        std::format(L"saya のチャンネル定義ファイルを読み込みました。(チャンネル数: {})", m_definitions["channels"].size()).c_str()
    );

    m_isReady = wcslen(m_annictToken) > 0;
}

/*
 * 現在の番組をチェックする
 */
void CAnnictRecorderPlugin::CheckCurrentProgram()
{
    // トークンが設定されていないかプラグインが無効
    if (!m_isReady || !m_isEnabled)
    {
        PrintDebug(L"プラグインは無効化されています。");
        return;
    }

    // ロック
    {
        std::lock_guard lock(m_mutex);
        PrintDebug(L"クリティカルセクションに入りました。");

        // ServiceInfo
        TVTest::ServiceInfo Service{};
        if (!m_pApp->GetServiceInfo(0, &Service))
        {
            PrintDebug(L"サービス情報の取得に失敗しました。");
            return;
        }

        // ProgramInfo
        TVTest::ProgramInfo Program{};
        wchar_t pszEventName[64]{};
        Program.pszEventName = pszEventName;
        Program.MaxEventName = _countof(pszEventName);
        Program.pszEventText = nullptr;
        Program.pszEventExtText = nullptr;
        if (!m_pApp->GetCurrentProgramInfo(&Program))
        {
            PrintDebug(L"番組情報の取得に失敗しました。(サービス ID: {}, サービス名: {})", Service.ServiceID, Service.szServiceName);
            return;
        }
        if (Program.EventID == m_lastProgram.EventID)
        {
            PrintDebug(L"前回と同じ番組です。無視します。");
        }

        // EpgEventInfo
        TVTest::EpgEventQueryInfo EpgEventQuery{};
        EpgEventQuery.EventID = Program.EventID;
        EpgEventQuery.ServiceID = Program.ServiceID;
        const auto EpgEvent = m_pApp->GetEpgEventInfo(&EpgEventQuery);
        if (EpgEvent == nullptr|| EpgEvent->ContentList == nullptr || EpgEvent->ContentListLength == 0)
        {
            PrintDebug(L"ジャンル情報の取得に失敗しました。(サービス ID: {}, サービス名: {}, 番組名: {})", Service.ServiceID, Service.szServiceName, Program.pszEventName);
            return;
        }
        bool IsAnimeGenre = false;
        for (auto i = 0; i < EpgEvent->ContentListLength; i++)
        {
            // ReSharper disable once CppTooWideScope
            const auto [ContentNibbleLevel1, ContentNibbleLevel2, _, __] = EpgEvent->ContentList[i];

            // 「アニメ」 or 「映画」→「アニメ」
            if (ContentNibbleLevel1 == 0x7 || (ContentNibbleLevel1 == 0x6 && ContentNibbleLevel2 == 0x2))
            {
                IsAnimeGenre = true;
                break;
            }
        }

        m_pApp->FreeEpgEventInfo(EpgEvent);
        
        if (!IsAnimeGenre)
        {
            PrintDebug(L"アニメジャンルではありません。無視します。");
            return;
        }

        // ChannelType
        Saya::ChannelType ChannelType;
        if (wchar_t tuningSpaceName[8]{}; m_pApp->GetTuningSpaceName(m_pApp->GetTuningSpace(), tuningSpaceName, 8) != 0)
        {
            ChannelType = Saya::GetSayaChannelTypeByName(tuningSpaceName);
        }
        else
        {
            PrintDebug(L"チューニング空間の取得に失敗しました。(サービス ID: {}, サービス名: {})", Service.ServiceID, Service.szServiceName);
            return;
        }

        // YAML::Node
        const auto definition = Saya::FindSayaChannel(m_definitions, ChannelType, Service.ServiceID);
        if (!definition.has_value())
        {
            PrintDebug(L"saya のチャンネル定義に存在しないチャンネルです。(サービス名: {}, サービス ID: {})", Service.szServiceName, Service.ServiceID);
            return;
        }
        
        HandleProgram(Program, Service, ChannelType, definition.value());

        m_lastProgram = Program;
    }

    PrintDebug(L"クリティカルセクションから出ました。");
}

/*
 * TVTest のイベントコールバック
 */
LRESULT CALLBACK CAnnictRecorderPlugin::EventCallback(const UINT Event, const LPARAM lParam1, LPARAM, void* pClientData)
{
    auto* pThis = static_cast<CAnnictRecorderPlugin*>(pClientData);

    switch (Event)
    {
    case TVTest::EVENT_PLUGINENABLE:
        pThis->m_isEnabled = lParam1 == 1;
        if (pThis->m_isEnabled)
        {
            pThis->Enable();
            pThis->CheckCurrentProgram();
        }
        else
        {
            pThis->Disable();
        }

        return true;

    case TVTest::EVENT_CHANNELCHANGE:
    case TVTest::EVENT_SERVICECHANGE:
    case TVTest::EVENT_SERVICEUPDATE:
        pThis->CheckCurrentProgram();

        return true;

    default:
        return false;
    }
}

/*
 * ウィンドウプロシージャ
 * タイマー処理を行う
 */
LRESULT CALLBACK CAnnictRecorderPlugin::WndProc(const HWND hWnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        {
            auto* const pcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
            auto* pThis = static_cast<CAnnictRecorderPlugin*>(pcs->lpCreateParams);

            ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
            ::SetTimer(hWnd, AnnictRecorderTimerId, AnnictRecorderTimerIntervalMs, nullptr);
        }

        return true;

    case WM_TIMER:
        if (wParam == AnnictRecorderTimerId)
        {
            auto* pThis = reinterpret_cast<CAnnictRecorderPlugin*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

            pThis->CheckCurrentProgram();
        }

        return false;

    default:
        return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}
