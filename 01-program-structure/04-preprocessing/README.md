# Preprocessing

## What is this topic?
This topic explores the **preprocessor**, the very first phase of the C/C++ build process. It handles directives like `#include`, `#define`, and `#ifdef`.

## Why is it important?
The preprocessor is a simple text-substitution engine with no understanding of C/C++ syntax. While powerful for conditional compilation (especially in embedded), it is also the source of the most difficult-to-debug logic errors (due to macro expansion bugs).

## Prerequisites
- [03-translation-unit](../03-translation-unit/README.md)

## Learning Outcomes
1. Understand that the preprocessor merely copies and pastes text.
2. Master `#ifdef` for hardware-specific conditional compilation.
3. Understand the severe dangers of `#define` macros and why modern C++ prefers `constexpr` and templates.
