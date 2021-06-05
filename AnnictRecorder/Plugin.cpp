#include "pch.h"

#include "AnnictApi.h"
#include "Debug.h"
#include "SayaApi.h"
#include "TvtPlay.h"
#include "Utils.h"

constexpr auto AnnictRecorderWindowClass = L"AnnictRecorder Window";
constexpr auto AnnictRecorderTimerId = 1;
constexpr auto AnnictRecorderTimerIntervalMs = 5 * 1000;
constexpr auto MaxEventNameLength = 64;

class CAnnictRecorderPlugin final : public TVTest::CTVTestPlugin
{
    wchar_t m_iniFileName[MAX_PATH]{};
    HWND m_hWnd{};
    YAML::Node m_definitions{};
    std::map<WORD, time_t> m_watchStartTime{};
    std::map<WORD, bool> m_recorded{};
    std::mutex m_mutex{};

    char m_annictToken[MaxAnnictTokenLength]{};
    int m_recordThresholdPercent = 20;
    bool m_dryRun = false;
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
        // (TVTest ver.0.7.14 or later)
        return TVTEST_PLUGIN_VERSION_(0, 0, 12);
    }

    /*
     * プラグインの情報を返す
     */
    bool GetPluginInfo(TVTest::PluginInfo* pInfo) override
    {
        pInfo->Type = TVTest::PLUGIN_TYPE_NORMAL;
        pInfo->Flags = 0;
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

    // 設定の読み込み
    LoadConfig();
}

/*
 * プラグインが無効化されたときの処理を記述する
 */
void CAnnictRecorderPlugin::Disable()
{
}

/*
 * 設定を読み込む
 */
