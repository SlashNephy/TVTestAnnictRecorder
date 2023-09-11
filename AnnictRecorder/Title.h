#pragma once

#include "pch.h"

namespace Title {
    struct AtxTitleResult {
        bool found = false;
        std::wstring title{};
        float_t countStart{};
        float_t countEnd{};
    };

    static AtxTitleResult ExtractAtxTitle(const std::wstring &eventName) {
        const auto multipleEpisodeRegex = std::wregex(LR"(^(?:\[無\])?(.+)\s#([\d\.]+)[-・]#([\d\.]+).*$)");
        if (std::wsmatch match; std::regex_match(eventName, match, multipleEpisodeRegex)) {
            return {
                    true,
                    match[1].str(),
                    static_cast<float_t>(_wtof(match[2].str().c_str())),
                    static_cast<float_t>(_wtof(match[3].str().c_str()))
            };
        }

        const auto singleEpisodeRegex = std::wregex(LR"(^(?:\[無\])?(.+)\s#([\d\.]+).*$)");
        if (std::wsmatch match; std::regex_match(eventName, match, singleEpisodeRegex)) {
            const auto start = static_cast<float_t>(_wtof(match[2].str().c_str()));

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
