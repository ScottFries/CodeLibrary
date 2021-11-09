#pragma once

#include <type_traits>

// Wrappers around type_traits: https://en.cppreference.com/w/cpp/header/type_traits
/// Primary Type Categories
template <typename T>
using is_void = std::enable_if_t<std::is_void_v<T>>;

template <typename T>
using is_nullptr = std::enable_if_t<std::is_null_pointer_v<T>>;

template <typename T>
using is_integral = std::enable_if_t<std::is_integral_v<T>>;

template <typename T>
using is_floating_point = std::enable_if_t<std::is_floating_point_v<T>>;

template <typename T>
using is_array = std::enable_if_t<std::is_array_v<T>>;

template <typename T>
using is_enum = std::enable_if_t<std::is_enum_v<T>>;

template <typename T>
using is_union = std::enable_if_t<std::is_union_v<T>>;

template <typename T>
using is_class = std::enable_if_t<std::is_class_v<T>>;

template <typename T>
using is_function = std::enable_if_t<std::is_function_v<T>>;

template <typename T>
using is_pointer = std::enable_if_t<std::is_pointer_v<T>>;

template <typename T>
using is_l_reference = std::enable_if_t<std::is_lvalue_reference_v<T>>;

template <typename T>
using is_r_reference = std::enable_if_t<std::is_rvalue_reference_v<T>>;

template <typename T>
using is_member_object_pointer = std::enable_if_t<std::is_member_object_pointer_v<T>>;

template <typename T>
using is_member_function_pointer = std::enable_if_t<std::is_member_function_pointer_v<T>>;

/// Composite Type Categories
template <typename T>
using is_fundamental = std::enable_if_t<std::is_fundamental_v<T>>;

template <typename T>
using is_arithmetic = std::enable_if_t<std::is_arithmetic_v<T>>;

template <typename T>
using is_scalar = std::enable_if_t<std::is_scalar_v<T>>;

template <typename T>
using is_object = std::enable_if_t<std::is_object_v<T>>;

template <typename T>
using is_compound = std::enable_if_t<std::is_compound_v<T>>;

template <typename T>
using is_reference = std::enable_if_t<std::is_reference_v<T>>;

template <typename T>
using is_member_pointer = std::enable_if_t<std::is_member_pointer_v<T>>;

/// Type Properties
template <typename T>
using is_const = std::enable_if_t<std::is_const_v<T>>;

template <typename T>
using is_volatile = std::enable_if_t<std::is_volatile_v<T>>;

template <typename T>
using is_trivial = std::enable_if_t<std::is_trivial_v<T>>;

template <typename T>
using is_trivially_copyable = std::enable_if_t<std::is_trivially_copyable_v<T>>;

template <typename T>
using is_standard_layout = std::enable_if_t<std::is_standard_layout_v<T>>;

template <typename T>
using is_pod = std::enable_if_t<std::is_pod_v<T>>;

template <typename T>
using is_literal_type = std::enable_if_t<std::is_literal_type_v<T>>;

template <typename T>
using has_unique_object_representations = std::enable_if_t<std::has_unique_object_representations_v<T>>;

template <typename T>
using is_empty = std::enable_if_t<std::is_empty_v<T>>;

template <typename T>
using is_polymorphic = std::enable_if_t<std::is_polymorphic_v<T>>;

template <typename T>
using is_abstract = std::enable_if_t<std::is_abstract_v<T>>;

template <typename T>
using is_final = std::enable_if_t<std::is_final_v<T>>;

template <typename T>
using is_aggregate = std::enable_if_t<std::is_aggregate_v<T>>;

template <typename T>
using is_signed = std::enable_if_t<std::is_signed_v<T>>;

template <typename T>
using is_unsigned = std::enable_if_t<std::is_unsigned_v<T>>;

/// Supported Operations
template <typename T>
using is_constructible = std::enable_if_t<std::is_constructible_v<T>>;

template <typename T>
using is_trivially_constructible = std::enable_if_t<std::is_trivially_constructible_v<T>>;

