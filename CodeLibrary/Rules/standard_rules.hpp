#pragma once

#include <type_traits>

namespace frw
{
#if _MSC_VER
#pragma region Basic Special Member Function Asserts
#endif
template <typename T>
constexpr bool assert_is_default_constructible()
{
    static_assert(std::is_default_constructible_v<T>, typeid(T).name() + ": must be default constructible.");
    return std::is_default_constructible_v<T>;
}

template <typename T>
constexpr bool assert_is_nothrow_default_constructible()
{
    static_assert(std::is_nothrow_default_constructible_v<T>,
                  typeid(T).name() + ": must be (nothrow) default constructible.");
    return std::is_nothrow_default_constructible_v<T>;
}

template <typename T>
constexpr bool assert_is_trivially_constructible()
{
    static_assert(std::is_trivially_constructible_v<T>, typeid(T).name() + ": must be trivially constructible.");
    return std::is_trivially_constructible_v<T>;
}

template <typename T>
constexpr bool assert_is_copyable()
{
    static_assert(std::is_copy_constructible_v<T>, typeid(T).name() + ": must be copy constructible.");
    static_assert(std::is_copy_assignable_v<T>, typeid(T).name() + ": must be copy assignable.");
    return std::is_copy_constructible_v<T> && std::is_copy_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_trivially_copyable()
{
    static_assert(std::is_trivially_copy_constructible_v<T>,
                  typeid(T).name() + ": must be (trivially) copy constructible.");
    static_assert(std::is_trivially_copy_assignable_v<T>, typeid(T).name() + ": must be (trivially) copy assignable.");
    return std::is_trivially_copy_constructible_v<T> && std::is_trivially_copy_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_nothrow_copyable()
{
    static_assert(std::is_nothrow_copy_constructible_v<T>,
                  typeid(T).name() + ": must be (nothrow) copy constructible.");
    static_assert(std::is_nothrow_copy_assignable_v<T>, typeid(T).name() + ": must be (nothrow) copy assignable.");
    return std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_copy_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_moveable()
{
    static_assert(std::is_move_constructible_v<T>, typeid(T).name() + ": must be moveconstructible.");
    static_assert(std::is_move_assignable_v<T>, typeid(T).name() + ": must be move assignable.");
    return std::is_move_constructible_v<T> && std::is_move_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_trivially_moveable()
{
    static_assert(std::is_trivially_move_constructible_v<T>,
                  typeid(T).name() + ": must be (trivially) move constructible.");
    static_assert(std::is_trivially_move_assignable_v<T>, typeid(T).name() + ": must be (trivially) move assignable.");
    return std::is_trivially_move_constructible_v<T> && std::is_trivially_move_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_nothrow_moveable()
{
    static_assert(std::is_nothrow_move_constructible_v<T>,
                  typeid(T).name() + ": must be (nothrow) move constructible.");
    static_assert(std::is_nothrow_move_assignable_v<T>, typeid(T).name() + ": must be (nothrow) move assignable.");
    return std::is_nothrow_move_constructible_v<T> && std::is_nothrow_move_assignable_v<T>;
}

template <typename T>
constexpr bool assert_is_destructible()
{
    static_assert(std::is_destructible_v<T>, typeid(T).name() + ": must be destructible.");
    return std::is_destructible_v<T>;
}

template <typename T>
constexpr bool assert_is_trivially_destructible()
{
    static_assert(std::is_trivially_destructible_v<T>, typeid(T).name() + ": must be (trivially) destructible.");
    return std::is_trivially_destructible_v<T>;
}

template <typename T>
constexpr bool assert_is_nothrow_destructible()
{
    static_assert(std::is_nothrow_destructible_v<T>, typeid(T).name() + ": must be (nothrow) destructible.");
    return std::is_nothrow_destructible_v<T>;
}

#if _MSC_VER
// region Basic Asserts
#pragma endregion
#endif

/**
 * Asserts that a type is trivial; i.e. is a scalar, or is trivially constructible.
 * For more, see https://en.cppreference.com/w/cpp/types/is_trivial
 */
template <typename T>
constexpr bool assert_is_trivial()
{
    static_assert(std::is_trivial_v<T>, typename(T).name() + ": must be a trivial type.");
    return std::is_trivial_v<T>;
}
}  // namespace frw