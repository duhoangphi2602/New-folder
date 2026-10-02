# Solutions: inline, static, extern

## Solution 1: Storage Location
**Answer:**
- `a`: Static Memory (`.data`). Global variable.
- `b`: Static Memory (`.data`). Global variable with internal linkage.
- `c`: **Stack**. Local automatic variable.
- `d`: Static Memory (`.data`). Local static variable.

## Solution 2: C++17 Constants
**Answer:** In C++98, `const int` implicitly has internal linkage. If included in 10 files, the compiler creates **10 separate copies** of the variable in the final binary (wasting memory).
**C++17 Fix:**
```cpp
inline constexpr int BAUD_RATE = 115200;
```
Using `inline constexpr` guarantees that the linker will collapse all references to a single memory address, saving space and satisfying the ODR.

## Solution 3: State Machine Bug
**Answer:** The `id++` operation is **not thread-safe** (it is a read-modify-write operation). If Thread A reads `id`, gets preempted, and Thread B reads/increments `id`, Thread A will then write a stale value back. Both threads might get the same ID, or IDs might be skipped.
**The Fix:** Use `std::atomic` to make the increment thread-safe.
```cpp
#include <atomic>
int get_next_id() {
    static std::atomic<int> id{0};
    return ++id;
}
```
*(Note: C++11 guarantees that the initialization `id{0}` is thread-safe, but the `++` operation requires `std::atomic` to be thread-safe).*
