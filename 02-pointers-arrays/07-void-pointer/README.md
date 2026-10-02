# void Pointer

## What is this topic?
This topic covers the generic `void*` (void pointer). A void pointer is a special type of pointer that can hold the memory address of *any* data type, acting as a universal container for memory addresses.

## Why is it important?
C and C++ are strongly-typed languages, but embedded systems frequently require moving blocks of raw memory without caring about what that memory represents (e.g., copying a buffer, transmitting bytes over SPI, or passing arbitrary configuration structs to an RTOS task). `void*` is the C-language mechanism for achieving generic programming before C++ templates existed.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)
- [03-pointer-arithmetic](../03-pointer-arithmetic/README.md)

## Learning Outcomes
1. Understand the restrictions on dereferencing and scaling `void*`.
2. Learn how to cast `void*` to a concrete type.
3. See how RTOS (Real-Time Operating System) APIs use `void*` to achieve generic task parameters.
