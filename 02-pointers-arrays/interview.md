# Chapter 02 — Interview Questions

## Beginner

1. **What is a pointer?**
   A variable that stores the memory address of another variable. On a 32-bit system, a pointer is 4 bytes.

2. **What is the difference between `&` and `*` operators?**
   `&` is the address-of operator (gives the address of a variable). `*` is the dereference operator (accesses the value at the address a pointer holds).

3. **What happens when you increment a `uint32_t*` pointer?**
   The address advances by `sizeof(uint32_t)` = 4 bytes, not 1 byte. This is pointer arithmetic — the compiler scales the increment by the size of the pointed-to type.

4. **What is array decay?**
   When an array name is used in most expressions, it "decays" to a pointer to its first element. This is why `sizeof(arr)` gives the total array size, but `sizeof(ptr)` after `ptr = arr` gives only the pointer size.

5. **What is `nullptr` and why is it preferred over `NULL`?**
   `nullptr` is a C++11 literal with type `std::nullptr_t`. Unlike `NULL` (which is typically `0`), `nullptr` is type-safe and won't accidentally convert to an integer.

## Intermediate

6. **What is the difference between `const int*` and `int* const`?**
   `const int*`: pointer to const — you can change where it points, but can't modify the data through it.
   `int* const`: const pointer — you can modify the data, but can't change where it points.

7. **What is a dangling pointer?**
   A pointer that refers to memory that has been freed or to a local variable that has gone out of scope. Dereferencing it is undefined behavior.

8. **What is the difference between a pointer and a reference?**
   A reference is an alias — it must be initialized, cannot be null, and cannot be reseated. A pointer can be null, uninitialized, and repointed. Under the hood, a reference is typically implemented as a pointer.

9. **When should you use `std::array` instead of a C array?**
   `std::array` knows its own size (`.size()`), doesn't decay to a pointer, supports iterators, and is bounds-checkable (`.at()`). It has zero overhead compared to C arrays.

## Advanced

10. **What is Memory-Mapped I/O?**
    Hardware peripherals are accessed through the CPU's address space. Each peripheral register has a fixed physical address. Reading/writing to that address communicates with the hardware — no special I/O instructions needed.

11. **Why must hardware registers be accessed through `volatile` pointers?**
    Without `volatile`, the compiler may optimize away repeated reads/writes because it assumes the memory value doesn't change externally. Hardware registers change independently of the program — `volatile` forces the compiler to always perform the memory access.

12. **What is `std::string_view` and why is it useful in embedded?**
    A non-owning reference to a contiguous sequence of characters. It avoids copying strings and doesn't allocate memory. Useful for parsing protocol data or passing string-like parameters without allocation. Danger: the underlying data must outlive the `string_view`.

13. **What causes an alignment fault?**
    Accessing data at an address that doesn't satisfy the type's natural alignment. For example, reading a `uint32_t` from an odd address on ARM Cortex-M0 causes a hard fault. On Cortex-M3/M4, unaligned access may work but is slower.
