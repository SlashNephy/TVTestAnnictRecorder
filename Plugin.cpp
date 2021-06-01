#include "pch.h"

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
        // 最低要件
        // どのバージョンの TVTest でも動作する
        return TVTEST_PLUGIN_VERSION_(0, 0, 1);
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
    if (!m_isReady || !m_isEnabled)
    {
        return;
    }

    // ロック
    {
        std::lock_guard lock(m_mutex);

        // ProgramInfo
        TVTest::ProgramInfo Program{};
        wchar_t pszEventName[64]{};
        Program.pszEventName = pszEventName;
        Program.MaxEventName = _countof(pszEventName);
        Program.pszEventText = nullptr;
        Program.pszEventExtText = nullptr;
        if (!m_pApp->GetCurrentProgramInfo(&Program) || Program.EventID == m_lastProgram.EventID)
        {
            return;
        }

        // ServiceInfo
        TVTest::ServiceInfo Service{};
        if (!m_pApp->GetServiceInfo(0, &Service))
        {
            return;
        }

        // ChannelType
        Saya::ChannelType TuningSpace;
        if (wchar_t tuningSpaceName[8]{}; m_pApp->GetTuningSpaceName(m_pApp->GetTuningSpace(), tuningSpaceName, 8) != 0)
        {
            TuningSpace = Saya::GetSayaChannelTypeByName(tuningSpaceName);
        }
        else
        {
            return;
        }

        // YAML::Node
        const auto definition = Saya::FindSayaChannel(m_definitions, TuningSpace, Service.ServiceID);
        if (!definition.has_value())
        {
            return;
        }
        
        HandleProgram(Program, Service, TuningSpace, definition.value());

        m_lastProgram = Program;
    }
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
            pThis->LoadConfig();
            pThis->CheckCurrentProgram();
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
