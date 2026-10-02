# Dangling Pointer

## What is this topic?
This topic explains **Dangling Pointers**, one of the most destructive and difficult-to-debug bugs in C/C++. A dangling pointer is a pointer that holds a memory address, but the memory at that address has been freed or is no longer valid.

## Why is it important?
When you dereference a null pointer, the program crashes immediately, making it easy to find the bug. When you dereference a *dangling pointer*, the program might continue running, silently corrupting other variables, behaving unpredictably, or crashing hours later in a completely unrelated part of the code. Preventing dangling pointers is the main reason modern C++ invented smart pointers.

## Prerequisites
- [10-pointer-vs-reference](../10-pointer-vs-reference/README.md)

## Learning Outcomes
1. Identify the three main ways a pointer becomes dangling (Stack return, Use-after-free, Out-of-scope).
2. Understand why dangling pointers cause silent corruption.
3. Learn C and C++ mitigation strategies to prevent them.
