#pragma once

#include "pch.h"

#include "Common.h"
#include "Debug.h"
#include "Utils.h"

namespace SyoboCal
{
    struct LookupProgramResult
    {
        uint16_t titleId;
        float_t count;
        std::optional<std::string> subTitle;
    };

    inline std::optional<LookupProgramResult> LookupProgram(const SYSTEMTIME& start, const DWORD seconds, const int chId)
    {
        const auto stTime = std::format("{:04d}{:02d}{:02d}_{:02d}{:02d}{:02d}-", start.wYear, start.wMonth, start.wDay, start.wHour, start.wMinute, start.wSecond);
        const auto endTimestamp = SystemTime2Timet(start) + seconds;
        tm end{};
        localtime_s(&end, &endTimestamp);
        const auto range = std::format("{}{:04d}{:02d}{:02d}_{:02d}{:02d}{:02d}", stTime, end.tm_year + 1900, end.tm_mon + 1, end.tm_mday, end.tm_hour, end.tm_min, end.tm_sec);

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
        const auto titleId = strtol(node.child_value("TID"), nullptr, 10);
        const auto count = strtod(node.child_value("Count"), nullptr);
        const auto rawSubTitle = node.child("STSubTitle");
        const auto subTitle = rawSubTitle.empty() ? std::nullopt : std::optional(rawSubTitle.value());

        PrintDebug(L"TID = {}, Count = {}", titleId, count);

        return std::optional(
            LookupProgramResult{
                static_cast<uint16_t>(titleId),
                static_cast<float_t>(std::round(count * 10) / 10),
                subTitle
            }
        );
    }
}
