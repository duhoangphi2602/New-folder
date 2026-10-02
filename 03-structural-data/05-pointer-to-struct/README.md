# Pointer to Struct

## What is this topic?
This topic explains how to use pointers that hold the memory address of a `struct`, rather than a standard primitive variable.

## Why is it important?
Because structs often contain a large amount of data (dozens of bytes), passing them into functions "by value" forces the CPU to copy every single byte, which is terribly slow and consumes massive amounts of stack memory. In embedded C/C++, you will almost always pass a struct to a function by passing a pointer (or reference) to it.

## Prerequisites
- [01-struct](../01-struct/README.md)
- [02-pointer-basics](../../02-pointers-arrays/02-pointer-basics/README.md)

## Learning Outcomes
1. Understand the Arrow (`->`) operator and why it exists.
2. Learn how passing a pointer to a struct saves memory and CPU cycles.
3. Understand how pointers to structs are used to map hardware registers.
