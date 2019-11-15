#pragma once

#include <optional>

namespace frw
{
template <typename T, typename E = T, typename Function, typename Derivative>
T newtons_method(Function function, Derivative derivative, T initial_guess, std::size_t iterations = 10,
                 std::optional<E> acceptable_error = {})
{
    T result = initial_guess;

    auto threshold_met = [function, acceptable_error](T value) {
        if (!acceptable_error) return false;
        return function(value) < *acceptable_error;
    };
    for (std::size_t i = 0; i < iterations && !threshold_met(result); ++i)
    {
        result -= function(result) / derivative(result);
    }
    return result;
}
}  // namespace frw