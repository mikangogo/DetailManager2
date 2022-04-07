#pragma once


#include "Types.hpp"
#include <span>
#include <vector>


/* Converts characters encoded in UTF-16 to UTF-8.
 */
std::vector<Utf8Char> Utf16ToUtf8(const std::span<Utf16Char> from);

/* Converts characters encoded in UTF-16 to UTF-8.
 */
std::vector<Utf16Char> Utf8ToUtf16(const std::span<Utf8Char> from);

/* Opens the shared library.
 * Returns the shared library handle on success;
 * Otherwise, returns `null`.
 */
SharedLibraryInstance OpenSharedLibrary(const std::span<Utf8Char> path);

/* Closes the shared library.
 * If fails, fails silently.
 */
void CloseSharedLibrary(SharedLibraryInstance instance);

/* Gets the function address using symbol name from shared library.
 * Returns the function address;
 * Otherwise, returns `nullptr`.
 */
Address GetFunctionAddressFromSymbolName(SharedLibraryInstance instance, const std::span<AnsiChar> symbolName);
