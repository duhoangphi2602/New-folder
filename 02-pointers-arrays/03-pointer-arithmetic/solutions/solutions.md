# Solutions: Pointer Arithmetic

## Solution 1: The Address Math
**Answer:** `0x1018`.
**Math:** 
- The pointer is of type `uint64_t`, which consumes 8 bytes.
- Adding 3 to the pointer advances it by 3 elements.
- `3 * 8 bytes = 24 bytes`.
- 24 in Decimal = `0x18` in Hexadecimal.
- `0x1000 + 0x18 = 0x1018`.

## Solution 2: Array Indexing Equivalence
**Answer:**
```cpp
*(arr + 4) = 99;
```
The compiler treats `arr` as a pointer to the first element. It adds `4` (scaled automatically by the element size), and then dereferences the result `*` to assign the value `99`.

## Solution 3: The Void Pointer Trap
**Answer:** Pointer arithmetic relies on the **Scaling Rule** (`N * sizeof(type)`). A `void` type has **no size** (`sizeof(void)` is illegal). Therefore, the compiler does not know how many bytes to jump when you say `ptr + 5`.
**The Fix:** You must cast the pointer to a type that has a size of exactly 1 byte (like `uint8_t*` or `char*`) so the compiler scales by `5 * 1`.
```cpp
void advance_5_bytes(void* ptr) {
    uint8_t* byte_ptr = static_cast<uint8_t*>(ptr);
    byte_ptr = byte_ptr + 5;
    // Or condensed: ptr = static_cast<uint8_t*>(ptr) + 5;
}
```
*(Note: Some C compilers, like GCC, have a non-standard extension that treats `sizeof(void)` as 1 and allows this arithmetic, but it is illegal in strict ISO C++).*
