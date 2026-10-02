# Pointer to Pointer

## What is this topic?
This topic covers **Double Pointers** (`**`). If a standard pointer holds the memory address of a variable, a pointer-to-a-pointer holds the memory address of another pointer.

## Why is it important?
In modern C++, double pointers are largely obsolete because we can use *references to pointers* (`*&`). However, embedded systems rely heavily on vendor C libraries (like STMicroelectronics HAL or FreeRTOS). In pure C, the *only* way a function can modify a caller's pointer is by accepting a double pointer. You will encounter them frequently in RTOS APIs.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)

## Learning Outcomes
1. Understand the syntax of multiple indirection (`**`).
2. Learn how C APIs use double pointers to return memory addresses to the caller.
3. Understand the modern C++ alternative (`*&`).
