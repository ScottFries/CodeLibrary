#pragma once

/**
 * Cross platform support for handling warnings.
 */

#if defined(_MSC_VER)
    #define DISABLE_WARNING_PUSH __pragma(warning( push ))
    #define DISABLE_WARNING_POP __pragma(warning( pop ))
    #define DISABLE_WARNING(warning_number) __pragma(warning( disable : warning_number ))
    #define DISABLE_WARNING_CP(warning_name, warning_number) DISABLE_WARNING(warning_number)
#elif defined (__GNUC__) || defined(__clang__)
    // GCC & Clang disable warnings by string name, so we wrap our call with stringify operators to allow a clean call to DISABLE_WARNING
    #define PRAGMA(command) _Pragma(#command)
    
    #define DISABLE_WARNING_PUSH PRAGMA(GCC diagnostic push)
    #define DISABLE_WARNING_POP PRAGMA(GCC diagnostic pop)
    #define DISABLE_WARNING(warning_name) PRAGMA(GCC diagnostic ignored #warning_name)
    #define DISABLE_WARNING_CP(warning_name, warning_number) DISABLE_WARNING(warning_name)
#else
    #define DISABLE_WARNING_PUSH
    #define DISABLE_WARNING_POP
    #define DISABLE_WARNING(...)
    #define DISABLE_WARNING_CP(...)
#endif

// Want a way to disable multiple warnings at once
// Would be nice to enforce a disable/enable pairing
// Would be nice to support overload of ignore/warn/error