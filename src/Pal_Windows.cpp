#include "Pal.hpp"

std::vector<Utf8Char> Utf16ToUtf8(const std::span<Utf16Char> from)
{
    auto lengthFrom = static_cast<int>(from.size());
    auto bytesTo = WideCharToMultiByte(CP_UTF8, 0, from.data(), lengthFrom, nullptr, 0, nullptr, nullptr);
    auto to = std::vector<Utf8Char>(bytesTo + 1);

    WideCharToMultiByte(CP_UTF8, 0, from.data(), lengthFrom, reinterpret_cast<char*>(to.data()), bytesTo, nullptr, nullptr);

    return to;
}


std::vector<Utf16Char> Utf8ToUtf16(const std::span<Utf8Char> from)
{
    auto bytesFrom = static_cast<int>(from.size_bytes());
    auto lengthTo = MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(from.data()), bytesFrom, nullptr, 0);
    auto to = std::vector<Utf16Char>(lengthTo + 1);

    MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(from.data()), bytesFrom, to.data(), lengthTo);

    return to;
}

SharedLibraryInstance OpenSharedLibrary(const std::span<Utf8Char> path)
{
    const auto wcsPath = Utf8ToUtf16(path);
    auto moduleInstance = LoadLibraryW(wcsPath.data());

    return moduleInstance;
}

void CloseSharedLibrary(SharedLibraryInstance instance)
{
    FreeLibrary(instance);
}

Address GetFunctionAddressFromSymbolName(SharedLibraryInstance instance, const std::span<AnsiChar> symbolName)
{
    return GetProcAddress(instance, symbolName.data());
}
