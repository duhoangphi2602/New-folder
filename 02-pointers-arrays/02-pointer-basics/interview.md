# Interview Questions: Pointer Basics

## 1. What is a pointer?
**Answer:** A pointer is a variable that stores a memory address. The size of the pointer itself depends on the system architecture (e.g., 4 bytes on a 32-bit system, 8 bytes on a 64-bit system), regardless of the size of the data it points to.

## 2. What is the difference between the `&` and `*` operators?
**Answer:** 
- The `&` (address-of) operator is used on a standard variable to get its memory address. 
- The `*` (dereference) operator is used on a pointer variable to follow the address it holds and access the actual data stored at that address.

## 3. What is a null pointer, and why is `nullptr` preferred over `NULL` in modern C++?
**Answer:** A null pointer is a pointer that intentionally points to nothing (address 0). It is used to indicate that the pointer is invalid or unassigned. In older C/C++, `NULL` was often just a macro defined as the integer `0`. This caused subtle bugs because the compiler couldn't tell if you meant the number 0 or the pointer 0. C++11 introduced `nullptr`, which has its own specific type (`std::nullptr_t`), ensuring type safety and preventing those overload resolution bugs.

## 4. If `sizeof(uint8_t)` is 1 and `sizeof(uint32_t)` is 4, what is the size of `uint8_t*` and `uint32_t*` on a 32-bit microcontroller?
**Answer:** They are both 4 bytes. A pointer only stores a memory address. On a 32-bit system, all memory addresses are 32 bits (4 bytes) wide, completely independent of the size of the data they are pointing to.
