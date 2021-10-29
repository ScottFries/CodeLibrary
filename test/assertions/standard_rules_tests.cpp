#define NON_FATAL_STANDARD_RULES
#include "code_library/assertions/standard_rules.hpp"

#include <catch2/catch.hpp>

#include <memory>

class EmptyType {};

class UnconstructibleType
{
    UnconstructibleType() = delete;
    UnconstructibleType(const UnconstructibleType&) = delete;
};

class EmptyTypeWithExplicitConstructor
{
public:
    EmptyTypeWithExplicitConstructor() {}
};

class EmptyTypeWithExplicitNoexceptConstructor
{
public:
    EmptyTypeWithExplicitNoexceptConstructor() noexcept {}
};

class CopyOnlyType
{
public:
    CopyOnlyType(const CopyOnlyType&) noexcept = default;
    CopyOnlyType& operator=(const CopyOnlyType&) noexcept = default;
    CopyOnlyType(CopyOnlyType&&) noexcept = delete;
    CopyOnlyType& operator=(CopyOnlyType&&) noexcept = delete;
};

class MoveOnlyType
{
public:
    MoveOnlyType(const MoveOnlyType&) noexcept = delete;
    MoveOnlyType& operator=(const MoveOnlyType&) noexcept = delete;
    MoveOnlyType(MoveOnlyType&&) noexcept = default;
    MoveOnlyType& operator=(MoveOnlyType&&) noexcept = default;
};

class UniquePtrType
{
private:
    std::unique_ptr<int> value_;
};

