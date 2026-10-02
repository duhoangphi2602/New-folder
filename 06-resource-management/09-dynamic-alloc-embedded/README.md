# Dynamic Allocation in Embedded Systems

## What is this topic?
This topic concludes the Resource Management chapter by answering the ultimate question: *If dynamic allocation (the Heap) is so dangerous, why does it exist, and when are we actually allowed to use it in Embedded C++?*

## Why is it important?
Total banishment of the Heap is standard in aerospace and automotive systems, but overly restrictive for general IoT devices (smart home, wearables) that need to parse massive, variable-length JSON packets from AWS or Azure. You must know the "safe" patterns for using dynamic memory so you can build modern connected devices without causing crashes.

## Prerequisites
- [08-heap-fragmentation-embedded](../08-heap-fragmentation-embedded/README.md)
- [05-smart-pointers](../05-smart-pointers/README.md)

## Learning Outcomes
1. Identify the 3 acceptable patterns for dynamic allocation in embedded systems.
2. Understand the "Allocate Once, Run Forever" pattern.
3. Understand the necessity of the Heap for modern network protocols (JSON, TLS/SSL).
