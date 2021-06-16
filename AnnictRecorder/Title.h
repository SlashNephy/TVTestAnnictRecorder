#pragma once

#include "pch.h"

namespace Title
{
    struct AtxTitleResult
    {
        bool found = false;
        std::wstring title{};
        int countStart{};
        int countEnd{};
    };

    static AtxTitleResult ExtractAtxTitle(const std::wstring& eventName)
    {
        const auto multipleEpisodeRegex = std::wregex(LR"(^(.+)\s#(\d+)[-・]#(\d+).*$)");
        if (std::wsmatch match; std::regex_match(eventName, match, multipleEpisodeRegex))
        {
            return {
                true,
                match[1].str(),
                _wtoi(match[2].str().c_str()),
                _wtoi(match[3].str().c_str())
            };
        }

        const auto singleEpisodeRegex = std::wregex(LR"(^(.+)\s#(\d+).*$)");
        if (std::wsmatch match; std::regex_match(eventName, match, singleEpisodeRegex))
        {
            const auto start = _wtoi(match[2].str().c_str());

            return {
                true,
                match[1].str(),
                start,
                start
            };
        }

        return {};
    }
}
