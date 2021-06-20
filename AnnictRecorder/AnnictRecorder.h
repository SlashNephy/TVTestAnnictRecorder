#pragma once

#include "pch.h"

#include "AnnictApi.h"
#include "Config.h"
#include "Debug.h"
#include "SayaApi.h"
#include "Title.h"
#include "Utils.h"
#include "SyoboCalApi.h"

namespace AnnictRecorder
{
    struct CreateRecordResult
    {
        bool success = false;
        std::wstring message{L"AnnictRecorder 待機中..."};
        std::optional<std::wstring> workName{};
        std::optional<std::wstring> episodeName{};
        std::optional<uint16_t> episodeNumber{};
        std::optional<std::wstring> episodeNumberText{};
    };

    static std::optional<std::wstring> GetWStringOrNull(const nlohmann::json& json, const std::string& key)
    {
        if (!json.is_object() || !json[key].is_string())
        {
            return std::nullopt;
        }

        const auto value = json[key].get<std::string>();
        return std::optional(Multi2Wide(value));
    }

    static void UpdateWorkStatus(
        const uint32_t annictWorkId,
        const bool isFirstEpisode,
        const bool isLastEpisode,
        const Config& Config
    )
    {
        std::optional<std::string> newStatus;
        if (isLastEpisode && Config.SetWatchedInLastEpisode)
        {
            newStatus = "watched";
        }
        else if ((isFirstEpisode && Config.SetWatchingStatusInFirstEpisode) || (!isLastEpisode && Config.SetWatchingStatusInAnyEpisodes))
        {
            newStatus = "watching";
        }

        if (newStatus.has_value())
        {
            const auto work = Annict::GetMyWork(annictWorkId, Config.AnnictToken);
            const auto status = work.has_value() ? work.value()["status"]["kind"].get<std::string>() : "no_select";

            if (status == "watched" && Config.SkipUpdateStatusIfAlreadyWatched)
            {
                return;
            }

            if (status != newStatus.value())
            {
                if (!Config.DryRun)
                {
                    Annict::PostMyStatus(annictWorkId, newStatus.value(), Config.AnnictToken);
                }

                PrintDebug(L"作品のステータスを「{}」→「{}」に変更しました。(WorkID={})", Multi2Wide(status), Multi2Wide(newStatus.value()), annictWorkId);
            }
        }
    }

    static CreateRecordResult CreateEpisodeRecord(
        const uint32_t annictWorkId,
        const float_t episodeCount,
        const std::optional<std::string>& episodeTitle,
        const Config& Config
    )
    {
        // Annict からエピソード一覧を取得して, 該当のエピソードを見つける
        const auto episodes = Annict::GetEpisodes(annictWorkId, Config.AnnictToken);
        const auto episodeIterator = std::ranges::find_if(episodes, [episodeCount, episodeTitle](const nlohmann::json& episode)
        {
            // 話数が一致
            if (episode["number"].is_number() && episodeCount == episode["number"].get<float_t>())  // NOLINT(clang-diagnostic-float-equal)
            {
                return true;
            }

            // 話数 (テキスト) が一致
            // まれに Annict 側に number だけ設定されていないデータがあるので文字列比較する
            if (const auto numberText = std::format("第{:.0f}話", episodeCount); episode["number_text"].is_string() && numberText == episode["number_text"].get<std::string>())
            {
                return true;
            }

            if (const auto numberText = std::format("#{:.0f}", episodeCount); episode["number_text"].is_string() && numberText == episode["number_text"].get<std::string>())
            {
                return true;
            }
            
            // サブタイトルが一致
            return episodeTitle.has_value() && episode["title"].is_string() && episodeTitle.value() == episode["title"].get<std::string>();
        });

        if (episodeIterator == episodes.end())
        {
            PrintDebug(L"Annict でのエピソードデータが見つかりませんでした。スキップします。(WorkID={}, Count={})", annictWorkId, episodeCount);

            return {
                false,
                L"Annictにエピソードデータが見つかりません。"
            };
        }

        const auto& targetEpisode = *episodeIterator;
        if (!Config.DryRun)
        {
            const auto annictEpisodeId = targetEpisode["id"].get<uint32_t>();
            Annict::PostRecord(annictEpisodeId, Config.ShareOnTwitter, Config.ShareOnFacebook, Config.AnnictToken);
        }

        const auto workName = GetWStringOrNull(targetEpisode["work"], "title");
        const auto episodeName = GetWStringOrNull(targetEpisode, "title");
        const auto episodeNumber = targetEpisode["number"].is_number() ? std::optional(targetEpisode["number"].get<uint16_t>()) : std::nullopt;
        const auto episodeNumberText = GetWStringOrNull(targetEpisode, "number_text");

        std::wstring message;
        if (episodeNumber.has_value()) {
            message = std::format(
                L"#{}「{}」を記録しました。",
                episodeNumber.value(),
                episodeName.value_or(L"タイトル不明")
            );
        }
        else if (episodeNumberText.has_value())
        {
            message = std::format(
                L"{}「{}」を記録しました。",
                episodeNumberText.value(),
                episodeName.value_or(L"タイトル不明")
            );
        }
        else if (episodeName.has_value())
        {
            message = std::format(
                L"「{}」を記録しました。",
                episodeName.value()
            );
        }
        else
        {
            message = std::format(
                L"「{}」を記録しました。",
                workName.value_or(L"タイトル不明")
            );
        }

        return {
            true,
            message,
            workName,
            episodeName,
            episodeNumber,
            episodeNumberText
        };
    }

