# malloc() and free()

## What is this topic?
This topic reviews the C-standard functions `malloc()` and `free()`, the traditional way to request dynamic memory from the Heap.

## Why is it important?
Even though you are learning C++, you will constantly encounter legacy C code, third-party libraries, and RTOS APIs that rely on `malloc` and `free`. You must understand how they work, why they are unsafe, and why modern C++ replaces them.

## Prerequisites
- [03-heap](../../05-memory/03-heap/README.md)

## Learning Outcomes
1. Understand how `malloc` requests memory from the OS or RTOS.
2. Identify common bugs: Memory Leaks, Double Free, and Dangling Pointers.
3. Understand why `malloc` returns a `void*` and requires a cast.
