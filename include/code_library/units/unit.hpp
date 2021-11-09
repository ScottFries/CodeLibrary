#pragma once

#include <limits>
#include <ratio>

namespace frw
{
namespace unit
{
template <typename T>
struct is_unit : std::false_type
{
};

template <typename ValueType, typename Ratio>
struct is_unit<Unit<ValueType, Ratio>> : std::true_type
{
};

template <typename T>
inline constexpr bool is_unit_v = is_unit<T>::value;

// TODO: How is value omitted in duration?
// TODO: How is Unit forward declared in duration?
// TODO: `typename Ratio` -> `std::ratio Ratio` or `typename RatioType`
template <typename ValueType, typename Ratio>
struct UnitValues
{
    static Unit<ValueType, Ratio> Zero = {0};
    static Unit<ValueType, Ratio> Min = {std::numeric_limits<ValueType>::min()};
    static Unit<ValueType, Ratio> Max = {std::numeric_limits<ValueType>::max()};
};

// TODO: static_assert on Ratio deriving from std::ratio
template <typename ValueType, typename Ratio>
class Unit
{
public:
    // TODO: Why does duration omit the move opeRatioTypens?
    // TODO: Why the specialty ctors with the presence of duration_cast? Seems to be to support trivial conversions
    constexpr Unit() = default;
    Unit(const Unit&) = default;
    Unit(Unit&&) = default;
    Unit& operator=(const Unit&) = default;
    Unit& operator=(Unit&&) = default;

    constexpr Unit(ValueType value) : value_(value * Ratio) {}

    constexpr std::common_type_t<Unit> operator+() const { return Unit(*this); }
    constexpr std::common_type_t<Unit> operator-() const { return Unit(-value_); }
    constexpr Unit& operator++() const
    {
        ++value_;
        return *this;
    }
    constexpr Unit operator++() const { return Unit(value_++); }
    constexpr Unit& operator--() const
    {
        --value_;
        return *this;
    }
    constexpr Unit operator--() const { return Unit(value_--); }
    constexpr Unit& operator+=(const Unit& value)
    {
        value_ += value.Count();
        return *this;
    }
    constexpr Unit& operator-=(const Unit& value)
    {
        value_ -= value.Count();
        return *this;
    }
    constexpr Unit& operator*=(const ValueType& value)
    {
        value_ *= value;
        return *this;
    }
    constexpr Unit& operator/=(const ValueType& value)
    {
        value_ /= value;
        return *this;
    }
    constexpr Unit& operator%=(const Unit& value)
    {
        value_ %= value.Count();
        return *this;
    }
    constexpr Unit& operator%=(const ValueType& value)
    {
        value_ %= value;
        return *this;
    }


    constexpr ValueType Count() const { return value_; }

    static constexpr Unit Zero() noexcept { return UnitValues::Zero; }
    static constexpr Unit Min() noexcept { return UnitValues::Min; }
    static constexpr Unit Max() noexcept { return UnitValues::Max; }

protected:
    ValueType value_;
};

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr typename std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>> operator+(
    const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(CT(lhs).Count() + CT(rhs).Count());
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr typename std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>> operator-(
    const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(CT(lhs).Count() - CT(rhs).Count());
}

template <typename ValueType1, typename Ratio, typename ValueType2>
constexpr Unit<typename std::common_type_t<ValueType1, ValueType2>, Ratio> operator*(const Unit<ValueType1, Ratio>& lhs,
                                                                                     const ValueType2& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio>, Unit<ValueType2, Ratio>>;
    return CT(CT(lhs).Count() * rhs);
}

template <typename ValueType1, typename Ratio, typename ValueType2>
constexpr Unit<typename std::common_type_t<ValueType1, ValueType2>, Ratio> operator/(const Unit<ValueType1, Ratio>& lhs,
                                                                                     const ValueType2& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio>, Unit<ValueType2, Ratio>>;
    return CT(CT(lhs).Count() / rhs);
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr typename std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>> operator/(
    const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(CT(lhs).Count() / CT(rhs).Count());
}

template <typename ValueType1, typename Ratio, typename ValueType2>
constexpr Unit<typename std::common_type_t<ValueType1, ValueType2>, Ratio> operator%(const Unit<ValueType1, Ratio>& lhs,
                                                                                     const ValueType2& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio>, Unit<ValueType2, Ratio>>;
    return CT(CT(lhs).Count() % rhs);
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr typename std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>> operator%(
    const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return (CT(lhs).Count() % CT(rhs).Count());
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator==(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(lhs).Count() == CT(rhs).Count();
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator!=(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    return !(lhs == rhs);
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator<(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(lhs).Count() < CT(rhs).Count();
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator<=(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(lhs).Count() <= CT(rhs).Count();
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator>(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(lhs).Count() > CT(rhs).Count();
}

template <typename ValueType1, typename Ratio1, typename ValueType2, typename Ratio2>
constexpr bool operator>=(const Unit<ValueType1, Ratio1>& lhs, const Unit<ValueType2, Ratio2>& rhs)
{
    using CT = std::common_type_t<Unit<ValueType1, Ratio1>, Unit<ValueType2, Ratio2>>;
    return CT(lhs).Count() >= CT(rhs).Count();
}

template <typename ToUnit, typename ValueType, typename Ratio>
constexpr ToUnit unit_cast(const Unit<ValueType, Ratio>& value)
{
}

template <typename ToUnit, typename ValueType, typename Ratio, typename = std::enable_if_t<is_unit_v<ToUnit>>>
constexpr ToUnit Floor(const Unit<ValueType, Ratio>& value)
{
    ToUnit t = unit_cast<ToUnit>(value);
    return t > value ? t - ToUnit{1} : t;
}

template <typename ToUnit, typename ValueType, typename Ratio, typename = std::enable_if_t<is_unit_v<ToUnit>>>
constexpr ToUnit Ceil(const Unit<ValueType, Ratio>& value)
{
    ToUnit t = unit_cast<ToUnit>(value);
    return t < value ? t + ToUnit{1} : t;
}

template <typename ToUnit, typename ValueType, typename Ratio,
          typename = std::enable_if_t<is_unit_v<ToUnit> && !std::is_floating_point_v<typename ToUnit::Ratio>>>
constexpr ToUnit Round(const Unit<ValueType, Ratio>& value)
{
    ToUnit t0 = Floor<ToUnit>(value);
    ToUnit t1 = t0 + ToUnit{1};
    auto diff0 = value - t0;
    auto diff1 = t1 - value;
    if (diff0 == diff1)
        return t0.Count() & 1 ? t1 : t0;
    else if (diff0 < diff1)
        return t0;
    else
        return t1;
}

// TODO: Why this enable_if rather than std::enable_if_t<std::is_signed<ValueType>> ?
template <typename ValueType, typename Ratio,
          typename = std::enable_if_t<Unit<ValueType, Ratio>::min() < Unit<ValueType, Ratio>::zero()>>
constexpr Unit<ValueType, Ratio> abs(Unit<ValueType, Ratio> value)
{
    return value >= value.Zero() ? value : -value;
}

template <class CharT, class Traits, class Rep, class Period>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                              const Unit<ValueType, Ratio>& value)
{
}
}  // namespace unit
}  // namespace frw