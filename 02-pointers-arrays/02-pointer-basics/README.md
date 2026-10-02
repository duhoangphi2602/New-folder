# Pointer Basics

## What is this topic?
This topic introduces the concept of a **pointer**, the most powerful and notorious feature of C/C++. A pointer is simply a variable that holds a memory address instead of a standard value.

## Why is it important?
Pointers are non-negotiable in embedded systems. Because microcontrollers require you to read and write directly to specific hardware memory addresses (like GPIO registers or UART buffers), you must use pointers. Without pointers, you literally cannot control the hardware.

## Prerequisites
- [01-variables-and-addresses](../01-variables-and-addresses/README.md)

## Learning Outcomes
1. Understand pointer declaration syntax.
2. Master the Reference (`&`) and Dereference (`*`) operators.
3. Understand the severe danger of dereferencing a `nullptr` or uninitialized pointer.
