#include "code_library/algorithm/sorting/insertion_sort.hpp" 

#include "sorting_test_values.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Collections can be sorted", "[insertion_sort]")
{
    SECTION("sorting an std::array<int32_t>")
    {
        auto collection = INT32_ARRAY;
        insertion_sort(collection);
        REQUIRE(INT32_ARRAY_SORTED == collection);
    }

    SECTION("sorting an std::list<char>")
    {
        auto collection = CHAR_LIST;
        insertion_sort(collection);
        REQUIRE(CHAR_LIST_SORTED == collection);
    }

    SECTION("sorting an std::vector<double>")
    {
        auto collection = DOUBLE_VECTOR;
        insertion_sort(collection);
        REQUIRE(DOUBLE_VECTOR_SORTED == collection);
    }
}