template <typename T>
using is_nothrow_constructible = std::enable_if_t<std::is_nothrow_constructible_v<T>>;

template <typename T>
using is_default_constructible = std::enable_if_t<std::is_default_constructible_v<T>>;

template <typename T>
using is_trivially_default_constructible = std::enable_if_t<std::is_trivially_default_constructible_v<T>>;

template <typename T>
using is_nothrow_default_constructible = std::enable_if_t<std::is_nothrow_default_constructible_v<T>>;

template <typename T>
using is_copy_constructible = std::enable_if_t<std::is_copy_constructible_v<T>>;

template <typename T>
using is_trivially_copy_constructible = std::enable_if_t<std::is_trivially_copy_constructible_v<T>>;

template <typename T>
using is_nothrow_copy_constructible = std::enable_if_t<std::is_nothrow_copy_constructible_v<T>>;

template <typename T>
using is_move_constructible = std::enable_if_t<std::is_move_constructible_v<T>>;

template <typename T>
using is_trivially_move_constructible = std::enable_if_t<std::is_trivially_move_constructible_v<T>>;

template <typename T>
using is_nothrow_move_constructible = std::enable_if_t<std::is_nothrow_move_constructible_v<T>>;

template <typename T>
using is_assignable = std::enable_if_t<std::is_assignable_v<T>>;

template <typename T>
using is_trivially_assignable = std::enable_if_t<std::is_trivially_assignable_v<T>>;

template <typename T>
using is_nothrow_assignable = std::enable_if_t<std::is_nothrow_assignable_v<T>>;

template <typename T>
using is_copy_assignable = std::enable_if_t<std::is_copy_assignable_v<T>>;

template <typename T>
using is_trivially_copy_assignable = std::enable_if_t<std::is_trivially_copy_assignable_v<T>>;

template <typename T>
using is_nothrow_copy_assignable = std::enable_if_t<std::is_nothrow_copy_assignable_v<T>>;

template <typename T>
using is_move_assignable = std::enable_if_t<std::is_move_assignable_v<T>>;

template <typename T>
using is_trivially_move_assignable = std::enable_if_t<std::is_trivially_move_assignable_v<T>>;

template <typename T>
using is_nothrow_move_assignable = std::enable_if_t<std::is_nothrow_move_assignable_v<T>>;

template <typename T>
using is_destructible = std::enable_if_t<std::is_destructible_v<T>>;

template <typename T>
using is_trivially_destructible = std::enable_if_t<std::is_trivially_destructible_v<T>>;

template <typename T>
using is_nothrow_destructible = std::enable_if_t<std::is_nothrow_destructible_v<T>>;

template <typename T>
using has_Virtual_destructor = std::enable_if_t<std::has_virtual_destructor_v<T>>;

template <typename T, typename U>
using is_swappable_with = std::enable_if_t<std::is_swappable_with_v<T, U>>;

template <typename T>
using is_swappable = std::enable_if_t<std::is_swappable_v<T>>;

template <typename T, typename U>
using is_nothrow_swappable_with = std::enable_if_t<std::is_nothrow_swappable_with_v<T, U>>;

template <typename T>
using is_nothrow_swappable = std::enable_if_t<std::is_nothrow_swappable_v<T>>;

/// Type Relationships
template <typename T, typename U>
using is_same = std::enable_if_t<std::is_same_v<T, U>>;

template <typename Base, typename Derived>
using is_base_of = std::enable_if_t<std::is_base_of_v<Base, Derived>>;

template <typename From, typename To>
using is_convertible = std::enable_if_t<std::is_convertible_v<From, To>>;

template <typename From, typename To>
using is_nothrow_convertible = std::enable_if_t<std::is_nothrow_convertible_v<From, To>>;

template <typename Fn, typename... ArgTypes>
using is_invocable = std::enable_if_t<std::is_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using is_invocable_r = std::enable_if_t<std::is_invocable_r_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using is_nothrow_invocable = std::enable_if_t<std::is_nothrow_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using is_nothrow_invocable_r = std::enable_if_t<std::is_nothrow_invocable_r_v<Fn, ArgTypes...>>;
