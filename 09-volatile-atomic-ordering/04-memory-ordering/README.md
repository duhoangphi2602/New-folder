# Memory Ordering

## What is this topic?
This topic introduces **Memory Ordering**, the most complex and advanced concurrency topic in C++11. It dictates how the compiler and the CPU are allowed to aggressively reorder your code execution behind your back.

## Why is it important?
You write line 1. Then you write line 2. You assume the CPU executes line 1 before line 2. **In modern processors (like ARM Cortex-M7), this assumption is false.** The Compiler and the CPU will constantly swap the execution order of your code to maximize pipeline performance. If you are communicating between two RTOS tasks without a Mutex, this out-of-order execution will catastrophically break your logic.

## Prerequisites
- [03-std-atomic](../03-std-atomic/README.md)

## Learning Outcomes
1. Understand why Compilers and CPUs reorder instructions.
2. Define `std::memory_order_relaxed`, `acquire`, `release`, and `seq_cst`.
3. Fix an out-of-order execution bug using a Release-Acquire barrier.
