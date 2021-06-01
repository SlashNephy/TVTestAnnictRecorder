// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。

#pragma once

// Windows ヘッダーからほとんど使用されていない部分を除外する
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// error C4996: '_Header_cstdbool': warning STL4004: <ccomplex>, <cstdalign>, <cstdbool>, and <ctgmath> are deprecated in C++17. You can define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING

#include <combaseapi.h>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <optional>
#include <regex>
#include <string>
#include <tchar.h>
#include <mutex>

#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "nlohmann/json.hpp"

#include "cpr/cpr.h"
#ifdef _DEBUG
#pragma comment(lib, "cprd.lib")
#else
#pragma comment(lib, "cpr.lib")
#endif

#include "yaml-cpp/yaml.h"
#ifdef _DEBUG
#pragma comment(lib, "yaml-cppd.lib")
#else
#pragma comment(lib, "yaml-cpp.lib")
#endif

#include "pugixml.hpp"
#ifdef _DEBUG
#pragma comment(lib, "pugixml_d.lib")
#else
#pragma comment(lib, "pugixml.lib")
#endif

// プラグインをクラスとして実装
#define TVTEST_PLUGIN_CLASS_IMPLEMENT
#include "TVTestPlugin.h"
