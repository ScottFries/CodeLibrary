#pragma once

#include "standard_rules.hpp"

#include <type_traits>

namespace frw
{
#if _MSC_VER
// region Special Member Function Rules
#pragma endregion
#endif
/**
 * Asserts that a type fullfills the Rule of 3; i.e. the type supports:
 * Copy Construction
 * Copy Assignment
 * Destruction
 * For more, see https://en.cppreference.com/w/cpp/language/rule_of_three or https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
 */
template <typename T>
constexpr bool assert_fullfills_rule_of_3()
{
    return assert_is_copy_constructible<T>() && assert_is_destructible<T>();
}

/**
 * Asserts that a type fullfills the Rule of 5; i.e. the type supports:
 * Copy Construction
 * Copy Assignment
 * Move Construction
 * Move Assignment
 * Destruction
 * For more, see https://en.cppreference.com/w/cpp/language/rule_of_three or https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
 */
template <typename T>
constexpr bool assert_fullfills_rule_of_5()
{
    return assert_is_copy_constructible<T>() && assert_is_move_constructible<T>() && assert_is_destructible<T>();
}

/**
 * Asserts that a type fullfills the Rule of 6; i.e. the type supports:
 * Default Construction
 * Copy Construction
 * Copy Assignment
 * Move Construction
 * Move Assignment
 * Destruction
 */
template <typename T>
constexpr bool assert_fullfills_rule_of_6()
{
    return assert_is_default_constructible<T>() && assert_is_copy_constructible<T>() && assert_is_move_constructible<T>() && assert_is_destructible<T>();
}
#if _MSC_VER
// region Special Member Function Rules
#pragma endregion
#endif
}  // namespace frw