# Interview Questions: nullptr

## 1. What is the difference between `NULL` and `nullptr`?
**Answer:** `NULL` is a legacy preprocessor macro, often defined simply as the integer `0`. `nullptr` is a modern C++11 keyword with a dedicated type (`std::nullptr_t`). `nullptr` can be implicitly converted to any pointer type, but it absolutely cannot be converted to an integer, making it type-safe.

## 2. Why is `NULL` dangerous in C++ but perfectly fine in C?
**Answer:** C does not support **Function Overloading**. In C, if a function takes a pointer, passing `0` (NULL) will correctly be interpreted as a null pointer. C++ supports function overloading. If you have two functions with the same name—one taking an `int` and one taking a pointer—passing `NULL` will silently call the `int` version, causing catastrophic logic bugs. 

## 3. Why is it important to initialize unused pointers to `nullptr` in an embedded system?
**Answer:** An uninitialized pointer holds a garbage memory address. If accidentally dereferenced, it corrupts random memory silently, leading to bugs that are incredibly hard to trace. If a pointer is initialized to `nullptr` and accidentally dereferenced, the CPU attempts to write to address `0x00000000`. On most microcontrollers (like ARM Cortex-M), this is protected or invalid memory for writing, which immediately triggers a Hard Fault. Failing fast and deterministically is much easier to debug than silent corruption.
