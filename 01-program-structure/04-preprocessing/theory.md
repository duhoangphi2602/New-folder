# Preprocessing

## 1. Concept
The **preprocessor** is the first phase of compilation. It scans the source code for preprocessor directives (lines starting with `#`) and performs simple text manipulation—copying files, replacing text, and conditionally removing blocks of code—*before* the actual C/C++ compiler runs. The preprocessor has no understanding of C/C++ syntax, types, or scopes.

## 2. Why
The preprocessor exists to allow source code to be dynamically configured before compilation. In embedded systems, the exact same C++ file might need to be compiled for an ARM chip on one day and an ESP32 on another. The preprocessor allows developers to conditionally include or exclude hardware-specific code without rewriting the core logic.

## 3. Syntax

### File Inclusion (`#include`)
The preprocessor literally **copies and pastes** the entire contents of the included file into the current source.
```cpp
#include <cstdint>       // System headers (searched in system paths)
#include "my_header.h"   // Project headers (searched locally first)
```

### Macros (`#define`)
Text replacement.
```cpp
// Object-like macro
#define BUFFER_SIZE 256

// Function-like macro
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

### Conditional Compilation (`#ifdef`)
```cpp
#ifdef DEBUG
    // This code is only compiled when DEBUG is defined
    printf("Debug value\n");
#endif
```

## 4. Example
*(See `examples/` for a demonstration of macro dangers vs `constexpr`).*

```cpp
// BUG: macro expands 'x' twice!
#define SQUARE(x) ((x) * (x))

int a = 5;
int result = SQUARE(a++);  // Expands to: ((a++) * (a++)) -> Undefined Behavior!
```
This is why modern C++ prefers `constexpr` functions, which are type-safe and evaluated exactly once.
```cpp
constexpr int square(int x) { return x * x; }
int result = square(a++);  // OK: a is incremented only once
```

## 5. Embedded usage
Conditional compilation is heavily used in embedded projects to select code for different hardware targets or debug configurations.

```cpp
#if defined(TARGET_STM32)
    #include "stm32_hal.h"
#elif defined(TARGET_NRF52)
    #include "nrf52_hal.h"
#else
    #error "No hardware target defined!"
#endif

// Conditionally compile out debug prints to save Flash memory
#ifdef ENABLE_UART_DEBUG
    #define DBG_PRINT(msg) uart_send(msg)
#else
    #define DBG_PRINT(msg) ((void)0)  // Compiles to absolutely nothing
#endif
```

## 6. Trade-offs

| Tool | Advantages | Disadvantages |
|------|------------|---------------|
| **`#define` Macros** | Universally supported (C and C++). Extremely flexible text substitution. | No type safety. Ignores namespaces. Causes severe hidden bugs. |
| **`constexpr` / `inline`** | Type-safe. Respects scope/namespaces. Debugger friendly. | Only available in C++. Doesn't work for conditional file inclusion. |
| **`#ifdef` Blocks** | Perfect for cross-platform hardware abstraction. | Can make code unreadable ("spaghetti `#ifdef`s"). |

## 7. Exercises
Please proceed to the `exercises/` folder to practice macro debugging.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
