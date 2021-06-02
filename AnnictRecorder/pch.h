// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。

#pragma once

// Windows ヘッダーからほとんど使用されていない部分を除外する
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma comment(lib, "User32.Lib")

#include <combaseapi.h>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <iostream>
#include <optional>
#include <regex>
#include <string>
#include <tchar.h>
#include <mutex>

#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "cpr/cpr.h"
#pragma comment(lib, "cpr.lib")
#ifdef _DEBUG
#pragma comment(lib, "libcurl-d.lib")
#pragma comment(lib, "zlibd.lib")
#else
#pragma comment(lib, "libcurl.lib")
#pragma comment(lib, "zlib.lib")
#endif
#pragma comment(lib, "Ws2_32.Lib")
#pragma comment(lib, "Wldap32.Lib")
#pragma comment(lib, "Crypt32.Lib")
#pragma comment(lib, "AdvAPI32.Lib")

#include "yaml-cpp/yaml.h"
#ifdef _DEBUG
#pragma comment(lib, "libyaml-cppmdd.lib")
#else
#pragma comment(lib, "libyaml-cppmd.lib")
#endif

#include "nlohmann/json.hpp"

#include "pugixml.hpp"
#ifdef _DEBUG
#pragma comment(lib, "pugixml_d.lib")
#else
#pragma comment(lib, "pugixml.lib")
#endif

// プラグインをクラスとして実装
#define TVTEST_PLUGIN_CLASS_IMPLEMENT
#include "TVTestPlugin.h"
