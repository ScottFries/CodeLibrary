#pragma once

/**
 * This file contains a set of compile-time assertions in the form of consteval functions that are used to ensure a given type adhears to the respective rules.
 *
 * The expected use is to execute the respective function immediately following the type definition, storing the result in an unused value. This will result in the static_assert triggering if the rule
 * doesn't hold, while allowing the compiler to optimize away the variable if the rule does hold.
 *
 * Example usage:
 *
 * class EmptyType {};
 * [[maybe_unused]] bool _EmptyTypeIsDefaultConstructible = assert_is_default_constructible<EmptyType>();
 */

#include <type_traits>

template<typename T> [[maybe_unused]] consteval bool assert_is_default_constructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_default_constructible_v<T>, "Type must be default constructible.");
#endif
    return std::is_default_constructible_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_trivially_constructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_trivially_constructible_v<T>, "Type must be trivially constructible.");
#endif
    return std::is_trivially_constructible_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_nothrow_default_constructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_nothrow_default_constructible_v<T>, "Type must be (nothrow) default constructible.");
#endif
    return std::is_nothrow_default_constructible_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_copyable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_copy_constructible_v<T>, "Type must be copy constructible.");
    static_assert(std::is_copy_assignable_v<T>, "Type must be copy assignable.");
#endif
    return std::is_copy_constructible_v<T> && std::is_copy_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_trivially_copyable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_trivially_copy_constructible_v<T>, "Type must be (trivially) copy constructible.");
    static_assert(std::is_trivially_copy_assignable_v<T>, "Type must be (trivially) copy assignable.");
#endif
    return std::is_trivially_copy_constructible_v<T> && std::is_trivially_copy_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_nothrow_copyable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_nothrow_copy_constructible_v<T>, "Type must be (nothrow) copy constructible.");
    static_assert(std::is_nothrow_copy_assignable_v<T>, "Type must be (nothrow) copy assignable.");
#endif
    return std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_copy_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_moveable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_move_constructible_v<T>, "Type must be moveconstructible.");
    static_assert(std::is_move_assignable_v<T>, "Type must be move assignable.");
#endif
    return std::is_move_constructible_v<T> && std::is_move_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_trivially_moveable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_trivially_move_constructible_v<T>, "Type must be (trivially) move constructible.");
    static_assert(std::is_trivially_move_assignable_v<T>, "Type must be (trivially) move assignable.");
#endif
    return std::is_trivially_move_constructible_v<T> && std::is_trivially_move_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_nothrow_moveable()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_nothrow_move_constructible_v<T>, "Type must be (nothrow) move constructible.");
    static_assert(std::is_nothrow_move_assignable_v<T>, "Type must be (nothrow) move assignable.");
#endif
    return std::is_nothrow_move_constructible_v<T> && std::is_nothrow_move_assignable_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_destructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_destructible_v<T>, "Type must be destructible.");
#endif
    return std::is_destructible_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_trivially_destructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_trivially_destructible_v<T>, "Type must be (trivially) destructible.");
#endif
    return std::is_trivially_destructible_v<T>;
}

template<typename T> [[maybe_unused]] consteval bool assert_is_nothrow_destructible()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_nothrow_destructible_v<T>, "Type must be (nothrow) destructible.");
#endif
    return std::is_nothrow_destructible_v<T>;
}

/**
 * Asserts that a type is trivial; i.e. is a scalar, or is trivially constructible.
 * For more, see https://en.cppreference.com/w/cpp/types/is_trivial
 */
template<typename T> [[maybe_unused]] consteval bool assert_is_trivial()
{
#ifndef NON_FATAL_STANDARD_RULES
    static_assert(std::is_trivial_v<T>, "Type must be a trivial type.");
#endif
    return std::is_trivial_v<T>;
}
