﻿#include "pch.h"

#include "AnnictRecorder.h"
#include "ArmApi.h"
#include "Capture.h"
#include "Config.h"
#include "Debug.h"
#include "SayaApi.h"
#include "TvtPlay.h"
#include "Utils.h"

constexpr auto AnnictRecorderWindowClass = L"AnnictRecorder Window";
constexpr auto AnnictRecorderStatusItemId = WM_APP + 1;
constexpr auto AnnictRecorderTimerId = WM_APP + 2;
constexpr auto AnnictRecorderTimerIntervalMs = 10 * 1000;
constexpr auto MaxEventNameLength = 64;

class CAnnictRecorderPlugin final : public TVTest::CTVTestPlugin
{
  // 設定ファイルへのパス
  wchar_t m_iniFileName[MAX_PATH]{};
  // Window
  HWND m_hWnd{};

  // saya のチャンネル定義 yml
  YAML::Node m_definitions{};
  std::future<void> m_definitionsFuture{};
  // しょぼいカレンダー TID をキーとして Annict 作品 ID を保持する map
  std::map<uint32_t, uint32_t> m_annictIds{};
  std::future<void> m_annictIdsFuture{};
  // Program ID をキーとして番組の視聴を開始したエポック秒を保持する map
  std::map<u_long, time_t> m_watchStartTime{};
  // Program ID をキーとして Annict に記録済かを保持する map
  std::map<u_long, bool> m_recorded{};
  // 前回の Annict の記録の結果を表す構造体
  AnnictRecorder::CreateRecordResult m_lastRecordResult{};
  // CheckCurrentProgram 内の排他ロック
  std::mutex m_mutex{};

  AnnictRecorder::Config m_config{};
  bool m_isReady = false;
  bool m_isEnabled = false;

  void Enable();

  void LoadConfig();

  void CheckCurrentProgram();

  static LRESULT CALLBACK EventCallback(UINT Event, LPARAM lParam1, LPARAM lParam2, void *pClientData);
  static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
  /*
   * プラグインのバージョンを返す
   */
  DWORD GetVersion() override
  {
    // TVTest API 0.0.14 以上
    // (TVTest ver.0.9.0 or later)
    return TVTEST_PLUGIN_VERSION_(0, 0, 14);
  }

  /*
   * プラグインの情報を返す
   */
  bool GetPluginInfo(TVTest::PluginInfo *pInfo) override
  {
    pInfo->Type = TVTest::PLUGIN_TYPE_NORMAL;
    pInfo->Flags = 0;
    pInfo->pszPluginName = L"Annict Recorder";
    pInfo->pszCopyright = L"© 2023 SlashNephy";
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
      m_pApp->AddLog(L"ウィンドウクラスの登録に失敗しました。");
      return false;
    }

    // ウィンドウの作成
    m_hWnd = ::CreateWindowEx(
        0, AnnictRecorderWindowClass, nullptr, WS_POPUP,
        0, 0, 0, 0, HWND_MESSAGE, nullptr, g_hinstDLL, this);
    if (m_hWnd == nullptr)
    {
      m_pApp->AddLog(L"ウィンドウの作成に失敗しました。");
      return false;
    }

