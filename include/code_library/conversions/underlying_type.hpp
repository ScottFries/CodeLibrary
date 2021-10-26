#pragma once

#include <type_traits>

/**
 * Converts an enum value to its underlying type.
 *
 * Example:
 * enum class Month : std::uint32_t { Jan = 0, Feb, Mar };
 * Month m = Month::Feb;
 * std::uint32_t m_val = to_underlying_type(m);
 *
 * For more details, see Item 10 (page 73) of Scott Meyer's "Modern Effective C++".
 */
template<typename EnumType, typename _ = typename std::enable_if_t<std::is_enum_v<EnumType>>, typename UnderlyingType = typename std::underlying_type_t<EnumType>>
constexpr auto to_underlying_type(EnumType value) noexcept
{
    return static_cast<UnderlyingType>(value);
}
