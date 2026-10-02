#pragma once

#include <iostream>
#include <cstdlib>

// A simple assertion macro for examples that works across platforms
// In a real embedded system, this would likely trigger a breakpoint or reset.

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" << #condition << "), " \
                      << "function " << __builtin_FUNCTION() \
                      << ", file " << __FILE__ \
                      << ", line " << __LINE__ << "." << std::endl \
                      << "Message: " << message << std::endl; \
            std::abort(); \
        } \
    } while (false)
