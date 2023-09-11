#pragma once

#include "pch.h"

#include "Common.h"

namespace Saya {
    constexpr auto DefinitionsYmlUrl = "https://raw.githubusercontent.com/SlashNephy/saya-definitions/master/definitions.yml";

    static YAML::Node LoadSayaDefinitions() {
        const auto response = cpr::Get(
                cpr::Url{DefinitionsYmlUrl},
                cpr::UserAgent{AnnictRecorderUserAgent}
        );

        return YAML::Load(response.text);
    }

    struct Channel {
        std::optional<int> syobocalId;
        std::optional<int> annictId;
    };

    enum class ChannelType {
        GR, BS, CS, SKY
    };

    static std::string GetNameOfChannelType(const ChannelType type) {
        switch (type) {
            case ChannelType::GR:
                return "GR";
            case ChannelType::BS:
                return "BS";
            case ChannelType::CS:
                return "CS";
            case ChannelType::SKY:
                return "SKY";
        }

        throw;
    }

    static std::optional <ChannelType> GetChannelTypeByName(const std::wstring &name) {
        if (name == L"GR") {
            return std::optional(ChannelType::GR);
        }
        if (name == L"BS") {
            return std::optional(ChannelType::BS);
        }
        if (name == L"CS") {
            return std::optional(ChannelType::CS);
        }
        if (name == L"SKY") {
            return std::optional(ChannelType::SKY);
        }

        return std::nullopt;
    }

    static std::optional <ChannelType> GetChannelTypeByIndex(const int index) {
        switch (index) {
            case TVTest::TUNINGSPACE_TERRESTRIAL:
                return std::optional(ChannelType::GR);
            case TVTest::TUNINGSPACE_BS:
                return std::optional(ChannelType::BS);
            case TVTest::TUNINGSPACE_110CS:
                return std::optional(ChannelType::CS);
            default:
                return std::nullopt;
        }
    }

    static std::optional <Channel>
    FindChannel(const YAML::Node &yml, const std::optional <ChannelType> targetChannelType,
                const WORD targetServiceId) {
        const auto channels = yml["channels"];

        // ReSharper disable once CppTooWideScope
        const auto node = std::ranges::find_if(channels,
                                               [targetChannelType, targetServiceId](const YAML::Node &channel) {
                                                   const auto serviceIds = channel["serviceIds"];
                                                   // ReSharper disable once CppTooWideScope
                                                   const auto channelType = channel["type"].as<std::string>();

                                                   if (targetChannelType.has_value() &&
                                                       channelType != GetNameOfChannelType(targetChannelType.value())) {
                                                       return false;
                                                   }

                                                   for (auto it = serviceIds.begin(); it != serviceIds.end(); ++it) {
                                                       if (targetServiceId == it->as<WORD>()) {
                                                           return true;
                                                       }
                                                   }

                                                   return false;
                                               });

        if (node != channels.end()) {
            const auto item = node->as<YAML::Node>();
            const auto syobocalId = item["syobocalId"];
            const auto annictId = item["annictId"];

            return Channel{
                    syobocalId.IsDefined() ? std::optional(syobocalId.as<int>()) : std::nullopt,
                    annictId.IsDefined() ? std::optional(annictId.as<int>()) : std::nullopt
            };
        }

        return std::nullopt;
    }
}
