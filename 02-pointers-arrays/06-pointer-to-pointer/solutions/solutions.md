# Solutions: Pointer to Pointer

## Solution 1: The Failed Allocation
**Answer:** In C/C++, all function arguments are passed by **value** (copied). When `init_dma_buffer(my_buffer)` is called, the compiler creates a *local copy* of the `NULL` pointer. The function successfully changes the local copy to point to `0x20005000`, but when the function returns, the local copy is destroyed, and the original `my_buffer` in `main` remains untouched (`NULL`).
**The Fix:**
```c
void init_dma_buffer(uint8_t** buffer_ptr) {
    *buffer_ptr = (uint8_t*)0x20005000;
}

int main() {
    uint8_t* my_buffer = NULL;
    init_dma_buffer(&my_buffer); // Pass address of the pointer
    my_buffer[0] = 0xFF;         // Safe!
}
```

## Solution 2: `char** argv`
**Answer:** 
- A string in C is an array of characters, which decays into a `char*` (a pointer to the first character).
- Command line arguments consist of *multiple* strings.
- Therefore, we need an array of strings. An array of `char*` decays into a pointer to its first element. A pointer to a `char*` is a `char**`.
`argv` points to a contiguous block of memory holding `char*` pointers, each of which points to a separate string in memory.
