#pragma once

#include "pch.h"

#include "Common.h"

namespace Saya
{
    constexpr auto DefinitionsYmlUrl = "https://raw.githubusercontent.com/SlashNephy/saya/dev/docs/definitions.yml";

    static YAML::Node LoadSayaDefinitions()
    {
        const auto response = cpr::Get(
            cpr::Url{DefinitionsYmlUrl},
            cpr::UserAgent{AnnictRecorderUserAgent}
        );

        return YAML::Load(response.text);
    }

    enum class ChannelType
    {
        GR, BS, CS, SKY
    };

    inline std::string GetNameOfSayaChannelType(const ChannelType type)
    {
        switch (type)
        {
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

    inline std::optional<ChannelType> GetSayaChannelTypeByName(const std::wstring& name)
    {
        if (name == L"GR")
        {
            return std::optional(ChannelType::GR);
        }
        if (name == L"BS")
        {
            return std::optional(ChannelType::BS);
        }
        if (name == L"CS")
        {
            return std::optional(ChannelType::CS);
        }
        if (name == L"SKY")
        {
            return std::optional(ChannelType::SKY);
        }

        return std::nullopt;
    }

    inline std::optional<ChannelType> GetSayaChannelTypeByIndex(const int index)
    {
        switch (index)
        {
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

    inline std::optional<YAML::Node> FindSayaChannel(const YAML::Node& yml, const std::optional<ChannelType> targetChannelType, const WORD targetServiceId)
    {
        const auto channels = yml["channels"];

        // ReSharper disable once CppTooWideScope
        const auto node = std::ranges::find_if(channels, [targetChannelType, targetServiceId](const YAML::Node& channel)
        {
            const auto serviceIds = channel["serviceIds"];
            // ReSharper disable once CppTooWideScope
            const auto channelType = channel["type"].as<std::string>();

            if (targetChannelType.has_value() && channelType != GetNameOfSayaChannelType(targetChannelType.value()))
            {
                return false;
            }

            for (auto it = serviceIds.begin(); it != serviceIds.end(); ++it) {
                if (targetServiceId == it->as<WORD>())
                {
                    return true;
                }
            }

            return false;
        });

        if (node != channels.end())
        {
            return std::optional(node->as<YAML::Node>());
        }

        return std::nullopt;
    }
}
