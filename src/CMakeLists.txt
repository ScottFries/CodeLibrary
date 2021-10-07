
find_package(fmt)
find_package(spdlog)
find_package(docopt)

file(GLOB_RECURSE HEADER_LIST CONFIGURE_DEPENDS "${CodeLibrary_SOURCE_DIR}/include/code_library/*.hpp")

add_library(code_library temp.cpp ${HEADER_LIST})

target_include_directories(code_library PUBLIC ../include)

target_link_libraries(
  code_library
  PRIVATE project_options
          project_warnings
          docopt::docopt
          fmt::fmt
          spdlog::spdlog)

source_group(TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})