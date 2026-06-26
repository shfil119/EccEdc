#pragma once

// SDKDDKVer.h をインクルードすると、利用できる最も上位の Windows プラットフォームが定義されます。

// 以前の Windows プラットフォーム用にアプリケーションをビルドする場合は、WinSDKVer.h をインクルードし、
// SDKDDKVer.h をインクルードする前に、サポート対象とするプラットフォームを示すように _WIN32_WINNT マクロを設定します。

#ifdef _MSC_VER
// If compiling with Microsoft Visual Studio, use the official SDK header
#include <SDKDDKVer.h>
#else
// Alternative for MinGW / GCC / Clang on Linux:
// Define target Windows version manually (0x0A00 targets Windows 10 and Windows 11)
#ifndef WINVER
#define WINVER 0x0A00
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#endif
