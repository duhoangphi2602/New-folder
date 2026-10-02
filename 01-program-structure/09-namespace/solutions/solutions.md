# Solutions: Namespace

## Solution 1: The Global Pollution Bug
**Answer:** `#include` acts as a copy-paste. Any file that includes `math_util.h` will involuntarily have the entire `std` namespace dumped into its global scope. 
**Example Failure:** If another developer includes `math_util.h`, and then tries to declare their own custom function `void vector()`, the compiler will throw an ambiguous definition error because it doesn't know if the developer means their new function, or the `std::vector` class from the standard library!

## Solution 2: C++17 Refactoring
**Answer:** C++17 allows nested namespaces to be defined concisely on a single line.
```cpp
namespace Drivers::Sensors::I2C {
    class TemperatureSensor {
        // ...
    };
}
```

## Solution 3: Internal Linkage
**Answer:**
Way 1 (The C-style approach):
```cpp
static uint32_t crc32(const uint8_t* data) { /* ... */ }
```
Way 2 (The C++ approach - Anonymous Namespace):
```cpp
namespace {
    uint32_t crc32(const uint8_t* data) { /* ... */ }
}
```
**Preference:** Modern C++ guidelines generally prefer the **Anonymous Namespace** for hiding classes and types, because `static` only works for variables and functions. However, for a simple function in an embedded environment, both are perfectly acceptable and compile to the exact same machine code.
