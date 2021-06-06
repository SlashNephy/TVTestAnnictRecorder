#pragma once

#include "pch.h"

#include "Common.h"

namespace Arm
{
    constexpr auto ArmJsonUrl = "https://raw.githubusercontent.com/kawaiioverflow/arm/master/arm.json";

    static std::map<uint32_t, uint32_t> LoadArmJson()
    {
        const auto response = cpr::Get(
            cpr::Url{ArmJsonUrl},
            cpr::UserAgent{AnnictRecorderUserAgent}
        );

        std::map<uint32_t, uint32_t> map{};
        for (auto& it : nlohmann::json::parse(response.text))
        {
            if (!it["syobocal_tid"].is_number_unsigned() || !it["annict_id"].is_number_unsigned())
            {
                continue;
            }

            const auto syobocalTid = it["syobocal_tid"].get<uint32_t>();
            const auto annictId = it["annict_id"].get<uint32_t>();
            map[syobocalTid] = annictId;
        }

        return map;
    }
}
