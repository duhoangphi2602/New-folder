# Professional Logging

## 1. Concept
A professional logging system categorizes messages by severity (Level):
1. **ERROR**: Fatal issues, system might crash.
2. **WARNING**: Unexpected behavior, but recoverable.
3. **INFO**: Normal system state changes.
4. **DEBUG**: High-frequency data used only by developers.

By using C preprocessor Macros instead of standard functions, we can instruct the compiler to physically delete specific log levels from the binary depending on the build configuration.

## 2. Why
If your drone has a 1000Hz motor control loop, putting a `printf` inside it will crash the drone due to UART blocking. But you *need* that `printf` when testing on the bench. 
If you use a macro `LOG_DEBUG("Motor speed: %d", speed);`, you can change one global setting (`#define LOG_LEVEL INFO`). The preprocessor will instantly replace all `LOG_DEBUG` lines with empty spaces, guaranteeing zero CPU overhead in production.

## 3. Syntax (Variadic Macros and Built-ins)

### Compiler Built-in Macros
The compiler automatically provides these strings at compile time:
- `__FILE__`: The name of the current file (e.g., `"main.cpp"`).
- `__LINE__`: The current line number (e.g., `42`).

### Variadic Macros
To wrap `printf`, our macro must accept a variable number of arguments (like `%d %f`). We use `...` and `__VA_ARGS__`.

```c
// A simple wrapping macro
#define LOG_INFO(format, ...) \
    printf("[INFO] " format "\n", ##__VA_ARGS__)

// Usage:
LOG_INFO("Voltage: %d", 12); 
// Expands to: printf("[INFO] Voltage: %d\n", 12);
```
*(The `##` is a GCC extension that cleanly handles the case where you pass zero variable arguments).*

## 4. Example
*(See `examples/` for a fully functional, compile-time configurable logging framework).*

## 5. Embedded usage (The Heavy Framework)

Here is a standard, robust embedded logging header (`logger.h`):

```c
#pragma once
#include <cstdio>

// Define Levels
#define LEVEL_ERROR 1
#define LEVEL_INFO  2
#define LEVEL_DEBUG 3

// Set the current level (Usually passed via CMake: -DACTIVE_LOG_LEVEL=2)
#ifndef ACTIVE_LOG_LEVEL
#define ACTIVE_LOG_LEVEL LEVEL_INFO
#endif

// ERROR is always compiled
#if ACTIVE_LOG_LEVEL >= LEVEL_ERROR
    #define LOG_ERROR(fmt, ...) \
        printf("[ERROR] %s:%d: " fmt "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define LOG_ERROR(fmt, ...) // Expands to nothing!
#endif

// INFO is compiled if level is 2 or 3
#if ACTIVE_LOG_LEVEL >= LEVEL_INFO
    #define LOG_INFO(fmt, ...) \
        printf("[INFO]  " fmt "\r\n", ##__VA_ARGS__)
#else
    #define LOG_INFO(fmt, ...) // Expands to nothing!
#endif
```

## 6. Trade-offs (Macros vs C++ Templates)
Some C++ purists hate macros and prefer using `constexpr` functions or variadic templates for logging. 
However, **Macros are the industry standard for logging, even in modern C++17.**
Why? Because `__FILE__` and `__LINE__` are inherently tied to the exact physical line of code where the macro is expanded. If you use a C++ template function, `__LINE__` will report the line number *inside the template file*, not the file where the error actually occurred! (Note: C++20 introduced `std::source_location` to finally fix this, but it is rarely available in embedded toolchains).

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
