#pragma once

#include "pch.h"

#include "Debug.h"
#include "SyoboCalApi.h"

namespace Annict
{
    constexpr auto DefinitionsYmlUrl = "https://raw.githubusercontent.com/SlashNephy/TVTestAnnictRecorder/master/docs/AnnictRecorder.ids.yml";

    inline YAML::Node LoadIdsYml()
    {
        const auto response = cpr::Get(
            cpr::Url{DefinitionsYmlUrl},
            cpr::UserAgent{AnnictRecorderUserAgent}
        );

        return YAML::Load(response.text)["tid2annict"];
    }

    static void PostRecord(const uint32_t episodeId, const std::string& annictToken)
    {
        cpr::Post(
            cpr::Url{"https://api.annict.com/v1/me/records"},
            cpr::Parameters{
                {"episode_id", std::to_string(episodeId)},
                {"access_token", annictToken}
            },
            cpr::UserAgent{AnnictRecorderUserAgent}
        );
    }

    static nlohmann::json GetEpisodes(const uint16_t workId, const std::string& annictToken)
    {
        // Paging not supported
        const auto response = cpr::Get(
            cpr::Url{"https://api.annict.com/v1/episodes"},
            cpr::Parameters{
                {"filter_work_id", std::to_string(workId)},
                {"fields", "id,title,number,number_text,work.title"},
                {"sort_id", "desc"},
                {"per_page", "50"},
                {"access_token", annictToken}
            }
        );

        const auto json = nlohmann::json::parse(response.text);
        return json["episodes"];
    }

    inline std::optional<std::wstring> GetStringOrNull(const nlohmann::json& json, const std::string& key)
    {
        if (!json.is_object() || json[key].is_null())
        {
            return std::nullopt;
        }

        // ロケールの設定
        setlocale(LC_ALL, ".utf8");

        wchar_t buf[256];
        const auto value = json[key].get<std::string>();
        mbstowcs_s(nullptr, buf, value.c_str(), 255);

        return std::optional(buf);
    }

    struct CreateRecordResult
    {
        bool success = false;
        std::optional<std::wstring> workName{};
        std::optional<std::wstring> episodeName{};
        std::optional<uint16_t> episodeNumber{};
        std::optional<std::wstring> episodeNumberText{};
    };

    static CreateRecordResult CreateRecord(
        const std::string& annictToken,
        const TVTest::ProgramInfo& Program,
        const YAML::Node& ChannelDefinition,
        const YAML::Node& AnnictIds,
        const bool DryRun
    )
    {
        // しょぼいカレンダーに登録されていないチャンネルは無視
        const auto rawSyoboCalId = ChannelDefinition["syobocalId"];
        if (!rawSyoboCalId.IsDefined())
        {
            PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。スキップします。");
            return CreateRecordResult{};
        }

        const auto syoboCalChId = rawSyoboCalId.as<int>();
        const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
        if (!syoboCalProgram.has_value())
        {
            PrintDebug(L"しょぼいカレンダーに放送時間が登録されていません。スキップします。(ChID={})", syoboCalChId);
            return CreateRecordResult{};
        }

        const auto syoboCalTitleId = std::to_string(syoboCalProgram.value().titleId);
        const auto annictWorkId = AnnictIds[syoboCalTitleId].IsDefined() ? std::optional(AnnictIds[syoboCalTitleId].as<uint16_t>()) : std::nullopt;
        if (!annictWorkId.has_value())
        {
            PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={})", syoboCalProgram.value().titleId);
            return CreateRecordResult{};
        }

        PrintDebug(L"Annict ID ={}", annictWorkId.value());

        const auto episodes = GetEpisodes(annictWorkId.value(), annictToken);
        const auto currentEpisode = std::ranges::find_if(episodes, [syoboCalProgram](const nlohmann::json& episode)
        {
            return syoboCalProgram.value().count == episode["number"].get<float_t>();  // NOLINT(clang-diagnostic-float-equal)
        });

        if (currentEpisode == episodes.end())
        {
            PrintDebug(L"Annict でのエピソードデータが見つかりませんでした。スキップします。(TID={}, Work ID={})", syoboCalProgram.value().titleId, annictWorkId.value());
            return CreateRecordResult{};
        }

        const auto annictEpisodeId = (*currentEpisode)["id"].get<uint32_t>();
        if (!DryRun)
        {
            PostRecord(annictEpisodeId, annictToken);
        }

        PrintDebug(L"Annict に視聴を記録しました。(TID={}, Work ID={}, Episode ID={})", syoboCalProgram.value().titleId, annictWorkId.value(), annictEpisodeId);
        return CreateRecordResult{
            true,
            GetStringOrNull((*currentEpisode)["work"], "title"),
            GetStringOrNull(*currentEpisode, "title"),
            !(*currentEpisode)["number"].is_null() ? std::optional((*currentEpisode)["number"].get<uint16_t>()) : std::nullopt,
            GetStringOrNull(*currentEpisode, "number_text")
        };
    }
}
