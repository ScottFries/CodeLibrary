#pragma once

#include "has_function.hpp"
#include "type_trait_conditions.hpp"

#include <type_traits>

// First impressions: this would be a pain in the ass, if even possible;
// contracts are definitely a lot better.

// trait constructor
// trait copy constructor
// trait assignable
// trait destructible
MAKE_HAS_FUNC(begin, iterator, )
MAKE_HAS_FUNC(begin, const iterator, const)
MAKE_HAS_FUNC(end, iterator, )
MAKE_HAS_FUNC(end, const iterator, const)
MAKE_HAS_FUNC(cbegin, const_iterator, const)
MAKE_HAS_FUNC(cend, const_iterator, const)
MAKE_HAS_FUNC(operator==, bool, const)
MAKE_HAS_FUNC(operator!=, bool, const)
// trait MAKE_HAS_FUNC(swap, void, , T&)
MAKE_HAS_FUNC(size, size_type, const)
MAKE_HAS_FUNC(max_size, size_typpe, const)
MAKE_HAS_FUNC(empty, bool, )

template <typename T>
struct is_container
{


    /* SFINAE catch */
    template <typename A>
    static std::false_type is_container_type()
    {
        return std::false_type();
    }

    using type = decltype(is_container_type<T>());
    static constexpr bool value = type::value;
};

template <typename T>
static constexpr bool is_container_v = is_container<T>::value;
