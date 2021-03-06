#pragma once

#ifdef __GNUG__
#include <cxxabi.h>
#endif  // __GNUG__
#include <memory>
#include <string>

namespace frw
{
std::string demangle(const char* name)
{
#ifdef __GNUG__
    // Clang/GNU; demangle with C++ ABI
    int status = -4;
    std::unique_ptr<char, void (*)(void*)> res{abi::__cxa_demangle(name, nullptr, nullptr, &status), std::free};
    return (status == 0) ? res.get() : name;
#endif  // __GNUG__

    // As a default: return the name passed
    return std::string(name);
}
}  // namespace frw