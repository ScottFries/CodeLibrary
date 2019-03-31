#pragma once

#include <deque>
#include <string>
#include <vector>

namespace frw
{
/**
 *  Erases a given value from an std::vector.
 */
template <typename T>
void erase(std::vector<T>& container, const T& value)
{
    container.erase(std::remove(container.begin(), container.end(), value), container.end());
}

/**
 *  Erases a given value from an std::vector.
 */
template <typename T>
void erase(std::vector<T>& container, const T& value)
{
    container.erase(std::remove(container.begin(), container.end(), value), container.end());
}

/**
 *  Erases a given value from an std::vector.
 */
template <typename T>
void erase(std::vector<T>& container, const T& value)
{
    container.erase(std::remove(container.begin(), container.end(), value), container.end());
}
}  // namespace frw