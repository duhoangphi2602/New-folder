# Solutions: void Pointer

## Solution 1: The Generic Swap
**Answer:** You cannot write `*a = *b` because `a` and `b` are `void*`. The compiler does not know how many bytes to read/write, so dereferencing is illegal.
To implement this, you must cast both pointers to `uint8_t*` (or `char*`) and swap them byte-by-byte in a loop up to `size`:
```cpp
void generic_swap(void* a, void* b, size_t size) {
    uint8_t* byte_a = static_cast<uint8_t*>(a);
    uint8_t* byte_b = static_cast<uint8_t*>(b);
    
    for (size_t i = 0; i < size; i++) {
        uint8_t temp = byte_a[i];
        byte_a[i] = byte_b[i];
        byte_b[i] = temp;
    }
}
```

## Solution 2: C++ Strictness
**Answer:** The C++ compiler will throw an error: `invalid conversion from 'void*' to 'uint8_t*'`. 
- **Why C++ enforces this:** C++ is heavily focused on type safety. `malloc` returns a `void*`. In C, `void*` implicitly converts to any pointer, which can hide dangerous bugs if you assign it to the wrong pointer type. C++ strictly requires the programmer to prove they know what type they are assigning the raw memory to.
- **The Fix:** The developer must explicitly cast the return value:
```cpp
uint8_t* buffer = static_cast<uint8_t*>(malloc(1024));
// Or C-style cast: (uint8_t*)malloc(1024);
```
*(Though ideally, in C++, they should refactor to use `new uint8_t[1024]` or `std::array`/`std::vector`).*
