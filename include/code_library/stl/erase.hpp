#pragma once

#include <vector>

/**
 *  Erases a given value from an std::vector.
 */
template <typename T>
void erase(std::vector<T>& container, const T& value)
{
    container.erase(std::remove(container.begin(), container.end(), value), container.end());
}
