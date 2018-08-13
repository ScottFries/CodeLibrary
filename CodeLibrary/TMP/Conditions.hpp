#pragma once

#include <type_traits>

// Wrappers around type_traits: https://en.cppreference.com/w/cpp/header/type_traits
/// Primary Type Categories
template <typename T>
using IsVoid = std::enable_if_t<std::is_void_v<T>>;

template <typename T>
using IsNotVoid = std::enable_if_t<!std::is_void_v<T>>;

template <typename T>
using IsNullptr = std::enable_if_t<std::is_null_pointer_v<T>>;

template <typename T>
using IsNotNullptr = std::enable_if_t<!std::is_null_pointer_v<T>>;

template <typename T>
using IsIntegral = std::enable_if_t<std::is_integral_v<T>>;

template <typename T>
using IsNotIntegral = std::enable_if_t<!std::is_integral_v<T>>;

template <typename T>
using IsFloatingPoint = std::enable_if_t<std::is_floating_point_v<T>>;

template <typename T>
using IsNotFloatingPoint = std::enable_if_t<!std::is_is_flong_point_v<T>>;

template <typename T>
using IsArray = std::enable_if_t<std::is_array_v<T>>;

template <typename T>
using IsNotArray = std::enable_if_t<!std::is_array_v<T>>;

template <typename T>
using IsEnum = std::enable_if_t<std::is_enum_v<T>>;

template <typename T>
using IsNotEnum = std::enable_if_t<!std : _is_enum_v<T>>;

template <typename T>
using IsUnion = std::enable_if_t<std::is_union_v<T>>;

template <typename T>
using IsNotUnion = std::enable_if_t<!std::is_union_v<T>>;

template <typename T>
using IsClass = std::enable_if_t<std::is_class_v<T>>;

template <typename T>
using IsNotClass = std::enable_if_t<!std::is_class_v<T>>;

template <typename T>
using IsFunction = std::enable_if_t<std::is_function_v<T>>;

template <typename T>
using IsNotFunction = std::enable_if_t<!std::is_function_v<T>>;

template <typename T>
using IsPointer = std::enable_if_t<std::is_pointer_v<T>>;

template <typename T>
using IsNotPointer = std::enable_if_t<!std::is_pointer_v<T>>;

template <typename T>
using IsLReference = std::enable_if_t<std::is_lvalue_reference_v<T>>;

template <typename T>
using IsNotLReference = std::enable_if_t<!std::is_lvalue_reference_v<T>>;

template <typename T>
using IsRReference = std::enable_if_t<std::is_rvalue_reference_v<T>>;

template <typename T>
using IsNotRReference = std::enable_if_t<!std::is_rvalue_reference_v<T>>;

template <typename T>
using IsMemberObjectPointer = std::enable_if_t<std::is_member_object_pointer_v<T>>;

template <typename T>
using IsNotMemberObjectPointer = std::enable_if_t<!std::is_member_object_pointer_v<T>>;

template <typename T>
using IsMemberFunctionPointer = std::enable_if_t<std::is_member_function_pointer_v<T>>;

template <typename T>
using IsNotMemberFunctionPointer = std::enable_if_t<!std::is_member_function_pointer_v<T>>;

/// Composite Type Categories
template <typename T>
using IsFundamental = std::enable_if_t<std::is_fundamental_v<T>>;

template <typename T>
using IsNotFundamental = std::enable_if_t<!std::is_fundamental_v<T>>;

template <typename T>
using IsArithmetic = std::enable_if_t<std::is_arithmetic_v<T>>;

template <typename T>
using IsNotArithmetic = std::enable_if_t<!std::is_arithmetic_v<T>>;

template <typename T>
using IsScalar = std::enable_if_t<std::is_scalar_v<T>>;

template <typename T>
using IsNotScalar = std::enable_if_t<!std::is_scalar_v<T>>;

template <typename T>
using IsObject = std::enable_if_t<std::is_object_v<T>>;

template <typename T>
using IsNotObject = std::enable_if_t<!std::is_object_v<T>>;

template <typename T>
using IsCompound = std::enable_if_t<std::is_compound_v<T>>;

template <typename T>
using IsNotCompound = std::enable_if_t<!std::is_compound_v<T>>;

