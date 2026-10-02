# Compilation (C++ to Assembly)

## What is this topic?
This topic focuses on **Stage 2** of the toolchain: the Compiler itself (e.g., GCC, Clang, MSVC). It explores how the compiler takes the massive text file from the Preprocessor and translates it into low-level CPU Assembly instructions.

## Why is it important?
When your code fails to build, 90% of the time it happens here. This is where C++ syntax rules are strictly enforced. Understanding how the compiler builds its AST (Abstract Syntax Tree), enforces type safety, and performs massive optimizations (`-O3`) is essential for understanding why your code runs the way it does.

## Prerequisites
- [01-preprocessing](../01-preprocessing/README.md)

## Learning Outcomes
1. Distinguish between syntax errors and semantic errors.
2. Understand how the Compiler generates an Abstract Syntax Tree (AST).
3. Understand the concept of "Dead Code Elimination" during optimization.
