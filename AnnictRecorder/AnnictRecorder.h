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
        std::optional<Annict::Work> work = std::nullopt;
        std::optional<Annict::Episode> episode = std::nullopt;
        std::optional<std::wstring> url = std::nullopt;
    };

    static void UpdateWorkStatus(
        const uint32_t annictWorkId,
        const bool isFirstEpisode,
        const bool isLastEpisode,
        const Config &Config)
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
            try
            {
                const auto workStatus = Annict::GetMyWorkStatus(annictWorkId, Config.AnnictToken);
                const auto status = workStatus.value_or("no_select");

                if (isFirstEpisode && status == "watched" && Config.SetWatchingStatusOnFirstEpisodeEvenIfWatched)
                {
                    // [新] フラグが付いていて視聴済みの場合であってもステータスを更新する
                    // 分割2クールの場合など
                }
                else if (status == "watched" && Config.SkipUpdateStatusIfAlreadyWatched)
                {
                    return;
                }

                if (status != newStatus.value())
                {
                    if (!Config.RecordDryRun)
                    {
                        Annict::PostMyStatus(annictWorkId, newStatus.value(), Config.AnnictToken);
                    }

                    PrintDebug(L"作品のステータスを「{}」→「{}」に変更しました。(WorkID={})", Multi2Wide(status), Multi2Wide(newStatus.value()), annictWorkId);
                }
            }
            catch (...)
            {
            }
        }
    }

    static CreateRecordResult CreateEpisodeRecord(
        const Annict::Episode &episode,
        const Config &Config)
    {
        std::wstring workTitle;
        if (episode.numberText.has_value())
        {
            workTitle = std::format(
                L"{}「{}」",
                Multi2Wide(episode.numberText.value()),
                Multi2Wide(episode.title.value_or("???")));
        }
        else if (episode.number.has_value())
        {
            workTitle = std::format(
                L"#{}「{}」",
                episode.number.value(),
                Multi2Wide(episode.title.value_or("???")));
        }
        else if (episode.title.has_value())
        {
            workTitle = std::format(
                L"「{}」",
                Multi2Wide(episode.title.value()));
        }
        else
        {
            workTitle = std::format(
                L"「{}」",
                Multi2Wide(episode.work.title));
        }

        if (!Config.RecordDryRun)
        {
            try
            {
                Annict::PostRecord(episode.id, Config.ShareOnTwitter, Config.ShareOnFacebook, Config.AnnictToken);
            }
            catch (...)
            {
                return {
                    false,
                    std::format(L"Annictとの通信に失敗しました。{}を記録できませんでした。", workTitle),
                    episode.work,
                    episode,
                    std::format(L"https://annict.com/works/{}/episodes/{}", episode.work.id, episode.id)};
            }
        }

        return {
            true,
            std::format(L"{}を記録しました。", workTitle),
            episode.work,
            episode,
            std::format(L"https://annict.com/works/{}/episodes/{}", episode.work.id, episode.id)};
    }

    static std::optional<Annict::Episode> FindEpisode(
        const uint32_t annictWorkId,
        const float_t episodeCount,
        const std::optional<std::string> &episodeTitle,
        const Config &Config)
    {
        try
        {
            // Annict からエピソード一覧を取得して, 該当のエピソードを見つける
            const auto episodes = Annict::GetEpisodes(annictWorkId, Config.AnnictToken);
            const auto episodeIterator = std::ranges::find_if(episodes, [episodeCount, episodeTitle](const Annict::Episode &episode)
                                                              {
                    // 話数が一致
                    if (episode.number.has_value() && episodeCount == episode.number.value())  // NOLINT(clang-diagnostic-float-equal)
                    {
                        return true;
                    }

                    // 話数 (テキスト) が一致
                    // まれに Annict 側に number だけ設定されていないデータがあるので文字列比較する
                    if (const auto numberText = std::format("第{:.0f}話", episodeCount); episode.numberText.has_value() && numberText == episode.numberText.value())
                    {
                        return true;
                    }

                    if (const auto numberText = std::format("#{:.0f}", episodeCount); episode.numberText.has_value() && numberText == episode.numberText.value())
                    {
                        return true;
                    }

                    // サブタイトルが一致
                    return episodeTitle.has_value() && episode.title.has_value() && episodeTitle.value() == episode.title.value(); });

            return episodeIterator != episodes.end() ? std::optional(*episodeIterator) : std::nullopt;
        }
        catch (...)
        {
            return std::nullopt;
        }
    }

    static CreateRecordResult CreateEpisodeRecord(
        const uint32_t annictWorkId,
        const float_t episodeCount,
        const std::optional<std::string> &episodeTitle,
        const Config &Config)
    {
        const auto episode = FindEpisode(annictWorkId, episodeCount, episodeTitle, Config);
        if (!episode.has_value())
        {
            PrintDebug(L"Annict でのエピソードデータが見つかりませんでした。スキップします。(WorkID={}, Count={})", annictWorkId, episodeCount);

            return {
                false,
                L"Annictにエピソードデータが見つかりません。"};
        }

        return CreateEpisodeRecord(episode.value(), Config);
    }

    static CreateRecordResult CreateWorkRecord(
        const Annict::Work &work,
        const Config &Config)
    {
        if (!Config.RecordDryRun)
        {
            try
            {
                Annict::PostMyStatus(work.id, "watched", Config.AnnictToken);
            }
            catch (...)
            {
                return {
                    false,
                    std::format(L"Annictとの通信に失敗しました。「{}」を記録できませんでした。", Multi2Wide(work.title)),
                    work,
                    std::nullopt,
                    std::format(L"https://annict.com/works/{}", work.id)};
            }
        }

        return {
            true,
            std::format(L"「{}」を記録しました。", Multi2Wide(work.title)),
            work,
            std::nullopt,
            std::format(L"https://annict.com/works/{}", work.id)};
    }

    static std::vector<CreateRecordResult> CreateRecordEach(
        const Annict::Work &work,
        // 開始話数, 終了話数
        const float_t episodeNumberStart,
        const float_t episodeNumberEnd,
        // エピソード名
        const std::optional<std::string> &episodeTitle,
        // 最初のエピソードであるか
        const bool isFirstEpisode,
        // 最後のエピソードであるか
        const bool isLastEpisode,
        // エピソードを持っているか
        const bool hasNoEpisodes,
        const Config &Config)
    {
        // 劇場版など
        if (hasNoEpisodes)
        {
            // エピソードで別れていない場合, 作品自体を「見た」に設定
            return {
                CreateWorkRecord(work, Config)};
        }

        // エピソードで別れている場合, 該当のエピソードを記録
        auto results = std::vector<CreateRecordResult>();
        for (auto count = episodeNumberStart; count <= episodeNumberEnd; count++) // NOLINT(cert-flp30-c)
        {
            const auto result = CreateEpisodeRecord(work.id, count, episodeTitle, Config);
            results.push_back(result);
        }

        UpdateWorkStatus(work.id, isFirstEpisode, isLastEpisode, Config);

        return results;
    }

    static std::vector<CreateRecordResult> CreateRecord(
        const Config &Config,
        const TVTest::ServiceInfo &Service,
        const TVTest::ProgramInfo &Program,
        const std::optional<const Saya::ChannelType> ChannelType,
        std::map<uint32_t, uint32_t> &AnnictIds,
        const YAML::Node &SayaDefinitions)
    {
        // saya のチャンネル定義
        const auto ChannelDefinition = FindChannel(SayaDefinitions, ChannelType, Service.ServiceID);
        if (!ChannelDefinition.has_value())
        {
            PrintDebug(L"saya のチャンネル定義に存在しないチャンネルです。スキップします。(サービス名: {}, サービス ID: {})", Service.szServiceName, Service.ServiceID);

            return {
                {false,
                 L"sayaのチャンネル定義に存在しないチャンネルです。"}};
        }

        // [新] フラグから第1話判定を行う
        auto isFirstEpisode = IsFirstEpisode(Program);
        // [終] フラグから最終話判定を行う
        auto isLastEpisode = IsLastEpisode(Program);

        // しょぼいカレンダーの ChID が登録されている場合
        if (ChannelDefinition.value().syobocalId.has_value())
        {
            // しょぼいカレンダー ChID
            const auto syoboCalChId = ChannelDefinition.value().syobocalId.value();

            // しょぼいカレンダーに放送時間が登録されている場合
            try
            {
                if (const auto syoboCalPrograms = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId); !syoboCalPrograms.empty())
                {
                    auto results = std::vector<std::vector<CreateRecordResult>>{};
                    for (const auto &syoboCalProgram : syoboCalPrograms)
                    {
                        // kawaiioverflow/arm から しょぼいカレンダー TID → Annict 作品 ID を見つける
                        const auto syoboCalTID = syoboCalProgram.titleId;
                        if (AnnictIds.contains(syoboCalTID))
                        {
                            // しょぼいカレンダー TID と Annict 作品 ID が紐付いている
                            const auto annictWorkId = AnnictIds[syoboCalTID];

                            try
                            {
                                const auto annictWork = Annict::GetWorkById(annictWorkId, Config.AnnictToken);

                                results.push_back(
                                    CreateRecordEach(
                                        annictWork.value(),
                                        syoboCalProgram.countStart,
                                        syoboCalProgram.countEnd,
                                        syoboCalProgram.subTitle,
                                        isFirstEpisode || syoboCalProgram.isFirstEpisode || syoboCalProgram.countStart <= 1,
                                        isLastEpisode || syoboCalProgram.isLastEpisode,
                                        annictWork.value().hasNoEpisodes,
                                        Config));
                            }
                            catch (...)
                            {
                                continue;
                            }
                        }
                        else
                        {
                            // 紐ついていないので、作品名から Annict 作品 ID を見つける
                            try
                            {
                                const auto title = SyoboCal::LookupTitle(syoboCalTID);
                                if (title.has_value())
                                {
                                    const auto workTitle = Wide2Multi(title.value());
                                    if (const auto annictWork = Annict::GetWorkByTitle(workTitle, Config.AnnictToken); annictWork.has_value())
                                    {
                                        results.push_back(
                                            CreateRecordEach(
                                                annictWork.value(),
                                                syoboCalProgram.countStart,
                                                syoboCalProgram.countEnd,
                                                syoboCalProgram.subTitle,
                                                isFirstEpisode || syoboCalProgram.isFirstEpisode || syoboCalProgram.countStart <= 1,
                                                isLastEpisode || syoboCalProgram.isLastEpisode,
                                                annictWork.value().hasNoEpisodes,
                                                Config));
                                    }
                                }
                            }
                            catch (...)
                            {
                                continue;
                            }
                        }
                    }

                    if (results.empty())
                    {
                        return {
                            {false,
                             L"Annictに作品データが見つかりません。"}};
                    }

                    return flatten(results);
                }
            }
            catch (...)
            {
            }
        }

        // Annict の ChID が登録されている場合
        if (ChannelDefinition.value().annictId.has_value())
        {
            const auto annictChId = ChannelDefinition.value().annictId.value();

            FILETIME localFt, utcFt;
            SYSTEMTIME utcStartTime;
            SystemTimeToFileTime(&Program.StartTime, &localFt);
            LocalFileTimeToFileTime(&localFt, &utcFt);
            FileTimeToSystemTime(&utcFt, &utcStartTime);

            // Annict に放送時間が登録されている場合
            try
            {
                if (const auto annictPrograms = Annict::GetMyPrograms(annictChId, utcStartTime, Program.Duration, Config.AnnictToken); !annictPrograms.empty())
                {
                    auto results = std::vector<std::vector<CreateRecordResult>>{};
                    for (const auto &annictProgram : annictPrograms)
                    {
                        if (!annictProgram.episode.number.has_value())
                        {
                            continue;
                        }

                        results.push_back(
                            CreateRecordEach(
                                annictProgram.work,
                                annictProgram.episode.number.value(),
                                annictProgram.episode.number.value(),
                                annictProgram.episode.title,
                                isFirstEpisode || annictProgram.episode.number.value() <= 1, // NOLINT(clang-diagnostic-float-equal)
                                isLastEpisode,
                                annictProgram.work.hasNoEpisodes,
                                Config));
                    }

                    return flatten(results);
                }
            }
            catch (...)
            {
            }
        }

        // しょぼいカレンダー / Annict に放送時間が未登録の場合は正規表現で検出を試みる

        // AT-X
        if (Service.ServiceID == 333)
        {
            const auto extraction = Title::ExtractAtxTitle(Program.pszEventName);
            if (!extraction.found)
            {
                return {
                    {false,
                     L"タイトルの抽出に失敗しました。"}};
            }

            PrintDebug(L"抽出されたタイトル情報: Title={}, Count={} ~ {}", extraction.title, extraction.countStart, extraction.countEnd);

            // タイトルから Annict 作品 ID を見つける
            const auto workTitle = Wide2Multi(extraction.title);
            try
            {
                if (const auto annictWork = Annict::GetWorkByTitle(workTitle, Config.AnnictToken); annictWork.has_value())
                {
                    return CreateRecordEach(
                        annictWork.value(),
                        extraction.countStart,
                        extraction.countEnd,
                        std::nullopt,
                        isFirstEpisode || extraction.countStart == 1, // NOLINT(clang-diagnostic-float-equal)
                        isLastEpisode,
                        annictWork.value().hasNoEpisodes,
                        Config);
                }
            }
            catch (...)
            {
            }

            return {
                {false,
                 L"Annictに作品データが見つかりません。"}};
        }

        PrintDebug(L"しょぼいカレンダー / Annict に放送時刻が登録されていません。スキップします。(Service={}, SID={})", Service.szServiceName, Service.ServiceID);

        return {
            {false,
             L"放送時刻データがありません。"}};
    }
}
