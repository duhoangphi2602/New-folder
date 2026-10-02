# Exercises: Pointer to Pointer

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Failed Allocation
A junior developer writes a C-style initialization function for a DMA buffer, but it keeps crashing.
```c
void init_dma_buffer(uint8_t* buffer) {
    // Simulate malloc or hardware address assignment
    buffer = (uint8_t*)0x20005000;
}

int main() {
    uint8_t* my_buffer = NULL;
    init_dma_buffer(my_buffer);
    
    // Crash! my_buffer is still NULL!
    my_buffer[0] = 0xFF; 
}
```
**Task:** Why is `my_buffer` still `NULL` in `main()`? Rewrite `init_dma_buffer` using C-style double pointers to fix the bug.

## Exercise 2: `char** argv`
The standard entry point for a desktop C++ application is:
```cpp
int main(int argc, char** argv)
```
**Task:** Explain what `argv` actually is in terms of memory layout. Why is it a double pointer instead of a single pointer?
