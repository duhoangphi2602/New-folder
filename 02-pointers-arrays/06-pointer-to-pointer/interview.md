# Interview Questions: Pointer to Pointer

## 1. When is it absolutely necessary to use a double pointer (`**`) in C?
**Answer:** In pure C, it is absolutely necessary when a function needs to modify a pointer that belongs to the caller (e.g., allocating memory dynamically and returning the address to the caller through an argument, or advancing a pointer in a parsing function).

## 2. What is the modern C++ alternative to passing a double pointer to a function?
**Answer:** Passing a **reference to a pointer** (`Type*&`). This achieves the exact same goal (allowing the function to modify the caller's pointer) but provides much cleaner syntax and prevents the risk of passing a `nullptr` as the double pointer itself.

## 3. Describe the memory layout of a `char** argv` array.
**Answer:** `argv` is a pointer holding the memory address of an array. The elements inside this array are themselves pointers (`char*`), each holding the memory address of the first character of a null-terminated string located elsewhere in memory.
