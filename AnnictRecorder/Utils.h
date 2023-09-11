#pragma once

#include "pch.h"

/*
 * SYSTEMTIME 構造体を time_t に変換する
 */
static time_t SystemTime2Timet(const SYSTEMTIME &st) {
    struct tm gm = {
            st.wSecond, st.wMinute, st.wHour, st.wDay, st.wMonth - 1, st.wYear - 1900, st.wDayOfWeek, 0, 0
    };

    return mktime(&gm);
}

/*
 * この番組がアニメジャンルであるかどうか判定する
 */
static bool IsAnimeGenre(const TVTest::EpgEventInfo &EpgEvent) {
    if (EpgEvent.ContentList == nullptr) {
        return false;
    }

    bool result = false;
    for (auto i = 0; i < EpgEvent.ContentListLength; i++) {
        // ReSharper disable once CppTooWideScope
        const auto [ContentNibbleLevel1, ContentNibbleLevel2, _, __] = EpgEvent.ContentList[i];

        // 「アニメ」 or 「映画」→「アニメ」
        if (ContentNibbleLevel1 == 0x7 || (ContentNibbleLevel1 == 0x6 && ContentNibbleLevel2 == 0x2)) {
            result = true;
            break;
        }
    }

    return result;
}

/*
 * この番組が第1話であるかどうか判定する
 */
static bool IsFirstEpisode(const TVTest::ProgramInfo &Program) {
    return std::wstring(Program.pszEventName).find(L"[新]") != std::string::npos;
}

/*
 * この番組が最終話であるかどうか判定する
 */
static bool IsLastEpisode(const TVTest::ProgramInfo &Program) {
    return std::wstring(Program.pszEventName).find(L"[終]") != std::string::npos;
}

static std::string Wide2Multi(const std::wstring source) {
    // ロケールの設定
    setlocale(LC_ALL, ".utf8");

    char buf[256];
    wcstombs_s(nullptr, buf, source.c_str(), 255);

    return buf;
}

static std::wstring Multi2Wide(const std::string source) {
    // ロケールの設定
    setlocale(LC_ALL, ".utf8");

    wchar_t buf[256];
    mbstowcs_s(nullptr, buf, source.c_str(), 255);

    return buf;
}

template<typename T>
std::vector <T> flatten(const std::vector <std::vector<T>> &v) {
    const auto totalSize = std::reduce(v.begin(), v.end(), static_cast<size_t>(0),
                                       [](const size_t acc, const std::vector <T> &vector) {
                                           return acc + vector.size();
                                       });

    std::vector <T> result;
    result.reserve(totalSize);
    for (const auto &sub: v) {
        result.insert(result.end(), sub.begin(), sub.end());
    }

    return result;
}

#pragma region NicoJK
// https://github.com/xtne6f/NicoJK/blob/83e7212b8cf4dfd50ac38d71ff1bb2b57c997318/Util.cpp#L45

// 必要なバッファを確保してGetPrivateProfileSection()を呼ぶ
static std::vector<wchar_t> GetPrivateProfileSectionBuffer(const LPCTSTR lpAppName, const LPCTSTR lpFileName) {
    std::vector<wchar_t> buf(4096);

    for (;;) {
        if (const size_t len = GetPrivateProfileSection(lpAppName, buf.data(), static_cast<DWORD>(buf.size()),
                                                        lpFileName); len < buf.size() - 2) {
            buf.resize(len + 1);
            break;
        }

        buf.resize(buf.size() * 2);
    }

    return buf;
}

// GetPrivateProfileSection()で取得したバッファから、キーに対応する文字列を取得する
static void GetBufferedProfileString(LPCTSTR lpBuff, const LPCTSTR lpKeyName, const LPCTSTR lpDefault,
                                     const LPTSTR lpReturnedString, const DWORD nSize) {
    const size_t nKeyLen = wcslen(lpKeyName);

    while (*lpBuff) {
        const size_t nLen = wcslen(lpBuff);

        if (!_wcsnicmp(lpBuff, lpKeyName, nKeyLen) && lpBuff[nKeyLen] == L'=') {
            if ((lpBuff[nKeyLen + 1] == L'\'' || lpBuff[nKeyLen + 1] == L'"') && nLen >= nKeyLen + 3 &&
                lpBuff[nKeyLen + 1] == lpBuff[nLen - 1]) {
                wcsncpy_s(lpReturnedString, nSize, lpBuff + nKeyLen + 2,
                          min(nLen - nKeyLen - 3, static_cast<size_t>(nSize - 1)));
            } else {
                wcsncpy_s(lpReturnedString, nSize, lpBuff + nKeyLen + 1, _TRUNCATE);
            }

            return;
        }

        lpBuff += nLen + 1;
    }

    wcsncpy_s(lpReturnedString, nSize, lpDefault, _TRUNCATE);
}

// GetPrivateProfileSection()で取得したバッファから、キーに対応する文字列を std::wstring で取得する
static std::wstring GetBufferedProfileToString(LPCTSTR lpBuff, const LPCTSTR lpKeyName, const LPCTSTR lpDefault) {
    const size_t nKeyLen = wcslen(lpKeyName);

    while (*lpBuff) {
        const size_t nLen = wcslen(lpBuff);

        if (!_wcsnicmp(lpBuff, lpKeyName, nKeyLen) && lpBuff[nKeyLen] == L'=') {
            if ((lpBuff[nKeyLen + 1] == L'\'' || lpBuff[nKeyLen + 1] == L'"') && nLen >= nKeyLen + 3 &&
                lpBuff[nKeyLen + 1] == lpBuff[nLen - 1]) {
                return std::wstring(lpBuff + nKeyLen + 2, nLen - nKeyLen - 3);
            }

            return std::wstring(lpBuff + nKeyLen + 1, nLen - nKeyLen - 1);
        }

        lpBuff += nLen + 1;
    }

    return lpDefault;
}

// GetPrivateProfileSection()で取得したバッファから、キーに対応する数値を取得する
static int GetBufferedProfileInt(const LPCTSTR lpBuff, const LPCTSTR lpKeyName, int nDefault) {
    wchar_t sz[16];
    GetBufferedProfileString(lpBuff, lpKeyName, L"", sz, _countof(sz));
    wchar_t *endPtr;
    int nRet = wcstol(sz, &endPtr, 10);

    return endPtr == sz ? nDefault : nRet;
}

static void
WritePrivateProfileInt(const LPCWSTR lpAppName, const LPCTSTR lpKeyName, const int value, const LPCTSTR lpFileName) {
    wchar_t sz[16];
    swprintf_s(sz, L"%d", value);
    WritePrivateProfileString(lpAppName, lpKeyName, sz, lpFileName);
}

#pragma region endregion
