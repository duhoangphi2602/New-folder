# Memory Alignment

## What is this topic?
This topic explains **Memory Alignment**: the strict hardware rule dictating exactly which memory addresses a variable is legally allowed to start on.

## Why is it important?
On older PC processors (like x86), you can put a 4-byte integer at any memory address you want. On embedded ARM Cortex-M processors, if you put a 4-byte integer at an odd address (like `0x20000001`) and try to read it, the CPU will immediately trigger a Hard Fault and crash the system. Understanding alignment is critical when casting pointers (e.g., parsing network packets) or designing data structures.

## Prerequisites
- [06-memory-map](../06-memory-map/README.md)
- [03-padding-alignment](../../03-structural-data/03-padding-alignment/README.md)

## Learning Outcomes
1. Understand the "Natural Alignment" rule for standard data types.
2. Understand why unaligned memory access crashes ARM processors.
3. Learn the C++ `alignof` keyword to determine hardware alignment requirements.
