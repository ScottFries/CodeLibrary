from conans import ConanFile


class CppStarterProject(ConanFile):
    # Note: options are copied from CMake boolean options.
    # When turned off, CMake sometimes passes them as empty strings.
    options = {
    }
    name = "CppStarterProject"
    version = "0.1"
    requires = (
        "catch2/2.13.7",
        "docopt.cpp/0.6.3",
        "fmt/8.0.1",
        "spdlog/1.9.2",
    )
    generators = "cmake", "compiler_args", "txt", "cmake_find_package"

    def requirements(self):
        return

