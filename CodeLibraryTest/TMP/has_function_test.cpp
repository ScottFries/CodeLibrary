#include "TMP/Conditions/has_function.hpp"

#include <string>

#include <gtest/gtest.h>

MAKE_HAS_FUNC(foo, void, )

MAKE_HAS_FUNC(bar, int, const, bool)

MAKE_HAS_FUNC(foobar, const std::string&, const volatile, int, bool, char*)

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

TEST(HasFunctionTest, SimpleFUnction)
{
    EXPECT_TRUE(frw::has_foo_v<Type1>);
    EXPECT_FALSE(frw::has_foo_v<Type2>);
    EXPECT_FALSE(frw::has_foo_v<Type3>);
}

TEST(HasFunctionTest, FunctionWithSingleReturnArgAndQualifier)
{
    EXPECT_FALSE(frw::has_bar_v<Type1>);
    EXPECT_TRUE(frw::has_bar_v<Type2>);
    EXPECT_FALSE(frw::has_bar_v<Type3>);
}

TEST(HasFunctionTest, FunctionWithReturnMultipleArgsAndMultipleQualifiers)
{
    EXPECT_FALSE(frw::has_foobar_v<Type1>);
    EXPECT_FALSE(frw::has_foobar_v<Type2>);
    EXPECT_TRUE(frw::has_foobar_v<Type3>);
}
