#pragma once

#include "pch.h"

#ifdef _DEBUG
template<typename... Variable>
void PrintDebug(const std::wstring format, const Variable&... variables)
{
    std::wstring message;

    try {
        auto fmt = std::wstring(format);
        fmt.append(L"\n");

        message = std::format(fmt, variables...);
    } catch (std::format_error& error)
    {
        wchar_t errorText[512];
        mbstowcs_s(nullptr, errorText, error.what(), 512);
        message = std::format(L"フォーマットの書式が間違っています。({})\n{}\n", format, errorText);
    }

    std::wcout << message;
    OutputDebugString(message.c_str());
}

inline void CreateConsole()
{
    if (AttachConsole(-1) || AllocConsole())
    {
        FILE* fp = nullptr;

        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONOUT$", "w", stderr);
        freopen_s(&fp, "CONIN$", "r", stdin);

        const auto hConOut = CreateFile(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        const auto hConIn = CreateFile(L"CONIN$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
        SetStdHandle(STD_ERROR_HANDLE, hConOut);
        SetStdHandle(STD_INPUT_HANDLE, hConIn);

        PrintDebug(L"デバッグコンソールを初期化しました。");
    }
}

inline void DestroyConsole()
{
    FreeConsole();

    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();
    std::wcout.clear();
    std::wclog.clear();
    std::wcerr.clear();
    std::wcin.clear();
}

#define STOP while (true) {}
#else
#define PrintDebug __noop
#endif
