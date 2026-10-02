# Volatile Keyword

## What is this topic?
This topic explores the `volatile` keyword in C/C++, a tool specifically designed to prevent the compiler from optimizing away memory accesses that have side effects invisible to the compiler.

## Why is it important?
In desktop programming, `volatile` is almost never used correctly. In embedded systems, it is mandatory. Without `volatile`, reading hardware registers (like a GPIO input) or checking flags updated by an Interrupt Service Routine (ISR) will fail spectacularly in Release builds (`-O2` or `-O3`) because the compiler will delete your code, assuming nothing outside the main thread could possibly change the value.

## Prerequisites
- [04-volatile-in-isr](../../08-interrupt-isr/04-volatile-in-isr/README.md)
- [14-memory-mapped-register](../../02-pointers-arrays/14-memory-mapped-register/README.md)

## Learning Outcomes
1. Understand how Compiler Optimization (`-O3`) aggressively caches variables in CPU registers.
2. Explain how `volatile` forces the compiler to emit `LDR` (Load) and `STR` (Store) assembly instructions to physical RAM every single time.
3. Identify the two specific scenarios where `volatile` is strictly required in embedded systems.
