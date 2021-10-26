#pragma once

#include <utility> // std::swap

template <typename Container>
constexpr void insertion_sort(Container& c)
{
    auto sorted_iter = c.begin();
    auto unsorted_iter = c.begin();
    ++unsorted_iter;
    
    while (unsorted_iter != c.end())
    {
        /** Can only do this if iterator is reversable
        auto sorting_iter = unsorted_iter;
        while (*sorting_iter < *sorted_iter)
        {
            std::swap(*sorting_iter--, *sorted_iter);
        }
        */
        if (*unsorted_iter < *sorted_iter)
        {
            auto sorting_iter = c.begin();
            while (*sorting_iter < *unsorted_iter)
            {
                ++sorting_iter;
            }
            while (sorting_iter != unsorted_iter)
            {
                std::swap(*sorting_iter++, *unsorted_iter);
            }
        }
        ++sorted_iter;
        ++unsorted_iter;
    }
}
