#pragma once

/**
 * @brief Determines what the highest bit set on a value is.
 * 
 * @param value     Value to determine MSB of.
 * @return Index of the MSB.
 */
template <typename T>
constexpr T most_significant_bit(T value)
{
    T result = 0;
    for (T val = value; val > 0; val >>= 1, ++result);
    return result;
}
