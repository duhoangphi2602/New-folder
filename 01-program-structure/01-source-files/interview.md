# Interview Questions: Source Files

## 1. What is the difference between a header file and a source file?
**Answer:** A header file (`.h`/`.hpp`) defines the *interface* of a module, containing declarations (function prototypes, structs, macros). A source file (`.c`/`.cpp`) contains the *implementation* of those functions.

## 2. What is an include guard and why is it needed?
**Answer:** An include guard (like `#ifndef MY_HEADER_H` ... `#endif` or `#pragma once`) prevents a header file from being included multiple times in the same translation unit. Without it, the compiler would see duplicate declarations, resulting in redefinition errors.

## 3. What does `extern "C"` do and when do you use it?
**Answer:** `extern "C"` instructs the C++ compiler not to perform "name mangling" on the enclosed functions, forcing them to use standard C linkage. You use it in header files when a C++ program needs to call functions written and compiled in C (e.g., vendor-provided hardware drivers or RTOS APIs).

## 4. Why shouldn't you define non-inline functions in header files?
**Answer:** Because if that header is included by multiple `.cpp` files, the function will be defined in multiple translation units. During the linking phase, the linker will throw a "Multiple Definition" error. (Unless the function is marked `inline`, in which case the linker will collapse the definitions).
