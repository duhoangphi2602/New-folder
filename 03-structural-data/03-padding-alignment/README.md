# Struct Padding and Alignment

## What is this topic?
This topic explains **Struct Padding**: the invisible bytes of dead memory that compilers automatically inject into your structs.

## Why is it important?
Because CPUs prefer to read memory at specific alignment boundaries (e.g., 4-byte boundaries for 32-bit integers), compilers will pad structs with empty bytes to satisfy the CPU hardware. If you do not understand this, you will write a struct that you think is 5 bytes long, but the compiler makes it 8 bytes. When you send this 8-byte struct over a network or UART, the receiver (expecting 5 bytes) will parse completely corrupted data.

## Prerequisites
- [02-struct-memory-layout](../02-struct-memory-layout/README.md)
- [13-alignment](../../02-pointers-arrays/13-alignment/README.md)

## Learning Outcomes
1. Understand why compilers inject padding bytes (alignment requirements).
2. Learn how to manually reorder struct members to minimize wasted RAM.
3. Learn how to use the compiler attribute `__attribute__((packed))` to strip out padding for network protocols, and understand its severe performance/safety consequences.