template <typename T>
using IsReference = std::enable_if_t<std::is_reference_v<T>>;

template <typename T>
using IsNotReference = std::enable_if_t<!std::is_reference_v<T>>;

template <typename T>
using IsMemberPointer = std::enable_if_t<std::is_member_pointer_v<T>>;

template <typename T>
using IsNotMemberPointer = std::enable_if_t<!std::is_member_pointer_v<T>>;

/// Type Properties
template <typename T>
using IsConst = std::enable_if_t<std::is_const_v<T>>;

template <typename T>
using IsNotConst = std::enable_if_t<!std::is_const_v<T>>;

template <typename T>
using IsVolatile = std::enable_if_t<std::is_volatile_v<T>>;

template <typename T>
using IsNotVolatile = std::enable_if_t<!std::is_volatile_v<T>>;

template <typename T>
using IsTrivial = std::enable_if_t<std::is_trivial_v<T>>;

template <typename T>
using IsNoTTrivial = std::enable_if_t<!std::is_trivial_v<T>>;

template <typename T>
using IsTriviallyCopyable = std::enable_if_t<std::is_trivially_copyable_v<T>>;

template <typename T>
using IsNotTriviallyCopyable = std::enable_if_t<!std::is_trivially_copyable_v<T>>;

template <typename T>
using IsStandardLayout = std::enable_if_t<std::is_standard_layout_v<T>>;

template <typename T>
using IsNotStandardLayout = std::enable_if_t<!std::is_standard_layout_v<T>>;

template <typename T>
using IsPOD = std::enable_if_t<std::is_pod_v<T>>;

template <typename T>
using IsNotPOD = std::enable_if_t<!std::is_pod_v<T>>;

template <typename T>
using IsLiteralType = std::enable_if_t<std::is_literal_type_v<T>>;

template <typename T>
using IsNotLiteralType = std::enable_if_t<!std::is_literal_type_v<T>>;

template <typename T>
using HasUniqueObjectRepresentations = std::enable_if_t<std::has_unique_object_representations_v<T>>;

template <typename T>
using HasNoUniqueObjectRepresentations = std::enable_if_t<!std::has_unique_object_representations_v<T>>;

template <typename T>
using IsEmpty = std::enable_if_t<std::is_empty_v<T>>;

template <typename T>
using IsNotEmpty = std::enable_if_t<!std::is_empty_v<T>>;

template <typename T>
using IsPolymorphic = std::enable_if_t<std::is_polymorphic_v<T>>;

template <typename T>
using IsNotPolymorphic = std::enable_if_t<!std::is_polymorphic_v<T>>;

template <typename T>
using IsAbstract = std::enable_if_t<std::is_abstract_v<T>>;

template <typename T>
using IsNotAbstract = std::enable_if_t<!std::is_abstract_v<T>>;

template <typename T>
using IsFinal = std::enable_if_t<std::is_final_v<T>>;

template <typename T>
using IsNotFinal = std::enable_if_t<!std::is_final_v<T>>;

template <typename T>
using IsAggregate = std::enable_if_t<std::is_aggregate_v<T>>;

template <typename T>
using IsNotAggregate = std::enable_if_t<!std::is_aggregate_v<T>>;

template <typename T>
using IsSigned = std::enable_if_t<std::is_signed_v<T>>;

template <typename T>
using IsNotSigned = std::enable_if_t<!std::is_signed_v<T>>;

template <typename T>
using IsUnsigned = std::enable_if_t<std::is_unsigned_v<T>>;

template <typename T>
using IsNotUnsigned = std::enable_if_t<!std::is_unsigned_v<T>>;

/// Supported Operations
template <typename T>
using IsConstructible = std::enable_if_t<std::is_constructible_v<T>>;

template <typename T>
using IsNotConstructible = std::enable_if_t<!std::is_constructible_v<T>>;

template <typename T>
using IsTriviallyConstructible = std::enable_if_t<std::is_trivially_constructible_v<T>>;

template <typename T>
using IsNotTriviallyConstructible = std::enable_if_t<!std::is_trivially_constructible_v<T>>;

template <typename T>
using IsNothrowConstructible = std::enable_if_t<std::is_nothrow_constructible_v<T>>;