    // ステータス項目の登録
    TVTest::StatusItemInfo StatusItem{
        sizeof StatusItem,
        TVTest::STATUS_ITEM_FLAG_TIMERUPDATE,
        0,
        AnnictRecorderStatusItemId,
        L"AnnictRecorder",
        L"Annict Recorder",
        0,
        -1,
        TVTest::StatusItemWidthByFontSize(30),
        0,
    };
    if (!m_pApp->RegisterStatusItem(&StatusItem))
    {
      m_pApp->AddLog(L"ステータス項目の登録に失敗しました。");
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
TVTest::CTVTestPlugin *CreatePluginClass()
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
 * 設定を読み込む
 */
void CAnnictRecorderPlugin::LoadConfig()
{
  ::GetModuleFileName(g_hinstDLL, m_iniFileName, MAX_PATH);
  ::PathRenameExtension(m_iniFileName, L".ini");

  wchar_t annictTokenW[AnnictRecorder::MaxAnnictTokenLength];
  ::GetPrivateProfileString(L"Annict", L"Token", L"", annictTokenW, AnnictRecorder::MaxAnnictTokenLength, m_iniFileName);
  wcstombs_s(nullptr, m_config.AnnictToken, annictTokenW, AnnictRecorder::MaxAnnictTokenLength - 1);

  const auto record = GetPrivateProfileSectionBuffer(L"Record", m_iniFileName);
  m_config.RecordThresholdPercent = GetBufferedProfileInt(record.data(), L"ThresholdPercent", m_config.RecordThresholdPercent);
  m_config.ShareOnTwitter = GetBufferedProfileInt(record.data(), L"ShareOnTwitter", m_config.ShareOnTwitter) > 0;
  m_config.ShareOnFacebook = GetBufferedProfileInt(record.data(), L"ShareOnFacebook", m_config.ShareOnFacebook) > 0;
  m_config.SetWatchingStatusInFirstEpisode = GetBufferedProfileInt(record.data(), L"SetWatchingStatusInFirstEpisode", m_config.SetWatchingStatusInFirstEpisode) > 0;
  m_config.SetWatchingStatusInAnyEpisodes = GetBufferedProfileInt(record.data(), L"SetWatchingStatusInAnyEpisodes", m_config.SetWatchingStatusInAnyEpisodes) > 0;
  m_config.SetWatchedInLastEpisode = GetBufferedProfileInt(record.data(), L"SetWatchedInLastEpisode", m_config.SetWatchedInLastEpisode) > 0;
  m_config.SkipUpdateStatusIfAlreadyWatched = GetBufferedProfileInt(record.data(), L"SkipUpdateStatusIfAlreadyWatched", m_config.SkipUpdateStatusIfAlreadyWatched) > 0;
  m_config.SetWatchingStatusOnFirstEpisodeEvenIfWatched = GetBufferedProfileInt(record.data(), L"SetWatchingStatusOnFirstEpisodeEvenIfWatched", m_config.SetWatchingStatusOnFirstEpisodeEvenIfWatched) > 0;
  m_config.RecordDryRun = GetBufferedProfileInt(record.data(), L"DryRun", m_config.RecordDryRun) > 0;
  m_config.Enabled = GetBufferedProfileInt(record.data(), L"Enabled", m_config.Enabled) > 0;

  wchar_t discordTokenW[AnnictRecorder::MaxDiscordTokenLength];
  ::GetPrivateProfileString(L"Discord", L"Token", L"", discordTokenW, AnnictRecorder::MaxDiscordTokenLength, m_iniFileName);
  wcstombs_s(nullptr, m_config.DiscordToken, discordTokenW, AnnictRecorder::MaxDiscordTokenLength - 1);
  wchar_t discordChannelIdW[AnnictRecorder::MaxDiscordChannelIdLength];
  ::GetPrivateProfileString(L"Discord", L"ChannelId", L"", discordChannelIdW, AnnictRecorder::MaxDiscordChannelIdLength, m_iniFileName);
  wcstombs_s(nullptr, m_config.DiscordChannelId, discordChannelIdW, AnnictRecorder::MaxDiscordChannelIdLength - 1);
  const auto discord = GetPrivateProfileSectionBuffer(L"Discord", m_iniFileName);
  m_config.DiscordDryRun = GetBufferedProfileInt(discord.data(), L"DryRun", m_config.DiscordDryRun) > 0;

  m_definitionsFuture = std::async(
      std::launch::async,
      [this]
      {
        try
        {
          m_definitions = Saya::LoadSayaDefinitions();

          m_pApp->AddLog(std::format(L"sayaのチャンネル定義ファイルを読み込みました。(チャンネル数: {})", m_definitions["channels"].size()).c_str());
        }
        catch (...)
        {
          m_lastRecordResult = {
              false,
              L"sayaのチャンネル定義ファイルが利用できません。",
          };
          m_pApp->AddLog(std::format(L"sayaのチャンネル定義ファイルの読み込みに失敗しました。").c_str(), TVTest::LOG_TYPE_ERROR);
        }
      });

  m_annictIdsFuture = std::async(
      std::launch::async,
      [this]
      {
        try
        {
          Arm::LoadArmJson(m_annictIds);

          m_pApp->AddLog(std::format(L"SlashNephy/arm-supplementaryの定義ファイルを読み込みました。(作品数: {})", m_annictIds.size()).c_str());
        }
        catch (...)
        {
          m_lastRecordResult = {
              false,
              L"SlashNephy/arm-supplementaryの定義ファイルが利用できません。",
          };
          m_pApp->AddLog(std::format(L"SlashNephy/arm-supplementaryの定義ファイルの読み込みに失敗しました。").c_str(), TVTest::LOG_TYPE_ERROR);
        }
      });

  m_isReady = strlen(m_config.AnnictToken) > 0;
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

  if (m_definitionsFuture.wait_for(std::chrono::seconds(0)) != std::future_status::ready || m_definitions.size() == 0)
  {
    PrintDebug(L"saya のチャンネル定義ファイルが利用できません。");
    return;
  }

  if (m_annictIdsFuture.wait_for(std::chrono::seconds(0)) != std::future_status::ready || m_annictIds.empty())
  {
    PrintDebug(L"kawaiioverflow/arm の定義ファイルが利用できません。");
    return;
  }

  // ロック
  {
    std::lock_guard lock(m_mutex);
    PrintDebug(L"クリティカルセクションに入りました。");

    // ProgramInfo
    TVTest::ProgramInfo Program{};
    wchar_t pszEventName[MaxEventNameLength]{};
    Program.pszEventName = pszEventName;
    Program.MaxEventName = _countof(pszEventName);
    Program.pszEventText = nullptr;
    Program.pszEventExtText = nullptr;

    if (!m_pApp->GetCurrentProgramInfo(&Program))
    {
      PrintDebug(L"番組情報の取得に失敗しました。スキップします。");
      return;
    }

    // 番組の固有 ID
    const auto programId = 100000ul * Program.ServiceID + Program.EventID;
    if (m_recorded[programId])
    {
      PrintDebug(L"既に Annict に記録済です。スキップします。");
      return;
    }

    // TvtPlayHwnd
    const auto tvtPlayHwnd = FindTvtPlayFrame();

    // 記録を付ける閾値に達しているかをチェック
    auto shouldRecord = false;
    double percent;
    if (const auto duration = static_cast<double>(Program.Duration); tvtPlayHwnd)
    {
      const auto pos = GetTvtPlayPositionSec(tvtPlayHwnd);
      percent = duration > 0 ? 100.0 * pos / duration : 100;

      shouldRecord = percent >= m_config.RecordThresholdPercent;
      PrintDebug(L"視聴位置 = {:.1f} %", percent);
    }
    else
    {
      time_t watchStartTime;
      if (m_watchStartTime.contains(programId))
      {
        watchStartTime = m_watchStartTime[programId];
      }
      else
      {
        watchStartTime = time(nullptr);
        m_watchStartTime[programId] = watchStartTime;
        return;
      }

      const auto pos = time(nullptr) - watchStartTime;
      percent = duration > 0 ? 100.0 * static_cast<double>(pos) / duration : 100;

      shouldRecord = percent >= m_config.RecordThresholdPercent;
      PrintDebug(L"視聴位置 = {:.1f} %", percent);
    }

    if (!shouldRecord)
    {
      PrintDebug(L"記録するための閾値 ({} %) に達していません。スキップします。", m_config.RecordThresholdPercent);
      if (m_config.Enabled)
      {
        m_lastRecordResult = {
            false,
            std::format(L"AnnictRecorder 待機中... ({:.0f}%)", std::floor(percent)),
        };
      }
      else
      {
        m_lastRecordResult = {
            false,
            L"AnnictRecorder 一時停止中...",
        };
      }

      return;
    }

    if (!m_config.Enabled)
    {
      return;
    }

    // IsAnime
    bool IsAnime = true;
    TVTest::ChannelInfo Channel{};
    if (m_pApp->GetCurrentChannelInfo(&Channel))
    {
      TVTest::EpgEventQueryInfo EpgEventQuery{};
      EpgEventQuery.NetworkID = Channel.NetworkID;
      EpgEventQuery.TransportStreamID = Channel.TransportStreamID;
      EpgEventQuery.ServiceID = Channel.ServiceID;
      EpgEventQuery.Type = TVTest::EPG_EVENT_QUERY_EVENTID;
      EpgEventQuery.EventID = Program.EventID;
      EpgEventQuery.Flags = 0;

      if (const auto EpgEvent = m_pApp->GetEpgEventInfo(&EpgEventQuery); EpgEvent == nullptr)
      {
        // BonDriver_Pipe やチャンネルスキャンしていない場合を考慮して暫定的にアニメジャンルの判定を無視
        PrintDebug(L"EPG 情報の取得に失敗しました。(ネットワークID: {}, サービス ID: {}, 番組名: {})", Channel.NetworkID, Program.ServiceID, Program.pszEventName);
      }
      else
      {
        IsAnime = IsAnimeGenre(*EpgEvent);

        // EpgEventInfo の解放
        m_pApp->FreeEpgEventInfo(EpgEvent);
      }
    }
    else
    {
      PrintDebug(L"チャンネル情報の取得に失敗しました。(サービス ID: {}, 番組名: {})", Program.ServiceID, Program.pszEventName);
    }

    if (!IsAnime)
    {
      PrintDebug(L"アニメジャンルではありません。スキップします。");
      m_lastRecordResult = {
          false,
          L"アニメジャンルではありません。",
      };

      return;
    }

    AnnictRecorder::CreateRecordResult Success{};
    AnnictRecorder::CreateRecordResult Failed{true};
    for (const auto &result : CreateRecord(m_config, Program, m_annictIds, m_definitions))
    {
      if (result.success)
      {
        m_pApp->AddLog(L"Annict に視聴記録を送信しました。");
        m_pApp->AddLog(result.message.c_str());
        Success = result;
      }
      else
      {
        Failed = result;
      }
    }

    if (!Failed.success)
    {
      m_pApp->AddLog(L"Annict に視聴記録を送信できませんでした。Annict 上に見つからない作品か, しょぼいカレンダーに放送時間が登録されていません。", TVTest::LOG_TYPE_WARNING);
      m_pApp->AddLog(Failed.message.c_str());
      m_pApp->AddLog(std::format(L"番組名: {}, ネットワークID: {}, サービスID: {}", Program.pszEventName, Channel.NetworkID, Program.ServiceID).c_str());
    }

    m_lastRecordResult = Failed.success ? Success : Failed;
    m_recorded[programId] = true;
  }

  PrintDebug(L"クリティカルセクションから出ました。");
}

/*
 * TVTest のイベントコールバック
 */
LRESULT CALLBACK CAnnictRecorderPlugin::EventCallback(const UINT Event, const LPARAM lParam1, LPARAM, void *pClientData)
{
  auto *pThis = static_cast<CAnnictRecorderPlugin *>(pClientData);

  switch (Event)
  {
  case TVTest::EVENT_PLUGINENABLE:
    pThis->m_isEnabled = lParam1 == 1;

    if (pThis->m_isEnabled)
    {
      pThis->Enable();
    }

    return true;

  case TVTest::EVENT_CHANNELCHANGE:
  case TVTest::EVENT_SERVICECHANGE:
  case TVTest::EVENT_SERVICEUPDATE:
    pThis->m_lastRecordResult = {};

    std::thread([pThis]
                { pThis->CheckCurrentProgram(); })
        .detach();

    return true;

  case TVTest::EVENT_STATUSITEM_DRAW:
    // ステータス項目の描画
    {
      const auto pInfo = reinterpret_cast<const TVTest::StatusItemDrawInfo *>(lParam1);

      std::wstring status;
      if ((pInfo->Flags & TVTest::STATUS_ITEM_DRAW_FLAG_PREVIEW) == 0)
      {
        // 通常の項目の描画
        status = pThis->m_lastRecordResult.message;
      }
      else
      {
        // プレビュー(設定ダイアログ)の項目の描画
        status = L"第8話「あたしって、ほんとバカ」を記録しました。";
      }

      pThis->m_pApp->ThemeDrawText(
          pInfo->pszStyle,
          pInfo->hdc,
          status.c_str(),
          pInfo->DrawRect,
          DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS,
          pInfo->Color);
    }

    return true;

    // ステータス項目の通知
  case TVTest::EVENT_STATUSITEM_NOTIFY:
  {
    switch (const auto *pInfo = reinterpret_cast<const TVTest::StatusItemEventInfo *>(lParam1); pInfo->Event)
    {
    // 項目が作成された
    case TVTest::STATUS_ITEM_EVENT_CREATED:
    {
      TVTest::StatusItemSetInfo StatusItemSet{};
      StatusItemSet.Size = sizeof StatusItemSet;
      StatusItemSet.Mask = TVTest::STATUS_ITEM_SET_INFO_MASK_STATE;
      StatusItemSet.ID = AnnictRecorderStatusItemId;
      StatusItemSet.StateMask = TVTest::STATUS_ITEM_STATE_VISIBLE;
      // プラグインが有効であれば項目を表示状態にする
      StatusItemSet.State = pThis->m_pApp->IsPluginEnabled() ? TVTest::STATUS_ITEM_STATE_VISIBLE : 0;

      pThis->m_pApp->SetStatusItem(&StatusItemSet);
    }

      return true;

      // 更新タイマー
    case TVTest::STATUS_ITEM_EVENT_UPDATETIMER:
      // true を返すと再描画される
      return true;

    default:
      return false;
    }
  }

    // ステータス項目のマウス操作
  case TVTest::EVENT_STATUSITEM_MOUSE:
  {
    switch (const auto pInfo = reinterpret_cast<const TVTest::StatusItemMouseEventInfo *>(lParam1); pInfo->Action)
    {
    // マウスの左ボタン
    case TVTest::STATUS_ITEM_MOUSE_ACTION_LDOWN:
    {
      if (pThis->m_lastRecordResult.url.has_value())
      {
        ShellExecute(nullptr, nullptr, pThis->m_lastRecordResult.url.value().c_str(), nullptr, nullptr, SW_SHOW);
      }
      else
      {
        pThis->m_config.Enabled = !pThis->m_config.Enabled;
        WritePrivateProfileInt(L"Record", L"Enabled", pThis->m_config.Enabled, pThis->m_iniFileName);

        std::thread(
            [pThis]
            { pThis->CheckCurrentProgram(); })
            .detach();
      }

      return true;
    }
    case TVTest::STATUS_ITEM_MOUSE_ACTION_RDOWN:
    {
      std::thread(
          [pThis]
          {
            auto bitmap = pThis->m_pApp->CaptureImage();
            if (bitmap != nullptr)
            {
              const auto result = Capture::ConvertToPng(bitmap);
              if (result.has_value())
              {
                const auto json = nlohmann::json(
                    {
                        {"content", ""},
                        // {"nonce", ""},
                        {"channel_id", pThis->m_config.DiscordChannelId},
                        {"type", 0},
                        {"sticker_ids", nlohmann::json::array()},
                        {
                            "attachments",
                            nlohmann::json::array(
                                {
                                    {
                                        {"id", "0"},
                                        {"filename", "unknown.png"},
                                    },
                                }),
                        },
                    });

                const auto jsonContent = json.dump();
                if (!pThis->m_config.DiscordDryRun)
                {
                  try
                  {
                    const auto response = cpr::Post(
                        cpr::Url{std::format("https://discord.com/api/v9/channels/{}/messages", pThis->m_config.DiscordChannelId)},
                        cpr::Header{
                            {"accept", "*/*"},
                            {"accept-language", "ja"},
                            {"authorization", pThis->m_config.DiscordToken},
                            {"origin", "https://discord.com"},
                            {"x-discord-locale", "ja"},
                        },
                        cpr::UserAgent{"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) discord/1.0.9005 Chrome/91.0.4472.164 Electron/13.6.6 Safari/537.36"},
                        cpr::Multipart{
                            {
                                "files[0]",
                                cpr::Buffer{
                                    result.value().begin(),
                                    result.value().end(),
                                    "unknown.png",
                                },
                                "image/png",
                            },
                            {"payload_json", jsonContent, "application/json"},
                        });

                    PrintDebug(L"Status = {}", response.status_code);
                  }
                  catch (...)
                  {
                  }
                }
              }

              pThis->m_pApp->MemoryFree(bitmap);
            }
          })
          .detach();

      return true;
    }
    default:
      return false;
    }
  }

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
    auto *const pcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
    auto *pThis = static_cast<CAnnictRecorderPlugin *>(pcs->lpCreateParams);

    ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
    SetTimer(hWnd, AnnictRecorderTimerId, AnnictRecorderTimerIntervalMs, nullptr);
  }

    return true;

  case WM_TIMER:
    if (wParam == AnnictRecorderTimerId)
    {
      auto *pThis = reinterpret_cast<CAnnictRecorderPlugin *>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

      std::thread(
          [pThis]
          { pThis->CheckCurrentProgram(); })
          .detach();
    }

    return false;

  default:
    return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
  }
}
