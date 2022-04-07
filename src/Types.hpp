#pragma once

#if defined(_MSC_VER)

#include "Types_Windows.hpp"

#else

#include <cstddef>

typedef void* Address;
typedef Address SharedLibraryInstance;
typedef char AnsiChar;
typedef char Utf8Char;
typedef char32_t Utf16Char;
typedef std::size_t SizeType;

#endif
