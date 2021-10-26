#include "code_library/conditions/has_function.hpp"

#include <string>

#include <catch2/catch.hpp>

class Type1
{
public:
    void foo();
    void bar();
    void foobar();
};

class Type2
{
public:
    int foo(bool b) const;
    int bar(bool b) const;
    int foobar(bool b) const;
};

class Type3
{
public:
    const std::string& foo(int i, bool b, char* c) const volatile;
    const std::string& bar(int i, bool b, char* c) const volatile;
    const std::string& foobar(int i, bool b, char* c) const volatile;
};

MAKE_HAS_FUNC(foo, void, ,)
MAKE_HAS_FUNC(bar, int, const, bool)
MAKE_HAS_FUNC(foobar, const std::string&, const volatile, int, bool, char*)

TEST_CASE("Functions can be tested for", "[has_function]")
{
    SECTION("Basic functions can be tested for")
    {
        CHECK(has_foo_v<Type1>);
        CHECK(!has_foo_v<Type2>);
        CHECK(!has_foo_v<Type3>);
    }

    SECTION("Functions with a single argument and qualifier can be tested for")
    {
        CHECK(!has_bar_v<Type1>);
        CHECK(has_bar_v<Type2>);
        CHECK(!has_bar_v<Type3>);
    }

    SECTION("Functions with multiple arguments and qualifiers can be tested for")
    {
        CHECK(!has_foobar_v<Type1>);
        CHECK(!has_foobar_v<Type2>);
        CHECK(has_foobar_v<Type3>);
    }
}