void CAnnictRecorderPlugin::LoadConfig()
{
    ::GetModuleFileName(g_hinstDLL, m_iniFileName, MAX_PATH);
    ::PathRenameExtension(m_iniFileName, L".ini");

    wchar_t annictTokenW[MaxAnnictTokenLength];
    ::GetPrivateProfileString(L"Annict", L"Token", L"", annictTokenW, MaxAnnictTokenLength, m_iniFileName);
    m_recordThresholdPercent = ::GetPrivateProfileInt(L"Record", L"ThresholdPercent", m_recordThresholdPercent, m_iniFileName);
    m_dryRun = ::GetPrivateProfileInt(L"Record", L"DryRun", m_dryRun, m_iniFileName) > 0;

    wcstombs_s(nullptr, m_annictToken, annictTokenW, MaxAnnictTokenLength - 1);

    m_definitions = Saya::LoadSayaDefinitions();
    m_pApp->AddLog(
        std::format(L"saya のチャンネル定義ファイルを読み込みました。(チャンネル数: {})", m_definitions["channels"].size()).c_str()
    );

    m_isReady = strlen(m_annictToken) > 0;
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

        // ServiceInfo: サブチャンネルを考慮する
        std::optional<TVTest::ServiceInfo> Service = std::nullopt;
        for (auto i = 0; i < 3; i++)
        {
            TVTest::ServiceInfo service{};
            if (m_pApp->GetServiceInfo(i, &service))
            {
                Service = std::optional(service);
                break;
            }
        }

        if (!Service.has_value())
        {
            PrintDebug(L"サービス情報の取得に失敗しました。スキップします。");
            return;
        }

        // ProgramInfo
        TVTest::ProgramInfo Program{};
        wchar_t pszEventName[MaxEventNameLength]{};
        Program.pszEventName = pszEventName;
        Program.MaxEventName = _countof(pszEventName);
        Program.pszEventText = nullptr;
        Program.pszEventExtText = nullptr;

        if (!m_pApp->GetCurrentProgramInfo(&Program))
        {
            PrintDebug(L"番組情報の取得に失敗しました。スキップします。(サービス ID: {}, サービス名: {})", Service.value().ServiceID, Service.value().szServiceName);
            return;
        }

        // TvtPlayHwnd
        const auto tvtPlayHwnd = FindTvtPlayFrame();

        // 記録を付ける閾値に達しているかをチェック
        auto shouldRecord = false;
        if (const auto duration = static_cast<double>(Program.Duration); tvtPlayHwnd)
        {
            const auto pos = GetTvtPlayPositionSec(tvtPlayHwnd);
            const auto percent = 100.0 * pos / duration;
            
            shouldRecord = percent >= m_recordThresholdPercent;
            PrintDebug(L"視聴位置 = {:.1f} %", percent);
        }
        else
        {
            time_t watchStartTime;
            if (m_watchStartTime.contains(Program.EventID))
            {
                watchStartTime = m_watchStartTime[Program.EventID];
            }
            else
            {
                watchStartTime = time(nullptr);
                m_watchStartTime[Program.EventID] = watchStartTime;
                return;
            }

            const auto pos = time(nullptr) - watchStartTime;
            const auto percent = 100.0 * static_cast<double>(pos) / duration;

            shouldRecord = percent >= m_recordThresholdPercent;
            PrintDebug(L"視聴位置 = {:.1f} %", percent);
        }

        if (!shouldRecord)
        {
            PrintDebug(L"記録するための閾値 ({} %) に達していません。スキップします。", m_recordThresholdPercent);
            return;
        }
        
        if (m_recorded[Program.EventID]) {
            PrintDebug(L"既に Annict に記録済です。スキップします。");
            return;
        }

        // IsAnime
        bool IsAnime = false;
        TVTest::EpgEventQueryInfo EpgEventQuery{};
        EpgEventQuery.EventID = Program.EventID;
        EpgEventQuery.ServiceID = Program.ServiceID;

        if (const auto EpgEvent = m_pApp->GetEpgEventInfo(&EpgEventQuery); EpgEvent == nullptr)
        {
            // BonDriver_Pipe やチャンネルスキャンしていない場合を考慮して暫定的にアニメジャンルの判定を無視
            IsAnime = true;

            PrintDebug(L"EPG 情報の取得に失敗しました。(サービス ID: {}, サービス名: {}, 番組名: {})", Service.value().ServiceID, Service.value().szServiceName, Program.pszEventName);
            // return;
        } else
        {
            IsAnime = IsAnimeGenre(*EpgEvent);

            // EpgEventInfo の解放
            m_pApp->FreeEpgEventInfo(EpgEvent);
        }

        if (!IsAnime)
        {
            PrintDebug(L"アニメジャンルではありません。スキップします。");
            return;
        }

        // ChannelType
        std::optional<Saya::ChannelType> ChannelType = std::nullopt;
        TVTest::TuningSpaceInfo TuningSpace{};
        if (m_pApp->GetTuningSpaceInfo(m_pApp->GetTuningSpace(), &TuningSpace))
        {
            // チューナー空間名からチャンネルタイプを取得
            ChannelType = Saya::GetSayaChannelTypeByName(TuningSpace.szName);

            // チューナー空間の enum からチャンネルタイプを取得
            if (!ChannelType.has_value())
            {
                ChannelType = Saya::GetSayaChannelTypeByIndex(TuningSpace.Space);
            }
        }

        if (!ChannelType.has_value())
        {
            PrintDebug(L"チューニング空間の取得に失敗しました。(サービス ID: {}, サービス名: {})", Service.value().ServiceID, Service.value().szServiceName);
        }
        
        // ChannelDefinition
        const auto ChannelDefinition = FindSayaChannel(m_definitions, ChannelType, Service.value().ServiceID);
        if (!ChannelDefinition.has_value())
        {
            PrintDebug(L"saya のチャンネル定義に存在しないチャンネルです。スキップします。(サービス名: {}, サービス ID: {})", Service.value().szServiceName, Service.value().ServiceID);
            return;
        }

        if (const auto [success, workName, episodeName, episodeNumber] = Annict::CreateRecord(m_annictToken, Program, ChannelDefinition.value(), m_dryRun); success)
        {
            // MessageBox(
            //     nullptr,
            //     std::format(L"{} ({}) の視聴記録を送信しました。", episodeName.value_or(L"サブタイトル不明"), episodeNumber.value_or(L"第？話")).c_str(),
            //     std::format(L"Annict Recorder: {}", workName.value_or(L"")).c_str(),
            //     0
            // );

            m_pApp->AddLog(L"Annict に視聴記録を送信しました。");
            m_pApp->AddLog(
                std::format(L"Annict 作品名: {}, エピソード名: {} ({})", workName.value_or(L""), episodeName.value_or(L""), episodeNumber.value_or(L"")).c_str()
            );
        }

        m_recorded[Program.EventID] = true;
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
