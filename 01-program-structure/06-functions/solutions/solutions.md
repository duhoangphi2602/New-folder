# Solutions: Functions

## Solution 1: The Swapper
**Answer:**
- `swap_ptr` and `swap_ref` will successfully swap the values. 
- `swap_val` will **fail** to swap the values in `main`.
**Why:** `swap_val` receives copies of `a` and `b`. It successfully swaps the copies inside its own local scope, but as soon as the function returns, those copies are destroyed, and the original variables in `main` remain untouched.

## Solution 2: Stack Memory Calculation
**Answer:**
- `Matrix` contains `16 * 16 = 256` floats.
- A float is 4 bytes. `256 * 4 = 1024` bytes (1KB).
- The function takes *two* matrices by value, meaning two copies are made. `1KB + 1KB = 2KB`.
- **Consequence:** The arguments alone consume 2KB of stack space. On an MCU with a 2KB stack limit, this will cause an immediate **Stack Overflow**, crashing the system.
- **The Fix:** Pass by const reference: `void math_operation(const Matrix& m1, const Matrix& m2)`. This passes two 4-byte pointers instead of 2048 bytes of data, consuming only 8 bytes of stack.

## Solution 3: Dangling Reference
**Answer:** The function returns a reference to a local variable (`name`). Local variables are allocated on the stack and are immediately destroyed when the function returns. The caller receives a **dangling reference**—a pointer to memory that has been freed and is likely already overwritten by other data.
**Consequence:** Accessing this reference will result in undefined behavior (usually a crash or garbage text).
**The Fix:** Return by value (`std::string`), or declare the local variable as `static` so it lives in `.data` instead of the stack.
