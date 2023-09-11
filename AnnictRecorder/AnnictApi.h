#pragma once

#include "pch.h"

#include "Common.h"
#include "Debug.h"
#include "Utils.h"

namespace Annict {
    static void PostRecord(const uint32_t episodeId, const bool shareOnTwitter, const bool shareOnFacebook,
                           const std::string &annictToken) {
        cpr::Post(
                cpr::Url{"https://api.annict.com/v1/me/records"},
                cpr::Parameters{
                        {"episode_id",     std::to_string(episodeId)},
                        {"access_token",   annictToken},
                        {"share_twitter",  shareOnTwitter ? "true" : "false"},
                        {"share_facebook", shareOnFacebook ? "true" : "false"}
                },
                cpr::UserAgent{AnnictRecorderUserAgent}
        );
    }

    static void PostMyStatus(const uint32_t workId, const std::string &kind, const std::string &annictToken) {
        cpr::Post(
                cpr::Url{"https://api.annict.com/v1/me/statuses"},
                cpr::Parameters{
                        {"work_id",      std::to_string(workId)},
                        {"kind",         kind},
                        {"access_token", annictToken}
                },
                cpr::UserAgent{AnnictRecorderUserAgent}
        );
    }

    struct Work {
        uint32_t id;
        std::string title;
        bool hasNoEpisodes;
    };

    static std::optional <Work> GetWorkById(const uint32_t workId, const std::string &annictToken) {
        const auto response = cpr::Get(
                cpr::Url{"https://api.annict.com/v1/works"},
                cpr::Parameters{
                        {"filter_ids",   std::to_string(workId)},
                        {"fields",       "id,title,no_episodes"},
                        {"access_token", annictToken}
                }
        );

        const auto json = nlohmann::json::parse(response.text);
        if (json["total_count"].get<int>() == 0) {
            return std::nullopt;
        }

        const auto item = json["works"][0];
        return Work{
                item["id"].get<uint32_t>(),
                item["title"].get<std::string>(),
                item["no_episodes"].get<bool>()
        };
    }

    static std::optional <Work> GetWorkByTitle(const std::string &title, const std::string &annictToken) {
        const auto response = cpr::Get(
                cpr::Url{"https://api.annict.com/v1/works"},
                cpr::Parameters{
                        {"filter_title", title},
                        {"fields",       "id,title,no_episodes"},
                        {"per_page",     "50"},
                        {"access_token", annictToken}
                }
        );

        for (const auto json = nlohmann::json::parse(response.text); auto &item: json["works"]) {
            if (const auto itemTitle = item["title"].get<std::string>(); title == itemTitle) {
                return Work{
                        item["id"].get<uint32_t>(),
                        itemTitle,
                        item["no_episodes"].get<bool>()
                };
            }
        }

        return std::nullopt;
    }

    struct Episode {
        uint32_t id;
        std::optional <std::string> title;
        std::optional <float_t> number;
        std::optional <std::string> numberText;
        Work work;
    };

    static std::vector <Episode> GetEpisodes(const uint32_t workId, const std::string &annictToken) {
        // Paging not supported
        const auto response = cpr::Get(
                cpr::Url{"https://api.annict.com/v1/episodes"},
                cpr::Parameters{
                        {"filter_work_id", std::to_string(workId)},
                        {"fields",         "id,title,number,number_text,work.id,work.title,work.no_episodes"},
                        {"sort_id",        "desc"},
                        {"per_page",       "50"},
                        {"access_token",   annictToken}
                }
        );

        const auto json = nlohmann::json::parse(response.text);

        auto results = std::vector<Episode>();
        for (auto &item: json["episodes"]) {
            results.push_back({
                                      item["id"].get<uint32_t>(),
                                      item["title"].is_string() ? std::optional(item["title"].get<std::string>())
                                                                : std::nullopt,
                                      item["number"].is_number() ? std::optional(item["number"].get<float_t>())
                                                                 : std::nullopt,
                                      item["number_text"].is_string() ? std::optional(
                                              item["number_text"].get<std::string>()) : std::nullopt,
                                      {
                                              item["work"]["id"].get<uint32_t>(),
                                              item["work"]["title"].get<std::string>(),
                                              item["work"]["no_episodes"].get<bool>()
                                      }
                              });
        }

        return results;
    }

    static std::optional <std::string> GetMyWorkStatus(const uint32_t workId, const std::string &annictToken) {
        const auto response = cpr::Get(
                cpr::Url{"https://api.annict.com/v1/me/works"},
                cpr::Parameters{
                        {"filter_ids",   std::to_string(workId)},
                        {"fields",       "status.kind"},
                        {"access_token", annictToken}
                }
        );

        const auto json = nlohmann::json::parse(response.text);
        if (json["total_count"].get<int>() == 0) {
            return std::nullopt;
        }

        const auto item = json["works"][0]["status"]["kind"];
        return item.is_string() ? std::optional(item.get<std::string>()) : std::nullopt;
    }

    struct Program {
        Work work;
        Episode episode;
    };

    static std::vector <Program>
    GetMyPrograms(const int channelId, const SYSTEMTIME &start, const DWORD seconds, const std::string &annictToken) {
        const auto stTime = std::format("{:04d}/{:02d}/{:02d} {:02d}:{:02d}", start.wYear, start.wMonth, start.wDay,
                                        start.wHour, start.wMinute);
        const auto endTimestamp = SystemTime2Timet(start) + seconds;
        tm end{};
        localtime_s(&end, &endTimestamp);
        const auto endTime = std::format("{:04d}/{:02d}/{:02d} {:02d}:{:02d}", end.tm_year + 1900, end.tm_mon + 1,
                                         end.tm_mday, end.tm_hour, end.tm_min);

        PrintDebugW(L"stTime", stTime);
        PrintDebugW(L"endTime", endTime);

        const auto response = cpr::Get(
                cpr::Url{"https://api.annict.com/v1/me/programs"},
                cpr::Parameters{
                        {"filter_channel_ids",   std::to_string(channelId)},
                        {"filter_started_at_gt", stTime},
                        {"filter_started_at_lt", endTime},
                        {"fields",               "work.id,work.title,work.no_episodes,episode.id,episode.title,episode.number,episode.number_text"},
                        {"sort_started_at",      "asc"},
                        {"per_page",             "1"},
                        {"access_token",         annictToken}
                }
        );

        const auto json = nlohmann::json::parse(response.text);

        auto results = std::vector<Program>();
        for (auto &item: json["programs"]) {
            const auto work = Work{
                    item["work"]["id"].get<uint32_t>(),
                    item["work"]["title"].get<std::string>(),
                    item["work"]["no_episodes"].get<bool>()
            };

            results.push_back({
                                      work,
                                      {
                                              item["episode"]["id"].get<uint32_t>(),
                                              item["episode"]["title"].is_string() ? std::optional(
                                                      item["episode"]["title"].get<std::string>()) : std::nullopt,
                                              item["episode"]["number"].is_number() ? std::optional(
                                                      item["episode"]["number"].get<float_t>()) : std::nullopt,
                                              item["episode"]["number_text"].is_string() ? std::optional(
                                                      item["episode"]["number_text"].get<std::string>()) : std::nullopt,
                                              work
                                      }
                              });
        }

        return results;
    }
}
