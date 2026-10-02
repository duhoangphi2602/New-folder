# Chapter 01 — Interview Questions

## Beginner

1. **What is the difference between a header file and a source file?**
   A header declares interfaces (function prototypes, types). A source file provides implementations. The compiler compiles source files; headers are included via `#include`.

2. **What is a translation unit?**
   The result of preprocessing one source file — all `#include` expanded, macros resolved. The compiler works on one translation unit at a time.

3. **What does `#pragma once` do?**
   It's a modern include guard that prevents a header from being included more than once in the same translation unit.

4. **What are the three parameter passing modes in C++?**
   Pass by value (copy), pass by pointer (address), and pass by reference (alias). Use `const&` to avoid copying large objects.

## Intermediate

5. **What is the One Definition Rule (ODR)?**
   An entity with external linkage must be defined exactly once across the entire program. Multiple declarations are allowed, but multiple definitions cause linker errors.

6. **What are the different meanings of `static`?**
   - File scope: internal linkage (private to translation unit).
   - Function scope: persistent local variable (survives across calls, stored in `.data`/`.bss`).
   - Class scope: shared across all instances of the class.

7. **What does `extern "C"` do?**
   Disables C++ name mangling for the enclosed declarations, allowing C++ code to call C functions (and vice versa).

8. **What is a function pointer and how is it used in embedded?**
   A variable holding the address of a function. Used for callbacks (e.g., ISR handlers, driver event notifications) and dispatch tables (command parsers).

## Advanced

9. **What happens before `main()` on an ARM Cortex-M MCU?**
   The CPU loads the initial stack pointer from Vector Table[0], jumps to Reset_Handler from Vector Table[1]. The Reset_Handler copies `.data` from Flash to RAM, zero-fills `.bss`, calls `SystemInit()`, calls `__libc_init_array()` (C++ global constructors), then calls `main()`.

10. **What is the Static Initialization Order Fiasco?**
    The order of construction of global/static objects across different translation units is undefined. If one global depends on another, it may use an uninitialized object. Solution: use the "Construct on First Use" idiom (function-local static).

11. **Can a lambda with captures be used as a C function pointer?**
    No. Only stateless lambdas (with `[]` captures) can decay to a C function pointer. Capturing lambdas have state and need `std::function` or a template parameter to be passed around.

12. **Why should you avoid recursion in embedded firmware?**
    Each recursive call creates a new stack frame. On MCUs with limited stack space (e.g., 1–4 KB), deep recursion can easily cause stack overflow, leading to a hard fault or memory corruption.
