# Source Files

## 1. Concept
C/C++ programs are organized into **source files** (`.c`, `.cpp`) and **header files** (`.h`, `.hpp`). A header file declares the **interface** (function prototypes, types, constants), while the source file provides the **implementation** (the actual code). 

## 2. Why
The C/C++ compilation model compiles each `.c`/`.cpp` file **independently** into an object file. Headers provide the declarations that allow one source file to safely call functions defined in another, without having to recompile the entire project every time a single file changes.

## 3. Syntax

**Include Guards (Mandatory for headers):**
Without include guards, a header included multiple times causes redefinition errors. Modern compilers support `#pragma once`.
```cpp
// sensor.h
#pragma once                        // Prevents double inclusion

#include <cstdint>

struct SensorData {
    std::uint16_t temperature;
    std::uint16_t humidity;
};

// Declaration (Interface)
SensorData read_sensor();
```

**Implementation (Source file):**
```cpp
// sensor.cpp
#include "sensor.h"

// Definition (Implementation)
SensorData read_sensor() {
    return SensorData{2500, 6000}; 
}
```

## 4. Example
See `examples/` for a minimal project demonstrating the separation of `main.cpp`, `header_example.hpp`, and `implementation.cpp`.

## 5. Embedded usage (`extern "C"`)
In embedded projects, separation is critical for modularity (e.g., keeping hardware drivers separate from application logic). Furthermore, embedded C++ projects frequently use vendor-provided C libraries. To include a C header in a C++ file, you must use `extern "C"` to prevent C++ Name Mangling.

```cpp
// uart.h — C-compatible header usable from both C and C++
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void uart_init(unsigned int baud);
void uart_send_byte(unsigned char byte);

#ifdef __cplusplus
}
#endif
```

## 6. Trade-offs

| Approach | Advantages | Disadvantages |
|----------|------------|---------------|
| **Header + Source Split** | Faster incremental builds. Clean API hiding. | Boilerplate code. Requires keeping both files in sync. |
| **Header-Only Libraries** | Extremely easy to include. Good for templates. | Massive compile times. Code bloat. |

## 7. Exercises
Please proceed to the `exercises/` folder to test your understanding of file separation and include guards.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