TEST_CASE("Standard Rules can be enforced", "[standard_rules]")
{
    SECTION("Types can be enforced to be constructible")
    {
        CHECK(assert_is_default_constructible<EmptyType>());
        CHECK(assert_is_trivially_constructible<EmptyType>());
        CHECK(assert_is_nothrow_default_constructible<EmptyType>());

        CHECK(!assert_is_default_constructible<UnconstructibleType>());
        CHECK(!assert_is_trivially_constructible<UnconstructibleType>());
        CHECK(!assert_is_nothrow_default_constructible<UnconstructibleType>());
        
        CHECK(assert_is_default_constructible<EmptyTypeWithExplicitConstructor>());
        CHECK(!assert_is_trivially_constructible<EmptyTypeWithExplicitConstructor>());
        CHECK(!assert_is_nothrow_default_constructible<EmptyTypeWithExplicitConstructor>());
        
        CHECK(assert_is_default_constructible<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(!assert_is_trivially_constructible<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_nothrow_default_constructible<EmptyTypeWithExplicitNoexceptConstructor>());
        
        CHECK(!assert_is_default_constructible<CopyOnlyType>());
        CHECK(!assert_is_trivially_constructible<CopyOnlyType>());
        CHECK(!assert_is_nothrow_default_constructible<CopyOnlyType>());
        
        CHECK(!assert_is_default_constructible<MoveOnlyType>());
        CHECK(!assert_is_trivially_constructible<MoveOnlyType>());
        CHECK(!assert_is_nothrow_default_constructible<MoveOnlyType>());
        
        CHECK(assert_is_default_constructible<UniquePtrType>());
        CHECK(!assert_is_trivially_constructible<UniquePtrType>());
        CHECK(assert_is_nothrow_default_constructible<UniquePtrType>());
    }

    SECTION("Types can be enforced to be copyable", "[standard_rules]")
    {
        CHECK(assert_is_copyable<EmptyType>());
        CHECK(assert_is_trivially_copyable<EmptyType>());
        CHECK(assert_is_nothrow_copyable<EmptyType>());

        CHECK(!assert_is_copyable<UnconstructibleType>());
        CHECK(!assert_is_trivially_copyable<UnconstructibleType>());
        CHECK(!assert_is_nothrow_copyable<UnconstructibleType>());
        
        CHECK(assert_is_copyable<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_trivially_copyable<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_nothrow_copyable<EmptyTypeWithExplicitConstructor>());
        
        CHECK(assert_is_copyable<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_trivially_copyable<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_nothrow_copyable<EmptyTypeWithExplicitNoexceptConstructor>());
        
        CHECK(assert_is_copyable<CopyOnlyType>());
        CHECK(assert_is_trivially_copyable<CopyOnlyType>());
        CHECK(assert_is_nothrow_copyable<CopyOnlyType>());
        
        CHECK(!assert_is_copyable<MoveOnlyType>());
        CHECK(!assert_is_trivially_copyable<MoveOnlyType>());
        CHECK(!assert_is_nothrow_copyable<MoveOnlyType>());
        
        CHECK(!assert_is_copyable<UniquePtrType>());
        CHECK(!assert_is_trivially_copyable<UniquePtrType>());
        CHECK(!assert_is_nothrow_copyable<UniquePtrType>());
    }

    SECTION("Types can be enforced to be moveable", "[standard_rules]")
    {
        CHECK(assert_is_moveable<EmptyType>());
        CHECK(assert_is_trivially_moveable<EmptyType>());
        CHECK(assert_is_nothrow_moveable<EmptyType>());

        CHECK(!assert_is_moveable<UnconstructibleType>());
        CHECK(!assert_is_trivially_moveable<UnconstructibleType>());
        CHECK(!assert_is_nothrow_moveable<UnconstructibleType>());
        
        CHECK(assert_is_moveable<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_trivially_moveable<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_nothrow_moveable<EmptyTypeWithExplicitConstructor>());
        
        CHECK(assert_is_moveable<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_trivially_moveable<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_nothrow_moveable<EmptyTypeWithExplicitNoexceptConstructor>());
        
        CHECK(!assert_is_moveable<CopyOnlyType>());
        CHECK(!assert_is_trivially_moveable<CopyOnlyType>());
        CHECK(!assert_is_nothrow_moveable<CopyOnlyType>());
        
        CHECK(assert_is_moveable<MoveOnlyType>());
        CHECK(assert_is_trivially_moveable<MoveOnlyType>());
        CHECK(assert_is_nothrow_moveable<MoveOnlyType>());
        
        CHECK(assert_is_moveable<UniquePtrType>());
        CHECK(!assert_is_trivially_moveable<UniquePtrType>());
        CHECK(assert_is_nothrow_moveable<UniquePtrType>());
    }

    SECTION("Types can be enforced to be destructible", "[standard_rules]")
    {
        CHECK(assert_is_destructible<EmptyType>());
        CHECK(assert_is_trivially_destructible<EmptyType>());
        CHECK(assert_is_nothrow_destructible<EmptyType>());

        CHECK(assert_is_destructible<UnconstructibleType>());
        CHECK(assert_is_trivially_destructible<UnconstructibleType>());
        CHECK(assert_is_nothrow_destructible<UnconstructibleType>());
        
        CHECK(assert_is_destructible<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_trivially_destructible<EmptyTypeWithExplicitConstructor>());
        CHECK(assert_is_nothrow_destructible<EmptyTypeWithExplicitConstructor>());
        
        CHECK(assert_is_destructible<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_trivially_destructible<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(assert_is_nothrow_destructible<EmptyTypeWithExplicitNoexceptConstructor>());
        
        CHECK(assert_is_destructible<CopyOnlyType>());
        CHECK(assert_is_trivially_destructible<CopyOnlyType>());
        CHECK(assert_is_nothrow_destructible<CopyOnlyType>());
        
        CHECK(assert_is_destructible<MoveOnlyType>());
        CHECK(assert_is_trivially_destructible<MoveOnlyType>());
        CHECK(assert_is_nothrow_destructible<MoveOnlyType>());
        
        CHECK(assert_is_destructible<UniquePtrType>());
        CHECK(!assert_is_trivially_destructible<UniquePtrType>());
        CHECK(assert_is_nothrow_destructible<UniquePtrType>());
    }

    SECTION("Types can be enforced to be trivial", "[standard_rules]")
    {
        CHECK(assert_is_trivial<EmptyType>());
        CHECK(assert_is_trivial<UnconstructibleType>());
        CHECK(!assert_is_trivial<EmptyTypeWithExplicitConstructor>());
        CHECK(!assert_is_trivial<EmptyTypeWithExplicitNoexceptConstructor>());
        CHECK(!assert_is_trivial<CopyOnlyType>());
        CHECK(!assert_is_trivial<MoveOnlyType>());
        CHECK(!assert_is_trivial<UniquePtrType>());
    }
}