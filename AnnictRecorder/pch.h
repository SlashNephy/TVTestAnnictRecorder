// pch.h: プリコンパイル済みヘッダー ファイルです。
// 次のファイルは、その後のビルドのビルド パフォーマンスを向上させるため 1 回だけコンパイルされます。
// コード補完や多くのコード参照機能などの IntelliSense パフォーマンスにも影響します。
// ただし、ここに一覧表示されているファイルは、ビルド間でいずれかが更新されると、すべてが再コンパイルされます。
// 頻繁に更新するファイルをここに追加しないでください。追加すると、パフォーマンス上の利点がなくなります。

#pragma once

// Windows ヘッダーからほとんど使用されていない部分を除外する
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <combaseapi.h>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <iostream>
#include <mutex>
#include <optional>
#include <regex>
#include <shellapi.h>
#include <string>
#include <tchar.h>
#include <thread>

#include <Shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

#include "cpr/cpr.h"

#pragma comment(lib, "cpr.lib")

#include "yaml-cpp/yaml.h"

#ifdef _DEBUG
#pragma comment(lib, "yaml-cppd.lib")
#else
#pragma comment(lib, "yaml-cpp.lib")
#endif

#include "nlohmann/json.hpp"

#include "pugixml.hpp"

#pragma comment(lib, "pugixml.lib")

#include "lodepng.h"

#pragma comment(lib, "lodepng.lib")

// プラグインをクラスとして実装
#define TVTEST_PLUGIN_CLASS_IMPLEMENT

#include "TVTestPlugin.h"
