# Pointer Arithmetic

## What is this topic?
This topic explains how to perform math on pointers. Because a pointer holds a memory address (a number), you can add and subtract from that number to navigate through memory.

## Why is it important?
In embedded systems, hardware peripherals and communication protocols often return raw contiguous blocks of memory (arrays or buffers). Pointer arithmetic is the standard, high-performance way to parse through bytes in a UART packet, step through a DMA buffer, or navigate a block of pixels for an LCD display.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)

## Learning Outcomes
1. Understand the core rule of pointer arithmetic: **Scaling**.
2. Learn how to advance pointers to read sequential data.
3. Learn how pointer subtraction calculates the distance between two addresses.
