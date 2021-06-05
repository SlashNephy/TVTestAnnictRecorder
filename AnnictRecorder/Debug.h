#pragma once

#include "pch.h"

#ifdef _DEBUG
template<typename... Variable>
void PrintDebug(const wchar_t* format, const Variable&... variables)
{
    std::wstring message;

    try {
        auto fmt = std::wstring(format);
        fmt.append(L"\n");

        message = std::format(fmt, variables...);
    } catch (std::format_error& error)
    {
        wchar_t errorText[512 + 1];
        mbstowcs_s(nullptr, errorText, error.what(), 512);
        message = std::format(L"フォーマットの書式が間違っています。({})\n{}\n", format, errorText);
    }

    OutputDebugString(message.c_str());   
}

#define STOP while (true) {}
#else
#define PrintDebug __noop
#endif
