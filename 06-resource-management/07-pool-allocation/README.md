# Pool Allocation

## What is this topic?
This topic introduces the **Memory Pool**, a hybrid memory management technique that provides the flexibility of dynamic allocation (`malloc`/`new`) with the safety and speed of static allocation. It is the gold standard for dynamic memory in Real-Time Operating Systems (RTOS).

## Why is it important?
Standard Heap allocation (`malloc`) causes fragmentation and has unpredictable execution times (non-deterministic). Static allocation is perfectly safe but wastes RAM when handling bursty workloads. Memory Pools give you the best of both worlds: O(1) allocation time, zero fragmentation, and the ability to dynamically assign memory to tasks that need it right now.

## Prerequisites
- [06-static-allocation](../06-static-allocation/README.md)
- [01-malloc-free](../01-malloc-free/README.md)

## Learning Outcomes
1. Understand how a Memory Pool architecture avoids fragmentation.
2. Implement a simple fixed-size block allocator.
3. Understand how RTOSs use Memory Pools for Queues and Mailboxes.
