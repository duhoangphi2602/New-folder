# Solutions: const and Pointers

## Solution 1: Read Right-to-Left
**Answer:**
1. `float const * ptr;` -> "ptr is a pointer (`*`) to a `const float`." (Data is read-only).
2. `char * const ptr;` -> "ptr is a `const` pointer (`*`) to a `char`." (Address is fixed, data is mutable).
3. `const uint16_t * const ptr;` -> "ptr is a `const` pointer (`*`) to a `uint16_t` that is `const`." (Both address and data are locked).

## Solution 2: API Design
**Answer:**
```cpp
void calculate_sha256(const uint8_t* input_data, size_t input_length, uint8_t* output_hash);
```
By marking `input_data` as `const uint8_t*`, you provide a compile-time guarantee that the hashing function will only read the input data, never modify it. `output_hash` must lack `const` because the driver needs to write the result there.

## Solution 3: The Compile Error
**Answer:** The error is: `invalid conversion from 'const char*' to 'char*'`.
**Why:** `greeting` points to read-only data (string literals are typically stored in the `.rodata` section of Flash memory). If the compiler allowed you to assign a `const char*` to a regular mutable `char*`, you would be able to bypass the `const` restriction and attempt to modify read-only memory, causing a Hard Fault. C++ prevents you from silently discarding `const` qualifiers.
