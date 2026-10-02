# Interview Questions: Struct Memory Layout

## 1. Is the compiler allowed to reorder struct members to save memory?
**Answer:** No. In standard C and C++, the compiler is strictly forbidden from reordering the members of a struct. They must be allocated in memory in the exact order they are declared in the code, from lowest address to highest address. (Note: Some modern languages like Rust *do* auto-reorder struct members to optimize memory, but C/C++ prioritizes deterministic hardware layout).

## 2. Why is the address of the first member of a struct always identical to the base address of the struct itself?
**Answer:** Because the standard dictates that there can be zero padding at the *beginning* of a struct. The first member is always placed exactly at offset `0`. Therefore, casting a pointer to a struct into a pointer to its first member is guaranteed to be safe and mathematically equivalent.

## 3. What is the `offsetof` macro used for?
**Answer:** The `offsetof(type, member)` macro calculates the byte offset of a specific member from the beginning of the struct. It is crucial in embedded systems for writing compile-time assertions (`static_assert`) to guarantee that a struct representing hardware registers perfectly matches the byte offsets listed in the vendor's datasheet.
