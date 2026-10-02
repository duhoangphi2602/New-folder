# The Heap

## What is this topic?
This topic covers the **Heap**, the region of RAM used for Dynamic Memory Allocation (`malloc`, `free`, `new`, `delete`).

## Why is it important?
In desktop programming (Java, Python, C#), the Heap is used for absolutely everything; objects are dynamically created and destroyed constantly, and a Garbage Collector cleans up the mess. In high-reliability Embedded C++, **the Heap is often strictly banned.** Understanding why the Heap is so dangerous—specifically Memory Leaks and Heap Fragmentation—is a fundamental requirement for writing stable firmware.

## Prerequisites
- [02-stack](../02-stack/README.md)
- [06-pointer-to-pointer](../../02-pointers-arrays/06-pointer-to-pointer/README.md)

## Learning Outcomes
1. Understand how `malloc` and `free` allocate memory on the Heap.
2. Understand the C++ equivalents: `new` and `delete`.
3. Understand why Heap Fragmentation will inevitably crash a long-running embedded system.
