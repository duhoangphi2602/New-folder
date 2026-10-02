# nullptr (C++11)

## What is this topic?
This topic explains `nullptr`, the type-safe null pointer literal introduced in C++11, which formally replaces the legacy C-style `NULL` macro.

## Why is it important?
In legacy C and C++98, developers used `NULL` or `0` to represent a pointer that points to nothing. This created severe bugs in C++ due to function overloading, where the compiler couldn't distinguish if `NULL` was meant to be the integer `0` or a memory address. `nullptr` solves this completely. Using `NULL` in modern C++ is considered a bad practice.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)

## Learning Outcomes
1. Understand why the `NULL` macro is dangerous in C++.
2. Learn how `nullptr` resolves function overloading ambiguities.
3. Establish the habit of always initializing pointers to `nullptr`.
