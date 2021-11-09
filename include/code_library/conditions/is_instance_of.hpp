#pragma once

#include <type_traits>

/*
 * is_instance_of
 * Utility for determining if a type is an instance of another type.
 */
template <template <typename...> typename Template, typename Type>
struct is_instance_of : std::false_type
{
};

template <template <typename...> typename Template, typename... Args>
struct is_instance_of<Template, Template<Args...>> : std::true_type
{
};

template <template <typename...> typename Template, typename Type>
constexpr bool is_instance_of_v = is_instance_of<Template, Type>::value;
