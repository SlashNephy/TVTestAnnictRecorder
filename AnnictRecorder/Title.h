#pragma once

#include "pch.h"

#include "AnnictIds.h"
#include "SyoboCalApi.h"
#include "Utils.h"

inline void HandleProgram(
    const TVTest::ProgramInfo& Program,
    const bool IsAnime,
    const YAML::Node& ChannelDefinition
)
{
    if (!IsAnime)
    {
        PrintDebug(L"アニメジャンルではありません。スキップします。");
        return;
    }

    // しょぼいカレンダーに登録されていないチャンネルは無視
    const auto rawSyoboCalId = ChannelDefinition["syobocalId"];
    if (!rawSyoboCalId.IsDefined())
    {
        PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。スキップします。");
        return;
    }

    const auto syoboCalChId = rawSyoboCalId.as<int>();
    const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
    if (!syoboCalProgram.has_value())
    {
        return;
    }

    const auto syoboCalTid = syoboCalProgram.value().titleId;
    const auto annictId = Annict::SyoboCalTidToAnnictId(syoboCalTid);
    if (!annictId.has_value())
    {
        PrintDebug(L"Annict での作品データが見つかりませんでした。スキップします。(TID={})", syoboCalTid);
        return;
    }

    PrintDebug(L"Annict ID={}", annictId.value());
}

/*
 * この番組がアニメジャンルであるかどうか判定する
 */
inline bool IsAnimeGenre(const TVTest::EpgEventInfo& EpgEvent)
{
    if (EpgEvent.ContentList == nullptr)
    {
        return false;
    }

    bool result = false;
    for (auto i = 0; i < EpgEvent.ContentListLength; i++)
    {
        // ReSharper disable once CppTooWideScope
        const auto [ContentNibbleLevel1, ContentNibbleLevel2, _, __] = EpgEvent.ContentList[i];

        // 「アニメ」 or 「映画」→「アニメ」
        if (ContentNibbleLevel1 == 0x7 || (ContentNibbleLevel1 == 0x6 && ContentNibbleLevel2 == 0x2))
        {
            result = true;
            break;
        }
    }

    return result;
}

inline std::wstring NormalizeTitle(const std::wstring& source)
{
    auto title = std::wstring(source);
    Full2Half(title.data());

    const std::wregex sepRegex(LR"((\s+|;|・|\(|\)|～|‐|-|―|－|&|#|映画\s*|劇場版\s*|!|\?|…|『|』|「|」))");
    const std::wregex spaceRegex(LR"(\s*$)");

    const std::wsregex_token_iterator begin{title.begin(), title.end(), sepRegex, -1};
    const std::wsregex_token_iterator end;
    
    const auto result = std::find_if(begin, end, [spaceRegex](const std::wstring& str)
    {
        return !std::regex_search(str, spaceRegex);
    });
    
    if (result == end)
    {
        return std::wstring();
    }
    
    return *result;
}
