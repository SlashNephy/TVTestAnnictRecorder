#pragma once

#include "pch.h"

#include "Common.h"

namespace Annict
{
    static void PostRecord(const uint32_t episodeId, const bool shareOnTwitter, const bool shareOnFacebook, const std::string& annictToken)
    {
        cpr::Post(
            cpr::Url{"https://api.annict.com/v1/me/records"},
            cpr::Parameters{
                {"episode_id", std::to_string(episodeId)},
                {"access_token", annictToken},
                {"share_twitter", shareOnTwitter ? "true" : "false"},
                {"share_facebook", shareOnFacebook ? "true" : "false"}
            },
            cpr::UserAgent{AnnictRecorderUserAgent}
        );
    }

    static void PostMyStatus(const uint32_t workId, const std::string& kind, const std::string& annictToken)
    {
        cpr::Post(
            cpr::Url{"https://api.annict.com/v1/me/statuses"},
            cpr::Parameters{
                {"work_id", std::to_string(workId)},
                {"kind", kind},
                {"access_token", annictToken}
            },
            cpr::UserAgent{AnnictRecorderUserAgent}
        );
    }

    static std::optional<nlohmann::json> GetWorkById(const uint32_t workId, const std::string& annictToken)
    {
        const auto response = cpr::Get(
            cpr::Url{"https://api.annict.com/v1/works"},
            cpr::Parameters{
                {"filter_ids", std::to_string(workId)},
                {"fields", "title,no_episodes"},
                {"access_token", annictToken}
            }
        );

        const auto json = nlohmann::json::parse(response.text);
        if (json["total_count"].get<int>() == 0)
        {
            return std::nullopt;
        }

        return std::optional(json["works"][0]);
    }

    static std::optional<nlohmann::json> GetWorkByTitle(const std::string& title, const std::string& annictToken)
    {
        const auto response = cpr::Get(
            cpr::Url{"https://api.annict.com/v1/works"},
            cpr::Parameters{
                {"filter_title", title},
                {"fields", "id,title,no_episodes"},
                {"per_page", "50"},
                {"access_token", annictToken}
            }
        );

        const auto json = nlohmann::json::parse(response.text);
        if (json["total_count"].get<int>() == 0)
        {
            return std::nullopt;
        }

        for (auto& work : json["works"])
        {
            if (title == work["title"].get<std::string>())
            {
                return std::optional(work);
            }
        }

        return std::nullopt;
    }

    static nlohmann::json GetEpisodes(const uint32_t workId, const std::string& annictToken)
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
}
