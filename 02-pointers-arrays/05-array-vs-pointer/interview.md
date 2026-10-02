# Interview Questions: Array vs Pointer (Decay)

## 1. Are arrays and pointers the same thing in C/C++?
**Answer:** No. An array is a block of contiguous memory that knows its total size and data type. A pointer is a single variable that holds a memory address. The confusion arises because an array's name implicitly converts (decays) into a pointer to its first element in most expressions.

## 2. What does `sizeof` return when called on an array parameter inside a function?
**Answer:** It returns the size of a pointer (usually 4 or 8 bytes), because the array decayed into a pointer when it was passed into the function. It does NOT return the size of the original array.

## 3. How do you prevent array decay when passing an array to a function in C++?
**Answer:** You can pass the array by reference `void process(int (&arr)[5])` or use modern C++ wrappers like `std::array<int, 5>` or `std::span<int>` (C++20). These maintain type safety and do not lose their size information. In standard C, it is impossible to prevent decay, so you must always pass the length as an additional argument.
