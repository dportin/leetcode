#ifndef WARNINGS_HPP
#define WARNINGS_HPP

#if defined(__GNUC__) || defined(__clang__)
    #define DO_PRAGMA(X) _Pragma(#X)
    #define DISABLE_WARNING_PUSH           DO_PRAGMA(GCC diagnostic push)
    #define DISABLE_WARNING_POP            DO_PRAGMA(GCC diagnostic pop)
    #define DISABLE_WARNING(warningName)   DO_PRAGMA(GCC diagnostic ignored #warningName)
#elif defined(_MSC_VER)
    #define DISABLE_WARNING_PUSH           __pragma(warning( push ))
    #define DISABLE_WARNING_POP            __pragma(warning( pop ))
    #define DISABLE_WARNING(warningNumber) __pragma(warning( disable : warningNumber ))
#else
    #define DISABLE_WARNING_PUSH
    #define DISABLE_WARNING_POP
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define DISABLE_WARNING_SIGN_COMPARE DISABLE_WARNING(-Wsign-compare)
    #define DISABLE_WARNING_UNUSED_PARAMETER DISABLE_WARNING(-Wunused-parameter)
#if defined(__clang__)
#else
#endif
#elif defined(_MSC_VER)
    #define DISABLE_WARNING_SIGN_COMPARE
    #define DISABLE_WARNING_UNUSED_PARAMETER
#else
    #define DISABLE_WARNING_SIGN_COMPARE
    #define DISABLE_WARNING_UNUSED_PARAMETER
#endif

#endif // WARNINGS_HPP