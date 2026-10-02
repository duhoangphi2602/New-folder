# Memory-Mapped Register

## What is this topic?
This topic covers Memory-Mapped I/O (MMIO), the fundamental technique used in embedded systems to interact with hardware peripherals (like GPIO, UART, Timers) by reading and writing to specific memory addresses.

## Why is it important?
Without understanding MMIO, you cannot write firmware. A microcontroller doesn't have an operating system to manage hardware. You must directly instruct the silicon by manipulating the voltage levels of specific transistors, which are exposed to the programmer as memory addresses (Registers).

## Prerequisites
- [01-variables-and-addresses](../01-variables-and-addresses/README.md)
- [02-pointer-basics](../02-pointer-basics/README.md)
- [09-volatile-atomic-ordering/01-volatile](../../09-volatile-atomic-ordering/01-volatile/README.md)

## Learning Outcomes
1. Understand how physical hardware is mapped to the CPU's memory space.
2. Master the use of `reinterpret_cast` (or C-style casts) to create pointers to specific addresses.
3. Understand the absolute necessity of the `volatile` keyword in MMIO.
