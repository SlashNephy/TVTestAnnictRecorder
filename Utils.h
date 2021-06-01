#pragma once

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
 * 全角 → 半角に変換する
 * http://yamatyuu.net/computer/program/zen2han/index.html
 */
inline void Full2Half(wchar_t* source)
{
    for (auto* p = source; *p; p++)
    {
        // 全角数字英字記号
        if (0xff01 <= *p && *p <= 0xff5d)
        {
            *p -= 0xff00 - 0x20;
        }
        // 全角スペース
        // C4066: characters beyond first in wide-character constant ignored
        else if (*p == L'　')
        {
            *p = L' ';
        }
    }
}
