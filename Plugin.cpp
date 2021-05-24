#include "pch.h"

#include <ctime>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

constexpr auto TVTestAnnictRecorderWindowClass = L"TVTestAnnictRecorder Window";
constexpr auto TVTestAnnictRecorderTimerId = 1;
constexpr auto TVTestAnnictRecorderTimerIntervalMs = 5000;
constexpr auto AnnictTokenMaxLength = 32;

class CAnnictRecorderPlugin final : public TVTest::CTVTestPlugin
{
    TCHAR m_iniFileName[MAX_PATH]{};
    HWND m_hwnd{};
    TVTest::ProgramInfo m_lastProgram{};

    wchar_t m_annictToken[AnnictTokenMaxLength]{};
    bool m_isReady = false;
    bool m_isEnabled = false;

    void LoadConfig();
    void CheckCurrentProgram();

    static LRESULT CALLBACK EventCallback(UINT Event, LPARAM lParam1, LPARAM lParam2, void* pClientData);
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    /*
     * プラグインのバージョンを返す
     */
    DWORD GetVersion() override
    {
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
        wc.lpszClassName = TVTestAnnictRecorderWindowClass;
        if (::RegisterClass(&wc) == 0)
        {
            return false;
        }

        // ウィンドウの作成
        m_hwnd = ::CreateWindowEx(
            0, TVTestAnnictRecorderWindowClass, nullptr, WS_POPUP,
            0, 0, 0, 0, HWND_MESSAGE, nullptr, g_hinstDLL, this
        );
        if (m_hwnd == nullptr)
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
        ::KillTimer(m_hwnd, TVTestAnnictRecorderTimerId);
        ::DestroyWindow(m_hwnd);

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

    // Program
    TVTest::ProgramInfo Program{};
    wchar_t pszEventName[128];
    Program.pszEventName = pszEventName;
    Program.MaxEventName = _countof(pszEventName);
    wchar_t pszEventText[128];
    Program.pszEventText = pszEventText;
    Program.MaxEventText = _countof(pszEventText);
    wchar_t pszEventExtText[128];
    Program.pszEventExtText = pszEventExtText;
    Program.MaxEventExtText = _countof(pszEventExtText);

    if (!m_pApp->GetCurrentProgramInfo(&Program))
    {
        return;
    }

    // TODO
    m_lastProgram = Program;
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
LRESULT CALLBACK CAnnictRecorderPlugin::WndProc(const HWND hwnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        {
            auto* const pcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
            auto* pThis = static_cast<CAnnictRecorderPlugin*>(pcs->lpCreateParams);

            ::SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
            ::SetTimer(hwnd, TVTestAnnictRecorderTimerId, TVTestAnnictRecorderTimerIntervalMs, nullptr);
        }

        return true;

    case WM_TIMER:
        if (wParam == TVTestAnnictRecorderTimerId)
        {
            auto* pThis = reinterpret_cast<CAnnictRecorderPlugin*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));

            pThis->CheckCurrentProgram();
        }

        return false;

    default:
        return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
