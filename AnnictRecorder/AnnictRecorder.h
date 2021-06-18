#pragma once

#include "pch.h"

#include "AnnictApi.h"
#include "Config.h"
#include "SayaApi.h"
#include "Title.h"

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

    static std::vector<CreateRecordResult> CreateEpisodeRecord(
        const uint32_t annictWorkId,
        const bool isLastEpisode,
        const std::optional<float_t> episodeCount,
        const std::optional<std::string> episodeTitle,
        const Config& Config
    )
    {
        // Annict からエピソード一覧を取得して, 該当のエピソードを見つける
        const auto episodes = Annict::GetEpisodes(annictWorkId, Config.annictToken);
        const auto episodeIterator = std::ranges::find_if(episodes, [episodeCount, episodeTitle](const nlohmann::json& episode)
        {
            // 話数が一致
            if (episodeCount.has_value() && episode["number"].is_number() && episodeCount.value() == episode["number"].get<float_t>())  // NOLINT(clang-diagnostic-float-equal)
            {
                return true;
            }

            // 話数 (テキスト) が一致
            // まれに Annict 側に number だけ設定されていないデータがあるので文字列比較する
            if (episodeCount.has_value())
            {
                if (const auto numberText = std::format("第{:.0f}話", episodeCount.value()); episode["number_text"].is_string() && numberText == episode["number_text"].get<std::string>())
                {
                    return true;
                }

                if (const auto numberText = std::format("#{:.0f}", episodeCount.value()); episode["number_text"].is_string() && numberText == episode["number_text"].get<std::string>())
                {
                    return true;
                }
            }
            
            // サブタイトルが一致
            return episodeTitle.has_value() && episode["title"].is_string() && episodeTitle.value() == episode["title"].get<std::string>();
        });

        if (episodeIterator == episodes.end())
        {
            PrintDebug(L"Annict でのエピソードデータが見つかりませんでした。スキップします。(WorkID={}, Count={})", annictWorkId, episodeCount.value_or(0));
            return std::vector{
                CreateRecordResult{
                    false,
                    L"Annictにエピソードデータが見つかりません。"
                }
            };
        }

        const auto& targetEpisode = *episodeIterator;
        if (!Config.dryRun)
        {
            const auto annictEpisodeId = targetEpisode["id"].get<uint32_t>();
            Annict::PostRecord(annictEpisodeId, Config.annictToken, Config.shareOnTwitter, Config.shareOnFacebook);
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
                episodeName.value_or(L"？？？")
            );
        }
        else if (episodeNumberText.has_value())
        {
            message = std::format(
                L"{}「{}」を記録しました。",
                episodeNumberText.value(),
                episodeName.value_or(L"？？？")
            );
        }
        else if (episodeName.has_value())
        {
            message = std::format(
                L"「{}」を記録しました。",
                episodeName.value_or(L"？？？")
            );
        }
        else
        {
            message = std::format(
                L"「{}」を記録しました。",
                workName.value_or(L"？？？")
            );
        }

        auto results = std::vector{
            CreateRecordResult{
                true,
                message,
                workName,
                episodeName,
                episodeNumber,
                episodeNumberText
            }
        };

        if (isLastEpisode)
        {
            if (!Config.dryRun)
            {
                Annict::PostMyStatus(annictWorkId, Config.annictToken, "watched");
            }

            results.push_back(
                CreateRecordResult{
                    true,
                    std::format(L"「{}」を「見た」に変更しました。", workName.value_or(L"？？？")),
                    workName,
                    episodeName,
                    episodeNumber,
                    episodeNumberText
                }
            );
        }

        return results;
    }

    static std::vector<CreateRecordResult> CreateWorkRecord(
        const uint32_t annictWorkId,
        const nlohmann::json& annictWork,
        const Config& Config
    )
    {
        if (!Config.dryRun) {
            Annict::PostMyStatus(annictWorkId, Config.annictToken, "watched");
        }

        const auto workName = GetWStringOrNull(annictWork, "title");

        return std::vector{
            CreateRecordResult{
                true,
                std::format(L"「{}」を記録しました。", workName.value_or(L"タイトル不明")),
                workName, std::nullopt, std::nullopt, std::nullopt
            }
        };
    }

    static std::vector<CreateRecordResult> CreateAtxRecord(
        const Config& Config,
        const std::wstring& EventName,
        const bool IsLastEpisode
    )
    {
        const auto extraction = Title::ExtractAtxTitle(EventName);
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

        const auto title = Wide2Multi(extraction.title);
        const auto annictWork = Annict::SearchWorkIdOrNull(title, Config.annictToken);
        if (!annictWork.has_value())
        {
            return std::vector{
                CreateRecordResult{
                    false,
                    L"Annictに作品データが見つかりません。"
                }
            };
        }

        const auto annictWorkId = annictWork.value();

        auto results = std::vector<CreateRecordResult>();
        for (auto count = extraction.countStart; count <= extraction.countEnd; count++)
        {
            for (const auto& r : CreateEpisodeRecord(annictWorkId, IsLastEpisode, count, std::nullopt, Config))
            {
                results.push_back(r);
            }
        }

        return results;
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
        auto isLastEpisode = std::wstring(Program.pszEventName).find(L"[終]") != std::string::npos;

        // ChannelDefinition
        const auto ChannelDefinition = FindSayaChannel(SayaDefinitions, ChannelType, Service.ServiceID);
        if (!ChannelDefinition.has_value())
        {
            PrintDebug(L"sayaのチャンネル定義に存在しないチャンネルです。スキップします。(サービス名: {}, サービス ID: {})", Service.szServiceName, Service.ServiceID);

            return std::vector{
                CreateRecordResult{
                    false,
                    L"sayaのチャンネル定義に存在しないチャンネルです。"
                }
            };
        }

        // しょぼいカレンダーに登録されていないチャンネルは無視
        const auto rawSyoboCalId = ChannelDefinition.value()["syobocalId"];
        if (!rawSyoboCalId.IsDefined())
        {
            PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。スキップします。");
            return std::vector{
                CreateRecordResult{
                    false,
                    L"しょぼいカレンダーに登録されていないチャンネルです。"
                }
            };
        }

        // しょぼいカレンダーに放送時刻で問い合わせる
        const auto syoboCalChId = rawSyoboCalId.as<int>();
        const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
        if (!syoboCalProgram.has_value())
        {
            // しょぼいカレンダーに放送時間が未登録の場合は正規表現で検出を試みる

            // AT-X
            if (Service.ServiceID == 333)
            {
                return CreateAtxRecord(Config, Program.pszEventName, isLastEpisode);
            }

            PrintDebug(L"しょぼいカレンダーに放送時刻が登録されていません。スキップします。(ChID={})", syoboCalChId);
            return std::vector{
                CreateRecordResult{
                    false,
                    L"しょぼいカレンダーに放送時刻データがありません。"
                }
            };
        }

        isLastEpisode |= syoboCalProgram.value().isLastEpisode;

        // kawaiioverflow/arm から しょぼいカレンダー TID → Annict Work ID を見つける
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

        const auto annictWorkId = AnnictIds[syoboCalTID];
        const auto annictWork = Annict::GetWorkOrNull(annictWorkId, Config.annictToken);
        if (!annictWork.has_value())
        {
            PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={}, WorkID={})", syoboCalTID, annictWorkId);
            return std::vector{
                CreateRecordResult{
                    false,
                    L"Annictに作品データが見つかりません。"
                }
            };
        }

        // エピソードで別れている場合, 該当のエピソードを記録
        if (!annictWork.value()["no_episodes"].get<bool>())
        {
            auto results = std::vector<CreateRecordResult>();
            for (auto count = syoboCalProgram.value().countStart; count <= syoboCalProgram.value().countEnd; count++)
            {
                for (const auto& r : CreateEpisodeRecord(annictWorkId, isLastEpisode, count, syoboCalProgram.value().subTitle, Config))
                {
                    results.push_back(r);
                }
            }

            return results;
        }

        // エピソードで別れていない場合 (映画など), 作品自体を「見た」に設定
        return CreateWorkRecord(annictWorkId, annictWork.value(), Config);

    }
}
