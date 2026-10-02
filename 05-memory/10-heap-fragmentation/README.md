# Heap Fragmentation

## What is this topic?
This topic explores **Heap Fragmentation**, the invisible killer of long-running embedded systems that rely on dynamic memory allocation (`malloc`/`free` or `new`/`delete`).

## Why is it important?
You can write code that perfectly frees every single byte of memory it allocates (Zero Memory Leaks). Yet, after running perfectly for 3 weeks, your system crashes with an Out-Of-Memory error. Why? Because the Heap has become so fragmented that `malloc` cannot find a single contiguous block of memory large enough to satisfy your request. Understanding this mathematical inevitability is why the aerospace and automotive industries strictly ban dynamic memory.

## Prerequisites
- [03-heap](../03-heap/README.md)

## Learning Outcomes
1. Understand the difference between Internal and External Fragmentation.
2. Visualize how perfectly legal `malloc` and `free` calls destroy the Heap over time.
3. Understand why Memory Pools are the standard embedded alternative.
