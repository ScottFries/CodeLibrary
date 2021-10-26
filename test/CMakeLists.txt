find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE project_options)
target_link_libraries(catch_main PUBLIC code_library)

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
