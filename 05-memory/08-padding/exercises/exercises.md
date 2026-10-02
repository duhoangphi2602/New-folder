# Exercises: Memory Padding

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Calculate the Padding
Calculate the exact `sizeof` the following struct. Assume a 32-bit architecture where pointers are 4 bytes.
```cpp
struct SensorNode {
    uint16_t id;         // 2 bytes
    uint32_t timestamp;  // 4 bytes
    uint8_t  is_active;  // 1 byte
    void*    next_node;  // 4 bytes
};
```
**Task:** 
1. Draw out the memory map (e.g., Byte 0: id, Byte 1: id, Byte 2: padding...).
2. What is the total size?
3. Rewrite the struct to minimize its size. What is the new total size?

## Exercise 2: The `alignas` Keyword
C++11 introduced the `alignas` keyword, which allows you to *increase* the alignment requirement of a variable.
```cpp
struct CacheLine {
    alignas(16) uint32_t data[4];
    uint8_t flag;
};
```
**Task:** Why might a hardware engineer explicitly force a struct to align to a 16-byte or 32-byte boundary, rather than its natural 4-byte boundary? *(Hint: Think about CPU Caches or DMA).*
