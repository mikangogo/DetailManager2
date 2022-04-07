#define BOOST_TEST_MAIN

#include "boost/test/included/unit_test.hpp"

#include "Pal.hpp"
#include <string>

BOOST_AUTO_TEST_SUITE(Utf16ToUtf8_Test)

BOOST_AUTO_TEST_CASE(Japanese_Equal)
{
    auto c16 = L"あいう";
    auto c8 = u8"あいう";

    auto s16 = std::wstring{ c16 };
    
    auto actual = std::u8string{ Utf16ToUtf8(s16).data()};
    auto expected = std::u8string{ c8 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(Japanese_NotEqual)
{
    auto c16 = L"ういあ";
    auto c8 = u8"あいう";

    auto s16 = std::wstring{ c16 };

    auto actual = std::u8string{ Utf16ToUtf8(s16).data() };
    auto expected = std::u8string{ c8 };

    BOOST_CHECK(actual != expected);
}

BOOST_AUTO_TEST_CASE(Emoji_Equal)
{
    auto c16 = L"😒😘👌";
    auto c8 = u8"😒😘👌";

    auto s16 = std::wstring{ c16 };

    auto actual = std::u8string{ Utf16ToUtf8(s16).data() };
    auto expected = std::u8string{ c8 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(SurrogatePair_Equal)
{
    auto c16 = L"😒𠦝😘a👌";
    auto c8 = u8"😒𠦝😘a👌";

    auto s16 = std::wstring{ c16 };

    auto actual = std::u8string{ Utf16ToUtf8(s16).data() };
    auto expected = std::u8string{ c8 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(PathLike_Equal)
{
    auto c16 = L"ab:\\cde\\";
    auto c8 = u8"ab:\\cde\\";

    auto s16 = std::wstring{ c16 };

    auto actual = std::u8string{ Utf16ToUtf8(s16).data() };
    auto expected = std::u8string{ c8 };

    BOOST_CHECK(actual == expected);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Utf8ToUtf16_Test)

BOOST_AUTO_TEST_CASE(Japanese_Equal)
{
    auto c16 = L"あいう";
    auto c8 = u8"あいう";

    auto s8 = std::u8string{ c8 };

    auto actual = std::wstring{ Utf8ToUtf16(s8).data() };
    auto expected = std::wstring{ c16 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(Japanese_NotEqual)
{
    auto c16 = L"ういあ";
    auto c8 = u8"あいう";

    auto s8 = std::u8string{ c8 };

    auto actual = std::wstring{ Utf8ToUtf16(s8).data() };
    auto expected = std::wstring{ c16 };

    BOOST_CHECK(actual != expected);
}

BOOST_AUTO_TEST_CASE(Emoji_Equal)
{
    auto c16 = L"😒😘👌";
    auto c8 = u8"😒😘👌";

    auto s8 = std::u8string{ c8 };

    auto actual = std::wstring{ Utf8ToUtf16(s8).data() };
    auto expected = std::wstring{ c16 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(SurrogatePair_Equal)
{
    auto c16 = L"😒𠦝😘a👌";
    auto c8 = u8"😒𠦝😘a👌";

    auto s8 = std::u8string{ c8 };

    auto actual = std::wstring{ Utf8ToUtf16(s8).data() };
    auto expected = std::wstring{ c16 };

    BOOST_CHECK(actual == expected);
}

BOOST_AUTO_TEST_CASE(PathLike_Equal)
{
    auto c16 = L"ab:\\cde\\";
    auto c8 = u8"ab:\\cde\\";

    auto s8 = std::u8string{ c8 };

    auto actual = std::wstring{ Utf8ToUtf16(s8).data() };
    auto expected = std::wstring{ c16 };

    BOOST_CHECK(actual == expected);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(OpenSharedLibrary_Test)

BOOST_AUTO_TEST_CASE(OpenSharedLibrary_Success)
{
    auto s8 = std::u8string{ u8"Kernel32.dll" };
    auto vs8 = std::vector<Utf8Char>{ s8.begin(), s8.end() };

    auto actual = OpenSharedLibrary(vs8);

    BOOST_CHECK(actual != nullptr);


    auto s = std::string{ "Beep" };
    auto addr = GetFunctionAddressFromSymbolName(actual, s);

    BOOST_CHECK(addr != nullptr);


    s = std::string{ "BeeBo" };
    addr = GetFunctionAddressFromSymbolName(actual, s);

    BOOST_CHECK(addr == nullptr);


    CloseSharedLibrary(actual);
}

BOOST_AUTO_TEST_SUITE_END()
