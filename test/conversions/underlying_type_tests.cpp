#include "code_library/conversions/underlying_type.hpp"

#include <catch2/catch.hpp>

enum class Month : std::uint8_t
{
    JANUARY = 0,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

enum class ByteSize : std::uint64_t
{
    BIT = 0x1,
    NIBBLE = 0x2,
    BYTE = 0x4,
    KILOBYTE = 0x400,
    MEGABYTE = 0x100000,
    GIGABYTE = 0x40000000,
    TERABYTE = 0x10000000000,
    PETABYTE = 0x4000000000000,
    EXABYTE = 0x1000000000000000
};

TEST_CASE("Enums can be converted to their underlying types", "[underlying_type")
{
    SECTION("converting a std::uint8_t backed enum yields std::uint8_t values")
    {
        auto test_value = [](Month m, std::uint8_t val) {
            auto m_val = to_underlying_type(m);
            REQUIRE(typeid(m_val) == typeid(std::uint8_t));
            REQUIRE(m_val == val);
        };

        test_value(Month::JANUARY, 0);
        test_value(Month::FEBRUARY, 1);
        test_value(Month::MARCH, 2);
        test_value(Month::APRIL, 3);
        test_value(Month::MAY, 4);
        test_value(Month::JUNE, 5);
        test_value(Month::JULY, 6);
        test_value(Month::AUGUST, 7);
        test_value(Month::SEPTEMBER, 8);
        test_value(Month::OCTOBER, 9);
        test_value(Month::NOVEMBER, 10);
        test_value(Month::DECEMBER, 11);
    }

    SECTION("converting a std::uint64_t backed enum yields std::uint64_t values")
    {
        auto test_value = [](ByteSize m, std::uint64_t val) {
            auto m_val = to_underlying_type(m);
            REQUIRE(typeid(m_val) == typeid(std::uint64_t));
            REQUIRE(m_val == val);
        };

        test_value(ByteSize::BIT, 1L);
        test_value(ByteSize::NIBBLE, 2L);
        test_value(ByteSize::BYTE, 4L);
        test_value(ByteSize::KILOBYTE, 1024L);
        test_value(ByteSize::MEGABYTE, 1048576L);
        test_value(ByteSize::GIGABYTE, 1073741824L);
        test_value(ByteSize::TERABYTE, 1099511627776L);
        test_value(ByteSize::PETABYTE, 1125899906842624L);
        test_value(ByteSize::EXABYTE, 1152921504606846976L);
    }
}
