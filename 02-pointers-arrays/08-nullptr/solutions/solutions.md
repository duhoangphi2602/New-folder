# Solutions: nullptr

## Solution 1: The Hardware Reset Bug
**Answer:** The user meant to pass a null pointer to call the `void (*cb)()` overload to disable the callback. However, because `NULL` is defined as the integer `0` in C++, the compiler resolves the overload to the `int` version. It will call `set_callback(int interrupt_priority)` with a priority of `0`. The callback remains active (or uninitialized), and the interrupt priority is accidentally changed! 
**The Fix:** The user MUST call `set_callback(nullptr);` to ensure the compiler matches the pointer overload.

## Solution 2: `std::nullptr_t`
**Answer:** The exact data type is `std::nullptr_t`.
```cpp
#include <cstddef>

void my_function(std::nullptr_t arg) {
    // This function can ONLY be called by passing 'nullptr'
}
```
