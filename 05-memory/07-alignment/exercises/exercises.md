# Exercises: Memory Alignment

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Fault
You are given the following block of code:
```cpp
uint8_t buffer[8] = {0, 1, 2, 3, 4, 5, 6, 7};
uint16_t* ptr_a = (uint16_t*)(&buffer[2]); 
uint32_t* ptr_b = (uint32_t*)(&buffer[2]); 
```
Assume `buffer` starts at the perfectly aligned address `0x20001000`.
**Task:**
1. What is the absolute memory address of `&buffer[2]`?
2. If you execute `uint16_t val = *ptr_a;`, will it cause an Unaligned Access Exception? Why?
3. If you execute `uint32_t val = *ptr_b;`, will it cause an Unaligned Access Exception? Why?

## Exercise 2: `alignof` Structs
Look back at the `alignof` output in the `examples/` code. You will see that `alignof(MixedData)` returned `8`.
**Task:** Why is the alignment requirement of a `struct` equal to the alignment requirement of its largest individual member?
