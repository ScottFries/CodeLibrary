#include "code_library/bitwise/parity.hpp" 

#include <catch2/catch.hpp>

TEST_CASE("Parity of integral can be determined", "[parity]")
{
    SECTION("Parity of uint32_t")
    {
        uint32_t value1 = 0b1000'1000'1000'1000'1000'1000'1000'1000;
        uint32_t value2 = 0b1000'0000'1000'1000'1000'1000'1000'1000;
        uint32_t value3 = 0b1111'1111'1111'1111'1111'1111'1111'1111;
        REQUIRE(!parity(value1));
        REQUIRE(parity(value2));
        REQUIRE(!parity(value3));
    }

    SECTION("Parity of an char8_t")
    {
        char8_t value1 = 0b1000'1000;
        char8_t value2 = 0b1000'0000;
        char8_t value3 = 0b1111'1111;
        REQUIRE(!parity(value1));
        REQUIRE(parity(value2));
        REQUIRE(!parity(value3));
    }

    SECTION("Parity of an int64_t")
    {
        int64_t value1 = 0b100'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000;
        int64_t value2 = 0b100'0000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000'1000;
        int64_t value3 = 0b111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111'1111;
        REQUIRE(!parity(value1));
        REQUIRE(parity(value2));
        REQUIRE(parity(value3));
    }
}
