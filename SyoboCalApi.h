#pragma once

#include "pch.h"

#include "Common.h"
#include "Utils.h"

namespace SyoboCal
{
    struct LookupProgramResult
    {
        uint32_t programId;
        uint16_t titleId;
        uint16_t count;
        std::optional<std::string> subTitle;
    };

    inline std::optional<LookupProgramResult> LookupProgram(const SYSTEMTIME& start, const DWORD seconds, const int chId)
    {
        const auto stTime = std::format("{04d}{02d}{02d}_{02d}{02d}{02d}-", start.wYear, start.wMonth, start.wDay, start.wHour, start.wMinute, start.wSecond);
        const auto endTimestamp = SystemTime2Timet(start) + seconds;
        tm end{};
        localtime_s(&end, &endTimestamp);
        const auto range = std::format("{}-{04d}{02d}{02d}_{02d}{02d}{02d}", stTime, end.tm_year, end.tm_mon, end.tm_mday, end.tm_hour, end.tm_min, end.tm_sec);

        const auto response = cpr::Get(
            cpr::Url{"https://cal.syoboi.jp/db.php"},
            cpr::Parameters{
                {"Command", "ProgLookup"},
                {"ChID", std::to_string(chId)},
                {"StTime", stTime},
                {"Range", range},
                {"JOIN", "SubTitles"}
            },
            cpr::UserAgent{AnnictRecorderUserAgent}
        );

        pugi::xml_document doc;
        if (!doc.load_string(response.text.c_str()))
        {
            return std::nullopt;
        }

        const auto items = doc.select_nodes("/ProgLookupResponse/ProgItems/ProgItem");
        if (items.empty())
        {
            return std::nullopt;
        }

        const auto node = items.first().node();
        const auto programId = node.attribute("PID").as_uint();
        const auto titleId = node.attribute("TID").as_uint();
        const auto count = node.attribute("Count").as_uint();
        const auto rawSubTitle = node.attribute("STSubTitle");
        const auto subTitle = rawSubTitle.empty() ? std::nullopt : std::optional(rawSubTitle.as_string());

        return std::optional(
            LookupProgramResult{
                programId, static_cast<uint16_t>(titleId), static_cast<uint16_t>(count), subTitle
            }
        );
    }
}
