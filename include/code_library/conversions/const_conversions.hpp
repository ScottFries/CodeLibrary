#pragma once

template <class T>
struct const_reference
{
    using type = const std::remove_reference_t<T>&;
};

template <class T>
using const_reference_t = typename const_reference<T>::type;

template <class T>
struct add_const_to_value
{
    using type = std::conditional_t<std::is_lvalue_reference_v<T>, const_reference_t<T>, const T>;
};

template <class T>
using add_const_to_value_t = typename add_const_to_value<T>::type;
