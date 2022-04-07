#pragma once

#include <cstddef>
#include <windows.h>

typedef void* Address;
typedef HMODULE SharedLibraryInstance;

typedef char AnsiChar;
typedef char8_t Utf8Char;
typedef wchar_t Utf16Char;
typedef std::size_t SizeType;
