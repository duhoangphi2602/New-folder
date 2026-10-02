# Solutions: Declaration vs Definition

## Solution 1: Spot the Violation
**Answer:** It will compile successfully (each `.cpp` file compiles fine individually), but it will **fail to link**. 
It violates the **One Definition Rule (ODR)** because the function is *defined* in a header, resulting in two definitions of `multiply` in the final program.

**Fix 1 (Separate Declaration/Definition):**
In `.h`: `int multiply(int a, int b);`
In `.cpp`: `int multiply(int a, int b) { return a * b; }`

**Fix 2 (Inline):**
In `.h`: `inline int multiply(int a, int b) { return a * b; }`
*(The `inline` keyword relaxes the ODR, allowing multiple identical definitions, which the linker merges into one).*

## Solution 2: Global Variables
**Answer:**
In `system_state.h` (Declaration only):
```cpp
#pragma once
extern bool is_system_running;
```

In `system_state.cpp` (Definition exactly once):
```cpp
#include "system_state.h"
bool is_system_running = false;
```
Other files (`main.cpp`, etc.) just `#include "system_state.h"`.

## Solution 3: Forward Declaration
**Answer:** `car.h` will **not compile**. 
A forward declaration only introduces the name. The compiler does not know the `sizeof(Wheel)`. Therefore, it cannot allocate memory for an array of 4 `Wheel` objects by value.

If changed to `Wheel* wheels[4];`, it **will compile**. The compiler knows the size of a pointer (usually 4 or 8 bytes) regardless of what it points to, so it can allocate the array of pointers.
