# Memory Alignment

## What is this topic?
This topic explores **Memory Alignment**, which dictates the specific memory addresses at which certain data types are allowed to be stored.

## Why is it important?
On desktop computers, if you violate alignment rules, the CPU secretly fixes it for you (at a small performance cost). In embedded systems (like the ARM Cortex-M0), if you violate alignment rules, the CPU triggers a **Hard Fault** and the system crashes immediately. Furthermore, hardware peripherals like DMA (Direct Memory Access) or cache controllers often have strict alignment requirements for the buffers they interact with. 

## Prerequisites
- [12-memory-safety](../12-memory-safety/README.md)

## Learning Outcomes
1. Understand natural alignment boundaries (multiples of 2, 4, 8).
2. Learn how pointer casting can cause alignment faults.
3. Use C++11 `alignof` and `alignas` keywords to inspect and enforce alignment.
