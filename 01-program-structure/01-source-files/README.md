# Source Files

## What is this topic?
This topic covers the physical organization of C/C++ projects into **source files** (`.c`, `.cpp`) and **header files** (`.h`, `.hpp`), which is the foundation of C/C++ compilation.

## Why is it important?
Unlike Java or Python, C/C++ requires you to manually manage the separation of *interface* (declarations) and *implementation* (definitions). Understanding this separation is essential to prevent build errors, optimize compile times, and design modular embedded systems.

## Prerequisites
- [00-getting-started/first-program](../../00-getting-started/first-program/README.md)

## Learning Outcomes
1. Understand the difference between headers and source files.
2. Know how to use include guards (`#pragma once`).
3. Understand how `extern "C"` enables C/C++ interoperability in embedded systems.
