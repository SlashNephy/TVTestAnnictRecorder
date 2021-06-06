#pragma once

#include "pch.h"

#include "AnnictApi.h"
#include "SayaApi.h"

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

    static CreateRecordResult CreateEpisodeRecord(
        const uint32_t annictWorkId,
        const SyoboCal::LookupProgramResult& syobocalProgram,
        const std::string& annictToken,
        const bool dryRun
    )
    {
        // Annict からエピソード一覧を取得して, 該当のエピソードを見つける
        const auto episodes = Annict::GetEpisodes(annictWorkId, annictToken);
        const auto episodeIterator = std::ranges::find_if(episodes, [syobocalProgram](const nlohmann::json& episode)
        {
            return syobocalProgram.count == episode["number"].get<float_t>();  // NOLINT(clang-diagnostic-float-equal)
        });

        if (episodeIterator == episodes.end())
        {
            PrintDebug(L"Annict でのエピソードデータが見つかりませんでした。スキップします。(TID={}, WorkID={})", syobocalProgram.titleId, annictWorkId);
            return {
                false,
                L"Annictにエピソードデータが見つかりません。"
            };
        }

        const auto& targetEpisode = *episodeIterator;
        if (!dryRun)
        {
            const auto annictEpisodeId = targetEpisode["id"].get<uint32_t>();
            Annict::PostRecord(annictEpisodeId, annictToken);
        }

        const auto workName = GetWStringOrNull(targetEpisode["work"], "title");
        const auto episodeName = GetWStringOrNull(targetEpisode, "title");
        const auto episodeNumber = !targetEpisode["number"].is_null() ? std::optional(targetEpisode["number"].get<uint16_t>()) : std::nullopt;
        const auto episodeNumberText = GetWStringOrNull(targetEpisode, "number_text");

        return {
            true,
            std::format(
                L"#{:2d}「{}」を記録しました。",
                episodeNumber.value_or(0),
                episodeName.value_or(L"サブタイトル不明")
            ),
            workName, episodeName, episodeNumber, episodeNumberText
        };
    }

    static CreateRecordResult CreateWorkRecord(
        const uint32_t annictWorkId,
        const nlohmann::json& annictWork,
        const std::string& annictToken,
        const bool dryRun
    )
    {
        if (!dryRun) {
            Annict::PostMyStatus(annictWorkId, annictToken);
        }

        const auto workName = GetWStringOrNull(annictWork, "title");

        return {
            true,
            std::format(L"「{}」を記録しました。", workName.value_or(L"タイトル不明")),
            workName, std::nullopt, std::nullopt, std::nullopt
        };
    }

    static CreateRecordResult CreateRecord(
        const std::string& annictToken,
        const TVTest::ServiceInfo& Service,
        const TVTest::ProgramInfo& Program,
        const std::optional<const Saya::ChannelType> ChannelType,
        std::map<uint32_t, uint32_t>& AnnictIds,
        YAML::Node& SayaDefinitions,
        const bool DryRun
    )
    {
        // ChannelDefinition
        const auto ChannelDefinition = FindSayaChannel(SayaDefinitions, ChannelType, Service.ServiceID);
        if (!ChannelDefinition.has_value())
        {
            PrintDebug(L"sayaのチャンネル定義に存在しないチャンネルです。スキップします。(サービス名: {}, サービス ID: {})", Service.szServiceName, Service.ServiceID);

            return {
                false,
                L"sayaのチャンネル定義に存在しないチャンネルです。"
            };
        }

        // しょぼいカレンダーに登録されていないチャンネルは無視
        const auto rawSyoboCalId = ChannelDefinition.value()["syobocalId"];
        if (!rawSyoboCalId.IsDefined())
        {
            PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。スキップします。");
            return {
                false, L"しょぼいカレンダーに登録されていないチャンネルです。"
            };
        }

        // しょぼいカレンダーに放送時刻で問い合わせる
        const auto syoboCalChId = rawSyoboCalId.as<int>();
        const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
        if (!syoboCalProgram.has_value())
        {
            PrintDebug(L"しょぼいカレンダーに放送時刻が登録されていません。スキップします。(ChID={})", syoboCalChId);
            return {
                false, L"しょぼいカレンダーに放送時刻データがありません。"
            };
        }

        // kawaiioverflow/arm から しょぼいカレンダー TID → Annict Work ID を見つける
        const auto syoboCalTID = syoboCalProgram.value().titleId;
        if (!AnnictIds.contains(syoboCalTID))
        {
            PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={})", syoboCalTID);
            return {
                false, L"Annictに作品データが見つかりません。"
            };
        }

        const auto annictWorkId = AnnictIds[syoboCalTID];
        const auto annictWork = Annict::GetWorkOrNull(annictWorkId, annictToken);
        if (!annictWork.has_value())
        {
            PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={}, WorkID={})", syoboCalTID, annictWorkId);
            return {
                false, L"Annictに作品データが見つかりません。"
            };
        }

        // エピソードで別れている場合, 該当のエピソードを記録
        if (!annictWork.value()["no_episodes"].get<bool>())
        {
            return CreateEpisodeRecord(annictWorkId, syoboCalProgram.value(), annictToken, DryRun);
        }

        // エピソードで別れていない場合 (映画など), 作品自体を「見た」に設定
        return CreateWorkRecord(annictWorkId, annictWork.value(), annictToken, DryRun);

    }
}
