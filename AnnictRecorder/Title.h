#pragma once

#include "pch.h"

#include "SyoboCalApi.h"
#include "Utils.h"

inline void HandleProgram(
    const TVTest::ProgramInfo& Program,
    const TVTest::ServiceInfo& Service,
    const Saya::ChannelType ChannelType,
    const YAML::Node& ChannelDefinition
)
{
    // しょぼいカレンダーに登録されていないチャンネルは無視
    const auto rawSyoboCalId = ChannelDefinition["syobocalId"];
    if (!rawSyoboCalId.IsDefined())
    {
        PrintDebug(L"しょぼいカレンダーに登録されていないチャンネルです。無視します。");
        return;
    }

    const auto syoboCalChId = rawSyoboCalId.as<int>();
    const auto syoboCalProgram = SyoboCal::LookupProgram(Program.StartTime, Program.Duration, syoboCalChId);
    if (!syoboCalProgram.has_value())
    {
        return;
    }

    MessageBox(nullptr, std::format(L"TID={}", syoboCalProgram.value().titleId).c_str(), L"Debug", MB_ICONINFORMATION);
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
