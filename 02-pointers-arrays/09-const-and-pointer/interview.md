# Interview Questions: const and Pointers

## 1. What is the difference between `const int* p` and `int* const p`?
**Answer:** 
- `const int* p` means the data being pointed to is constant (you cannot write `*p = 5`), but the pointer itself can change to point to a different address.
- `int* const p` means the pointer's address is constant (it can never point to anything else), but the data it points to can be modified (`*p = 5` is allowed).

## 2. Why is "const correctness" important in C/C++ APIs?
**Answer:** It serves as a contract between the API author and the user. If an API accepts a `const` pointer, it guarantees the user's data will not be modified. It also allows the compiler to perform aggressive optimizations (like placing variables in read-only memory/Flash) because it can mathematically prove the data will never be altered.

## 3. Can you pass a `uint8_t*` (mutable pointer) into a function expecting a `const uint8_t*`? Can you do the reverse?
**Answer:** 
- **Yes**, you can pass mutable data into a function expecting `const` data. The compiler implicitly adds the `const` restriction. 
- **No**, you cannot pass `const` data into a function expecting mutable data. This would strip away the `const` protection, which is illegal in C++ (unless forced via a highly dangerous `const_cast`).
