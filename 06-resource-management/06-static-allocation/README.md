# Static Allocation

## What is this topic?
This topic explores **Static Memory Allocation**, the safest and most deterministic way to manage memory in embedded systems. Instead of requesting memory from the Heap while the program is running, the compiler pre-allocates exactly the right amount of memory during the compilation process.

## Why is it important?
In critical systems (like pace-makers, ABS brakes, or flight controllers), a failure to allocate memory is fatal. By allocating everything statically, the compiler can mathematically prove whether your program will fit in the available RAM *before* you even flash the chip. If it compiles, you are guaranteed not to run out of memory.

## Prerequisites
- [04-static-storage](../../05-memory/04-static-storage/README.md)
- [15-std-array](../../02-pointers-arrays/15-std-array/README.md)

## Learning Outcomes
1. Differentiate between Dynamic Allocation (Heap) and Static Allocation (BSS/Data/Stack).
2. Use `std::array` and C++ templates to size buffers at compile-time.
3. Understand the architectural trade-offs of reserving maximum required RAM.