template <typename T>
using IsNotNothrowConstructible = std::enable_if_t<!std::is_nothrow_constructible_v<T>>;

template <typename T>
using IsDefaultConstructible = std::enable_if_t<std::is_default_constructible_v<T>>;

template <typename T>
using IsNotDefaultConstructible = std::enable_if_t<!std::is_default_constructible_v<T>>;

template <typename T>
using IsTriviallyDefaultConstructible = std::enable_if_t<std::is_trivially_default_constructible_v<T>>;

template <typename T>
using IsNotTriviallyDefaultConstructible = std::enable_if_t<!std::is_trivially_default_constructible_v<T>>;

template <typename T>
using IsNothrowDefaultConstructible = std::enable_if_t<std::is_nothrow_default_constructible_v<T>>;

template <typename T>
using IsNotNothrowDefaultConstructible = std::enable_if_t<!std::is_nothrow_default_constructible_v<T>>;

template <typename T>
using IsCopyConstructible = std::enable_if_t<std::is_copy_constructible_v<T>>;

template <typename T>
using IsNotCopyConstructible = std::enable_if_t<!std::is_copy_constructible_v<T>>;

template <typename T>
using IsTriviallyCopyConstructible = std::enable_if_t<std::is_trivially_copy_constructible_v<T>>;

template <typename T>
using IsNotTriviallyCopyConstructible = std::enable_if_t<!std::is_trivially_copy_constructible_v<T>>;

template <typename T>
using IsNothrowCopyConstructible = std::enable_if_t<std::is_nothrow_copy_constructible_v<T>>;

template <typename T>
using IsNotNothrowCopyConstructible = std::enable_if_t<!std::is_nothrow_copy_constructible_v<T>>;

template <typename T>
using IsMoveConstructible = std::enable_if_t<std::is_move_constructible_v<T>>;

template <typename T>
using IsNotMoveConstructible = std::enable_if_t<!std::is_move_constructible_v<T>>;

template <typename T>
using IsTriviallyMoveConstructible = std::enable_if_t<std::is_trivially_move_constructible_v<T>>;

template <typename T>
using IsNotTriviallyMoveConstructible = std::enable_if_t<!std::is_trivially_move_constructible_v<T>>;

template <typename T>
using IsNothrowMoveConstructible = std::enable_if_t<std::is_nothrow_move_constructible_v<T>>;

template <typename T>
using IsNotNothrowMoveConstructible = std::enable_if_t<!std::is_nothrow_move_constructible_v<T>>;

template <typename T>
using IsAssignable = std::enable_if_t<std::is_assignable_v<T>>;

template <typename T>
using IsNotAssignable = std::enable_if_t<!std::is_assignable_v<T>>;

template <typename T>
using IsTriviallyAssignable = std::enable_if_t<std::is_trivially_assignable_v<T>>;

template <typename T>
using IsNotTriviallyAssignable = std::enable_if_t<!std::is_trivially_assignable_v<T>>;

template <typename T>
using IsNothrowAssignable = std::enable_if_t<std::is_nothrow_assignable_v<T>>;

template <typename T>
using IsNotNothrowAssignable = std::enable_if_t<!std::is_nothrow_assignable_v<T>>;

template <typename T>
using IsCopyAssignable = std::enable_if_t<std::is_copy_assignable_v<T>>;

template <typename T>
using IsNotCopyAssignable = std::enable_if_t<!std::is_copy_assignable_v<T>>;

template <typename T>
using IsTriviallyCopyAssignable = std::enable_if_t<std::is_trivially_copy_assignable_v<T>>;

template <typename T>
using IsNotTriviallyCopyAssignable = std::enable_if_t<!std::is_trivially_copy_assignable_v<T>>;

template <typename T>
using IsNothrowCopyAssignable = std::enable_if_t<std::is_nothrow_copy_assignable_v<T>>;

template <typename T>
using IsNotNothrowCopyAssignable = std::enable_if_t<!std::is_nothrow_copy_assignable_v<T>>;

template <typename T>
using IsMoveAssignable = std::enable_if_t<std::is_move_assignable_v<T>>;

template <typename T>
using IsNotMoveAssignable = std::enable_if_t<!std::is_move_assignable_v<T>>;

