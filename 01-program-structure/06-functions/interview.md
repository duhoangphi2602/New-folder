# Interview Questions: Functions

## 1. What are the differences between pass-by-value, pass-by-pointer, and pass-by-reference?
**Answer:**
- **By Value:** Makes a complete copy of the argument. Safe, but slow and memory-intensive for large objects.
- **By Pointer:** Passes the memory address. Allows modifying the original object. Can be `nullptr`, requiring null-checks. Syntax requires `&` and `*`.
- **By Reference:** Passes an alias to the original object. Allows modifying the original. Cannot be null (usually). Cleaner syntax than pointers. (Under the hood, it is implemented as a pointer by the compiler).

## 2. When should you use `const&` as a parameter?
**Answer:** You should use `const&` (pass by const reference) when you need to pass a large object (like a struct, class, or `std::string`) into a function purely for reading. It provides the performance benefit of pointers (no copy overhead) with the safety of pass-by-value (the compiler prevents the function from modifying the object).

## 3. Why is recursion generally discouraged in embedded systems?
**Answer:** Embedded systems have very small, strictly limited stack sizes (e.g., 1KB to 4KB). Every time a function calls itself recursively, a new stack frame (containing arguments, return address, and local variables) is pushed onto the stack. Since the maximum depth of recursion is often unpredictable at runtime, it poses a severe risk of causing a Stack Overflow and crashing the system.

## 4. What is a function prototype?
**Answer:** A function prototype is a declaration that tells the compiler the name, return type, and parameters of a function, without providing the body. It is placed in header files to satisfy the compiler's need to know about a function before it is called in a translation unit.
