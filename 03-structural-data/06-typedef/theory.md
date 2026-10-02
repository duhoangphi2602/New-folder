# typedef and using

## 1. Concept
Type aliasing does not create a new underlying data type; it simply creates a synonym (an alias) for an existing type. If you alias an `unsigned int` as `Age`, the compiler treats them as the exact same type mathematically.

## 2. Why
1. **Abstraction**: Instead of hardcoding `unsigned long`, you can alias it to `SystemTime_t`. If you later port your code to a 64-bit architecture, you only have to change the alias in one place. (This is exactly how `<cstdint>` implements `uint32_t`).
2. **Readability**: Function pointers in C have famously horrific syntax. Aliasing makes them look like normal variables.

## 3. Syntax (Legacy C `typedef`)

The C-style syntax places the new alias name at the very end of the declaration, which can be confusing.
```c
// 1. Basic alias
typedef unsigned int uint32_t;

// 2. Struct alias (Mandatory in C to avoid typing 'struct' everywhere)
typedef struct {
    int x;
    int y;
} Point2D;

// 3. Function pointer alias (Extremely confusing syntax)
typedef void (*CallbackFunc)(int, float);
```

## 4. Syntax (Modern C++11 `using`)

C++11 introduced the `using` keyword for type aliasing. It follows the standard `NewName = OldType` assignment syntax, making it incredibly easy to read.

```cpp
// 1. Basic alias
using uint32_t = unsigned int;

// 2. Struct alias (Usually unnecessary in C++ because structs are already types, 
//    but useful for renaming)
using Point2D = CoordinateSystem::CartesianPoint;

// 3. Function pointer alias (Extremely clean!)
using CallbackFunc = void (*)(int, float);
```

## 5. Example
*(See `examples/` for runnable code demonstrating function pointer aliasing).*

## 6. Embedded usage (Hardware Abstraction)
HAL (Hardware Abstraction Layer) libraries use type aliases extensively to decouple your application logic from the underlying silicon.

```cpp
// hardware_defs.h
#if defined(STM32F4)
    using Register_t = uint32_t;
#elif defined(AVR_ATMEGA)
    using Register_t = uint8_t;
#endif

// application.cpp
void write_register(Register_t val) {
    // This code now compiles perfectly on both 8-bit and 32-bit CPUs
}
```

## 7. Trade-offs (typedef vs using)

| Feature | `typedef` (Legacy C) | `using` (Modern C++11) |
|---------|----------------------|------------------------|
| **Syntax** | Confusing (alias name is buried inside). | Clean (`Alias = Type`). |
| **Templates** | Does not support templates. | Supports template aliasing (`template<typename T> using MyVec = std::vector<T>;`). |
| **Compatibility**| Compiles in pure C. | C++ only. |

**Golden Rule:** In C++, always use `using`. Only use `typedef` if you are writing a C header file that must be included by a pure C compiler.

## 8. Exercises
Please proceed to the `exercises/` folder.

## 9. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