template <typename T>
using IsTriviallyMoveAssignable = std::enable_if_t<std::is_trivially_move_assignable_v<T>>;

template <typename T>
using IsNotTriviallyMoveAssignable = std::enable_if_t<!std::is_trivially_move_assignable_v<T>>;

template <typename T>
using IsNothrowMoveAssignable = std::enable_if_t<std::is_nothrow_move_assignable_v<T>>;

template <typename T>
using IsNotNothrowMoveAssignable = std::enable_if_t<!std::is_nothrow_move_assignable_v<T>>;

template <typename T>
using IsDestructible = std::enable_if_t<std::is_destructible_v<T>>;

template <typename T>
using IsNotDestructible = std::enable_if_t<!std::is_destructible_v<T>>;

template <typename T>
using IsTriviallyDestructible = std::enable_if_t<std::is_trivially_destructible_v<T>>;

template <typename T>
using IsNotTriviallyDestructible = std::enable_if_t<!std::is_trivially_destructible_v<T>>;

template <typename T>
using IsNothrowDestructible = std::enable_if_t<std::is_nothrow_destructible_v<T>>;

template <typename T>
using IsNotNothrowDestructible = std::enable_if_t<!std::is_nothrow_destructible_v<T>>;

template <typename T>
using HasVirtualDestructor = std::enable_if_t<std::has_virtual_destructor_v<T>>;

template <typename T>
using HasNoVirtualDestructor = std::enable_if_t<!std::has_virtual_destructor_v<T>>;

template <typename T, typename U>
using IsSwappableWith = std::enable_if_t<std::is_swappable_with_v<T, U>>;

template <typename T, typename U>
using IsNotSwappableWith = std::enable_if_t<!std::is_swappable_with_v<T, U>>;

template <typename T>
using IsSwappable = std::enable_if_t<std::is_swappable_v<T>>;

template <typename T>
using IsNotSwappable = std::enable_if_t<!std::is_swappable_v<T>>;

template <typename T, typename U>
using IsNothrowSwappableWith = std::enable_if_t<std::is_nothrow_swappable_with_v<T, U>>;

template <typename T, typename U>
using IsNotNothrowSwappableWith = std::enable_if_t<!std::is_nothrow_swappable_with_v<T, U>>;

template <typename T>
using IsNothrowSwappable = std::enable_if_t<std::is_nothrow_swappable_v<T>>;

template <typename T>
using IsNotNothrowSwappable = std::enable_if_t<!std::is_nothrow_swappable_v<T>>;

/// Type Relationships
template <typename T, typename U>
using IsSame = std::enable_if_t<std::is_same_v<T, U>>;

template <typename T, typename U>
using IsNotSame = std::enable_if_t<!std::is_same_v<T, U>>;

template <typename Base, typename Derived>
using IsBaseOf = std::enable_if_t<std::is_base_of_v<Base, Derived>>;

template <typename Base, typename Derived>
using IsNotBaseOf = std::enable_if_t<!std::is_base_of_v<Base, Derived>>;

template <typename From, typename To>
using IsConvertible = std::enable_if_t<std::is_convertible_v<From, To>>;

template <typename From, typename To>
using IsNotConvertible = std::enable_if_t<!std::is_convertible_v<From, To>>;

template <typename From, typename To>
using IsNothrowConvertible = std::enable_if_t<std::is_nothrow_convertible_v<From, To>>;

template <typename From, typename To>
using IsNotNothrowConvertible = std::enable_if_t<!std::is_nothrow_convertible_v<From, To>>;

template <typename Fn, typename... ArgTypes>
using IsInvocable = std::enable_if_t<std::is_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNotInvocable = std::enable_if_t<!std::is_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsInvocableR = std::enable_if_t<std::is_invocable_r_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNotInvocableR = std::enable_if_t<!std::is_invocable_r_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNothrowInvocable = std::enable_if_t<std::is_nothrow_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNotNothrowInvocable = std::enable_if_t<!std::is_nothrow_invocable_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNothrowInvocableR = std::enable_if_t<std::is_nothrow_invocable_r_v<Fn, ArgTypes...>>;

template <typename Fn, typename... ArgTypes>
using IsNotNothrowInvocableR = std::enable_if_t<!std::is_nothrow_invocable_r_v<Fn, ArgTypes...>>;