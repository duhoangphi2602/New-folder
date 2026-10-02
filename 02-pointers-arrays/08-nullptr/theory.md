# nullptr (C++11)

## 1. Concept
`nullptr` is a keyword introduced in C++11 to represent a null pointer literal. It has its own distinct type: `std::nullptr_t`. It implicitly converts to any pointer type, but it **does not convert to integer types**.

## 2. Why
In C, `NULL` is typically a preprocessor macro defined as `((void *)0)` or simply `0`. Because C++ does not allow implicit conversion from `void*` to other pointers, early C++ compilers defined `NULL` simply as `0`. 

This breaks **Function Overloading** (a feature C++ has but C does not). If you have a function that takes an `int`, and another overload that takes an `int*`, passing `NULL` will call the `int` version, causing massive logic bugs.

## 3. Syntax (The Problem with NULL)

```cpp
void process(int x) { /* Integer version */ }
void process(int* p) { /* Pointer version */ }

int main() {
    process(NULL);    // BUG! Calls process(int) because NULL is 0.
    process(nullptr); // SAFE! Calls process(int*) because nullptr is a pointer type.
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating function overloading and `nullptr`).*

## 5. Embedded usage (Initialization and Safety)
In bare-metal embedded programming, an uninitialized pointer (e.g., `uint8_t* tx_buffer;`) will hold whatever garbage data was sitting on the stack. If you accidentally dereference it, the CPU writes to a random memory address, which might overwrite a critical hardware register or RTOS structure, causing a subtle bug that takes weeks to find.

If you initialize it to `nullptr` (`uint8_t* tx_buffer = nullptr;`), and you accidentally dereference it, the CPU attempts to write to address `0x00000000`. On ARM Cortex-M, this address contains the Flash Vector Table (read-only). The CPU immediately triggers a **Hard Fault**. While a crash sounds bad, a deterministic, immediate crash is *infinitely better* than a silent memory corruption.

**Golden Rule:**
```cpp
// BAD: Uninitialized
uint8_t* rx_buffer; 

// BAD: Legacy C style
uint8_t* rx_buffer = NULL; 

// GOOD: Modern C++ style
uint8_t* rx_buffer = nullptr; 
```

## 6. Trade-offs

| Null Literal | Pros | Cons |
|--------------|------|------|
| `NULL` (C-style) | Compiles on 30-year-old compilers. | Breaks C++ function overloading. Not type-safe. |
| `nullptr` (C++11) | Type-safe. Fixes overloading. Clear intent. | Requires C++11 or newer (standard on all modern embedded toolchains). |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
