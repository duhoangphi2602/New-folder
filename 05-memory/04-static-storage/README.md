# Static Storage Duration

## What is this topic?
This topic explores **Static Storage Duration**, which dictates how Global Variables and the `static` keyword are allocated in memory.

## Why is it important?
Because the Heap (Dynamic Memory) is banned in safety-critical systems, and the Stack is too small for large arrays, embedded developers must rely heavily on Static Storage. When you declare a global array of 10KB, the compiler statically allocates it at compile-time. Understanding how this memory is reserved, and the specific behavior of the `static` keyword inside functions and files, is the foundation of embedded memory management.

## Prerequisites
- [02-stack](../02-stack/README.md)
- [03-heap](../03-heap/README.md)

## Learning Outcomes
1. Understand the lifecycle of Global Variables (Static Storage Duration).
2. Learn the two entirely different meanings of the `static` keyword in C/C++.
3. Understand why Static Storage is the safest memory allocation method for embedded systems.
