﻿#pragma once

#include "pch.h"

/*
 * SYSTEMTIME 構造体を time_t に変換する
 */
inline time_t SystemTime2Timet(const SYSTEMTIME& st)
{
    struct tm gm = {
        st.wSecond, st.wMinute, st.wHour, st.wDay, st.wMonth - 1, st.wYear - 1900, st.wDayOfWeek, 0, 0
    };

    return mktime(&gm);
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

inline std::string Wide2Multi(const std::wstring source)
{
    // ロケールの設定
    setlocale(LC_ALL, ".utf8");

    char buf[256];
    wcstombs_s(nullptr, buf, source.c_str(), 255);

    return buf;
}

inline std::wstring Multi2Wide(const std::string source)
{
    // ロケールの設定
    setlocale(LC_ALL, ".utf8");

    wchar_t buf[256];
    mbstowcs_s(nullptr, buf, source.c_str(), 255);

    return buf;
}
