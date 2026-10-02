# inline, static, extern

## What is this topic?
This topic breaks down three of the most important keywords in C/C++ that control **linkage** (who can see this code) and **storage duration** (how long this data lives).

## Why is it important?
In embedded systems, you must explicitly control what functions are public (API) and what functions are private (implementation details) to avoid linker collisions. Additionally, understanding where variables live (stack vs `.bss` vs `.data`) is controlled by `static` and `extern`, which is critical for memory management.

## Prerequisites
- [03-translation-unit](../03-translation-unit/README.md)
- [06-functions](../06-functions/README.md)

## Learning Outcomes
1. Understand the 3 completely different meanings of the `static` keyword.
2. Master `extern` and `extern "C"` for cross-file variable sharing and C-interop.
3. Understand `inline` functions and the C++17 `inline` variable feature.
