#pragma once

#include "pch.h"

#include "Common.h"

namespace Saya
{
  constexpr auto DefinitionsYmlUrl = "https://raw.githubusercontent.com/SlashNephy/saya-definitions/master/definitions.yml";

  static YAML::Node LoadSayaDefinitions()
  {
    const auto response = cpr::Get(
        cpr::Url{DefinitionsYmlUrl},
        cpr::UserAgent{AnnictRecorderUserAgent});

    return YAML::Load(response.text);
  }

  struct Channel
  {
    std::optional<int> syobocalId;
    std::optional<int> annictId;
  };

  static std::optional<Channel> FindChannel(const YAML::Node &yml, const WORD targetServiceId)
  {
    const auto channels = yml["channels"];

    const auto node = std::ranges::find_if(
        channels,
        [targetServiceId](const YAML::Node &channel)
        {
          // 本来であればネットワークIDもチェックすべきだが省略している
          // 環境によってはネットワークIDを取得できないことがある
          const auto serviceIds = channel["serviceIds"];
          for (auto it = serviceIds.begin(); it != serviceIds.end(); ++it)
          {
            if (targetServiceId == it->as<WORD>())
            {
              return true;
            }
          }

          return false;
        });

    if (node != channels.end())
    {
      const auto item = node->as<YAML::Node>();
      const auto syobocalId = item["syobocalId"];
      const auto annictId = item["annictId"];

      return Channel{
          syobocalId.IsDefined() ? std::optional(syobocalId.as<int>()) : std::nullopt,
          annictId.IsDefined() ? std::optional(annictId.as<int>()) : std::nullopt,
      };
    }

    return std::nullopt;
  }
}
