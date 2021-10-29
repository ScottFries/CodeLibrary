find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE project_options)
target_link_libraries(catch_main PUBLIC code_library)

add_executable(insertion_sort_tests "algorithm/sorting/insertion_sort_tests.cpp")
target_link_libraries(insertion_sort_tests PRIVATE project_options project_warnings catch_main)
catch_discover_tests(
    insertion_sort_tests
    TEST_PREFIX
    "insertion_sort."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "insertion_sort."
    OUTPUT_SUFFIX
    .xml
)

add_executable(standard_rules_tests "assertions/standard_rules_tests.cpp")
target_link_libraries(standard_rules_tests PRIVATE project_options project_warnings catch_main)
catch_discover_tests(
    standard_rules_tests
    TEST_PREFIX
    "standard_rules."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "standard_rules."
    OUTPUT_SUFFIX
    .xml
)

add_executable(parity_tests "bitwise/parity_tests.cpp")
target_link_libraries(parity_tests PRIVATE project_options project_warnings catch_main)
catch_discover_tests(
    parity_tests
    TEST_PREFIX
    "parity."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "parity."
    OUTPUT_SUFFIX
    .xml
)

add_executable(has_function_tests "conditions/has_function_tests.cpp")
target_link_libraries(has_function_tests PRIVATE project_options project_warnings catch_main)
catch_discover_tests(
    has_function_tests
    TEST_PREFIX
    "has_function."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "has_function."
    OUTPUT_SUFFIX
    .xml
)

add_executable(underlying_type_tests "conversions/underlying_type_tests.cpp")
target_link_libraries(underlying_type_tests PRIVATE project_options project_warnings catch_main)
catch_discover_tests(
    underlying_type_tests
    TEST_PREFIX
    "underlying_type."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "underlying_type."
    OUTPUT_SUFFIX
    .xml
)
