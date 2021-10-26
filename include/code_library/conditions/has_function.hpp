#pragma once

#include <type_traits>

/**
 * Creates a TMP type for determining if a type has a specified function.
 * This type will ensure the specified function matches the given function name, return type, qualifiers, and arguments.
 * This type must have visibility to the specified function in order to detect is.
 *
 * @param func          The name of the function.
 * @param return_type   The return type the function should have (if none, must specify `void`).
 * @param qualifiers    The qualifiers the function should have (const and/or volatile; may be empty).
 * @param args...       The arguement types the function should take (ordered; may be empty).
 */
#define MAKE_HAS_FUNC(func, return_type, qualifiers, /*args*/...)                  \
    template <typename T>                                                          \
    struct has_##func                                                              \
    {                                                                              \
        /* Ensures qualifiers exist on function; called by has_func below */       \
        template <typename A>                                                      \
        static std::true_type has_func(return_type (A::*)(__VA_ARGS__) qualifiers) \
        {                                                                          \
            return std::true_type();                                               \
        }                                                                          \
        /* Ensures function exists on type */                                      \
        template <typename A>                                                      \
        static decltype(has_func(&A::func)) has_func(decltype(&A::func), void*)    \
        {                                                                          \
            return decltype(has_func(&A::func))();                                 \
        }                                                                          \
        /* SFINAE catch */                                                         \
        template <typename A>                                                      \
        static std::false_type has_func(...)                                       \
        {                                                                          \
            return std::false_type();                                              \
        }                                                                          \
        /* Evaluate by passing 2 'nullptrs' (2 to skip first form of has_func) */  \
        using type = decltype(has_func<T>(0, 0));                                  \
        static constexpr bool value = type::value;                                 \
    };                                                                             \
    template <typename T>                                                          \
    static constexpr bool has_##func##_v = has_##func<T>::value;                   \

/// Example usages
/**
 * MAKE_HAS_FUNC(foo, void,)
 *
 * Most basic form.
 * Type created will be `has_foo`.
 * Expected function will be `foo`
 * Expected return type will be `void`.
 * Expected qualifiers will be none (not that this arg still must be passed, even if empty).
 * Expected args will be none.
 * Matching function declaration: `void foo()`.
 */

/**
 * MAKE_HAS_FUNC(bar, int, const, bool)
 * Type created will be `has_bar`.
 * Expected function will be `bar`.
 * Expected return type will be `int`.
 * Expected qualifiers will be `const`.
 * Expected args will be `bool`.
 * Matching function declaration: `int bar(bool b) const`.
 */

/**
 * MAKE_HAS_FUNC(foobar, const std::string&, const volatile, int, bool, char*)
 * Type created will be `has_foobar`.
 * Expected function will be `foobar`.
 * Expected return type will be `const std::string&`.
 * Expected qualifiers will be `const volatile`.
 * Expected args will be `int, bool, char*`.
 * Matching function delcaration: `const std::string& foobar(int i, bool b, char* c) const volatile`
 * Note: ordering of `const` and `volatile` qualifiers does not matter.
 */
