#pragma once

/**
 * The parity of a binary word is 1 if the number of 1s in the word is odd; othersie it is 0.
 * A common use case for parity checking is error detection, especially when transmitting data.
 * https://en.wikipedia.org/wiki/Parity_bit
 */

#include <climits> // CHAR_BIT
#include <type_traits>

/**
 * Determines the parity of a given binary integer value.
 * Returns true if Parity is 1, or false if Parity is 0.
 *
 * Parity is determined by repeatedly performing an XOR operation on the upper half of the binary
 * value against the lower half until we're left with a single bit that represents the parity.
 *
 * Note that the runtime speed of this can be improved (up to ~1.5x) by specializing the function
 * on input type and unwinding the loop.
 */
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
bool parity(T value)
{
    short bits = CHAR_BIT * sizeof(T);
    while ((bits /= 2) >= 1)
    {
        value ^= value >> bits;
    }
    return value & 0b1;
}