    static CreateRecordResult CreateWorkRecord(
        const uint32_t annictWorkId,
        const std::string& workTitle,
        const Config& Config
    )
    {
        if (!Config.DryRun) {
            Annict::PostMyStatus(annictWorkId, Config.AnnictToken, "watched");
        }

        const auto workName = Multi2Wide(workTitle);

        return {
            true,
            std::format(L"「{}」を記録しました。", workName),
            workName,
            std::nullopt,
            std::nullopt,
            std::nullopt
        };
    }

    static std::vector<CreateRecordResult> CreateRecord(
        const Config& Config,
        const TVTest::ServiceInfo& Service,
        const TVTest::ProgramInfo& Program,
        const std::optional<const Saya::ChannelType> ChannelType,
        std::map<uint32_t, uint32_t>& AnnictIds,
        const YAML::Node& SayaDefinitions
    )
    {
        // しょぼいカレンダー Ch ID
        int syoboCalChId;

        // saya のチャンネル定義からしょぼいカレンダーの Ch ID を見つける
        if (const auto ChannelDefinition = FindSayaChannel(SayaDefinitions, ChannelType, Service.ServiceID); ChannelDefinition.has_value())
        {
            if (const auto rawSyoboCalId = ChannelDefinition.value()["syobocalId"]; rawSyoboCalId.IsDefined())
            {
                syoboCalChId = rawSyoboCalId.as<int>();
            }
            else
            {
                PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。スキップします。");

                return std::vector{
                    CreateRecordResult{
                        false,
                        L"しょぼいカレンダーに登録されていないチャンネルです。"
                    }
                };
            }
        }
        else
        {
            PrintDebug(L"saya のチャンネル定義に存在しないチャンネルです。スキップします。(サービス名: {}, サービス ID: {})", Service.szServiceName, Service.ServiceID);

            return std::vector{
                CreateRecordResult{
                    false,
                    L"sayaのチャンネル定義に存在しないチャンネルです。"
                }
            };
        }

        // Annict 作品 ID
        uint32_t annictWorkId{};
        // 作品名
        std::string workTitle{};
        // 話数
        float_t episodeNumberStart{}, episodeNumberEnd{};
        // エピソード名
        std::optional<std::string> episodeTitle = std::nullopt;
        // [新] と [終] フラグから第1話 or 最終話判定を行う
        auto isFirstEpisode = std::wstring(Program.pszEventName).find(L"[新]") != std::string::npos;
        auto isLastEpisode = std::wstring(Program.pszEventName).find(L"[終]") != std::string::npos;
        // 作品がエピソードデータを持たない (劇場版など)
        bool hasNoEpisodes{};

        // しょぼいカレンダーに放送時間が登録されている場合
        if (const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId); syoboCalProgram.has_value())
        {
            // kawaiioverflow/arm から しょぼいカレンダー TID → Annict 作品 ID を見つける
            const auto syoboCalTID = syoboCalProgram.value().titleId;
            if (!AnnictIds.contains(syoboCalTID))
            {
                PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={})", syoboCalTID);

                return std::vector{
                    CreateRecordResult{
                        false,
                        L"Annictに作品データが見つかりません。"
                    }
                };
            }

