# Interview Questions: Memory Safety

## 1. Why are C and C++ considered memory-unsafe languages compared to Rust or Java?
**Answer:** Because C and C++ trust the programmer completely. They do not perform automatic bounds-checking on array accesses, they allow arbitrary pointer arithmetic (letting you point to any memory address), and they require manual allocation/deallocation (in C) without checking if memory has already been freed. This allows for unmatched performance but introduces severe risks if the programmer makes a logic error.

## 2. What is a Buffer Overflow?
**Answer:** A buffer overflow occurs when a program writes data beyond the allocated boundaries of a fixed-length buffer (array). This corrupts adjacent memory, which might contain other variables, return addresses, or RTOS control structures. It is a primary vector for cybersecurity vulnerabilities.

## 3. How does `std::array` improve upon C-style arrays for memory safety?
**Answer:** `std::array` does not decay into a pointer, meaning it always retains its size information. It provides an `.at()` method which performs explicit runtime bounds checking (throwing an exception if out of bounds), and it works perfectly with C++ range-based for loops, eliminating the possibility of Off-By-One index errors entirely.
