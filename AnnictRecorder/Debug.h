#pragma once

#include "pch.h"

#ifdef _DEBUG
template<class... Args>
void PrintDebug(const wchar_t* format, const Args&... args)
{
    std::wstring message;

    try
    {
        message = std::vformat(format, { std::make_wformat_args(args...) });
        message.append(L"\n");
    }
    catch (std::format_error& error)
    {
        wchar_t errorText[512 + 1];
        mbstowcs_s(nullptr, errorText, error.what(), 512);
        message = std::format(L"フォーマットの書式が間違っています。({})\n{}\n", format, errorText);
    }

    OutputDebugString(message.c_str());   
}

inline void PrintDebugW(const std::wstring& label, const std::string& str)
{
    // ロケールの設定
    setlocale(LC_ALL, ".utf8");

    wchar_t buf[1024];
    mbstowcs_s(nullptr, buf, str.c_str(), 1023);
    PrintDebug(L"{}: {}", label.c_str(), buf);
}

#define STOP while (true) {}
#else
#define PrintDebug __noop
#define PrintDebugW __noop
#endif
