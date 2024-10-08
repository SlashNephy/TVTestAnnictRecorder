#pragma once

#include "pch.h"

#pragma region TvtPlay
// https://github.com/xtne6f/TvtPlay/blob/work/src/_getinfo_test.cpp

constexpr auto WM_TVTP_GET_POSITION = WM_APP + 52;

static BOOL CALLBACK

FindTvtPlayFrameEnumProc(const HWND hwnd, const LPARAM lParam)
{
  TCHAR className[32];
  if (GetClassName(hwnd, className, _countof(className)) && !lstrcmp(className, L"TvtPlay Frame"))
  {
    *reinterpret_cast<HWND *>(lParam) = hwnd;
    return false;
  }

  return true;
}

static HWND FindTvtPlayFrame()
{
  HWND hwnd = nullptr;
  EnumThreadWindows(GetCurrentThreadId(), FindTvtPlayFrameEnumProc, reinterpret_cast<LPARAM>(&hwnd));

  return hwnd;
}

static int GetTvtPlayPositionSec(const HWND hwnd)
{
  return static_cast<int>(SendMessage(hwnd, WM_TVTP_GET_POSITION, 0, 0)) / 1000;
}

#pragma endregion