            annictWorkId = AnnictIds[syoboCalTID];

            const auto annictWork = Annict::GetWorkById(annictWorkId, Config.AnnictToken);
            workTitle = annictWork.value()["title"].get<std::string>();
            episodeNumberStart = syoboCalProgram.value().countStart;
            episodeNumberEnd = syoboCalProgram.value().countEnd;
            episodeTitle = syoboCalProgram.value().subTitle;
            isFirstEpisode |= syoboCalProgram.value().isFirstEpisode;
            isFirstEpisode |= syoboCalProgram.value().countStart == 1;  // NOLINT(clang-diagnostic-float-equal)
            isLastEpisode |= syoboCalProgram.value().isLastEpisode;
            hasNoEpisodes = annictWork.value()["no_episodes"].get<bool>();
        }
        // しょぼいカレンダーに放送時間が未登録の場合は正規表現で検出を試みる
        else
        {
            // AT-X
            if (Service.ServiceID == 333)
            {
                const auto extraction = Title::ExtractAtxTitle(Program.pszEventName);
                if (!extraction.found)
                {
                    return std::vector{
                        CreateRecordResult{
                            false,
                            L"タイトルの抽出に失敗しました。"
                        }
                    };
                }

                PrintDebug(L"抽出されたタイトル情報: Title={}, Count={} ~ {}", extraction.title, extraction.countStart, extraction.countEnd);

                // タイトルから Annict 作品 ID を見つける
                workTitle = Wide2Multi(extraction.title);
                if (const auto annictWork = Annict::GetWorkByTitle(workTitle, Config.AnnictToken); annictWork.has_value())
                {
                    annictWorkId = annictWork.value()["id"].get<uint32_t>();
                    episodeNumberStart = extraction.countStart;
                    episodeNumberEnd = extraction.countEnd;
                    isFirstEpisode |= extraction.countStart == 1;  // NOLINT(clang-diagnostic-float-equal)
                    hasNoEpisodes = annictWork.value()["no_episodes"].get<bool>();
                }
                else
                {
                    return std::vector{
                        CreateRecordResult{
                            false,
                            L"Annictに作品データが見つかりません。"
                        }
                    };
                }
            }
            else
            {
                PrintDebug(L"しょぼいカレンダーに放送時刻が登録されていません。スキップします。(ChID={})", syoboCalChId);

                return std::vector{
                    CreateRecordResult{
                        false,
                        L"しょぼいカレンダーに放送時刻データがありません。"
                    }
                };
            }
        }

        // 劇場版など
        if (hasNoEpisodes)
        {
            // エピソードで別れていない場合, 作品自体を「見た」に設定
            return std::vector{
                CreateWorkRecord(annictWorkId, workTitle, Config)
            };
        }

        // エピソードで別れている場合, 該当のエピソードを記録
        auto results = std::vector<CreateRecordResult>();
        for (auto count = episodeNumberStart; count <= episodeNumberEnd; count++)  // NOLINT(cert-flp30-c)
        {
            const auto result = CreateEpisodeRecord(annictWorkId, count, episodeTitle, Config);
            results.push_back(result);
        }

        UpdateWorkStatus(annictWorkId, isFirstEpisode, isLastEpisode, Config);

        return results;
    }
}
