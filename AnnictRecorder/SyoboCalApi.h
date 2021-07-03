#pragma once

#include "pch.h"

#include "Common.h"
#include "Debug.h"
#include "Utils.h"

namespace SyoboCal
{
    struct LookupProgramResult
    {
        uint32_t titleId;
        float_t countStart;
        float_t countEnd;
        bool isFirstEpisode;
        bool isLastEpisode;
        std::optional<std::string> subTitle;
    };

    static std::vector<LookupProgramResult> LookupProgram(const SYSTEMTIME& start, const DWORD seconds, const int chId)
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

        PrintDebugW(L"ProgLookup", response.text);

        pugi::xml_document doc;
        if (!doc.load_string(response.text.c_str()))
        {
            return {};
        }

        const auto items = doc.select_nodes("/ProgLookupResponse/ProgItems/ProgItem");
        if (items.empty())
        {
            return {};
        }

        auto results = std::vector<LookupProgramResult>{};
        for (auto& item : items)
        {
            const auto node = item.node();
            // 削除されたエントリを無視
            if (strtol(node.child_value("Deleted"), nullptr, 10) > 0)
            {
                continue;
            }

            const auto titleId = strtol(node.child_value("TID"), nullptr, 10);

            const auto rawSTSubTitle = node.child("STSubTitle");
            const auto stSubTitle = rawSTSubTitle.empty() ? std::nullopt : std::optional(std::string(rawSTSubTitle.child_value()));

            // https://docs.cal.syoboi.jp/spec/proginfo-flag/
            const auto isFirstEpisode = (strtol(node.child_value("Flag"), nullptr, 10) & 2) > 0;
            const auto isLastEpisode = (strtol(node.child_value("Flag"), nullptr, 10) & 4) > 0;

            float_t countStart = 0;
            float_t countEnd = 0;

            // 複数話同時放送の場合 SubTitle フィールドに #[\d\.]+～#[\d\.]+ という形式で格納されている
            // マルチバイトな正規表現に難があるので wchar を経由する
            const auto subTitle = Multi2Wide(node.child_value("SubTitle"));
            const auto subTitleRegex = std::wregex(LR"(^#([\d\.]+)～#([\d\.]+)$)");
            if (std::wcmatch match; std::regex_match(subTitle.c_str(), match, subTitleRegex))
            {
                countStart = static_cast<float_t>(_wtof(match[1].str().c_str()));
                countEnd = static_cast<float_t>(_wtof(match[2].str().c_str()));
            }
            // 通常 (単話放送) 時
            else
            {
                const auto count = strtof(node.child_value("Count"), nullptr);

                countStart = count;
                countEnd = count;
            }

            PrintDebug(L"TID = {}, Count = {} ~ {}, SubTitle = {}", titleId, countStart, countEnd, stSubTitle.has_value());
            PrintDebugW(L"SubTitle", stSubTitle.value_or("n/a"));

            results.push_back({
                static_cast<uint16_t>(titleId),
                countStart,
                countEnd,
                isFirstEpisode,
                isLastEpisode,
                stSubTitle
            });
        }

        return results;
    }
}
