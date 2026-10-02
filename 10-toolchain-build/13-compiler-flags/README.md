# Compiler Flags

## What is this topic?
This topic introduces the command-line arguments (Flags) passed to the Compiler to control its behavior, specifically focusing on Language Standards and Architecture specifications.

## Why is it important?
Compilers have thousands of settings. By default, GCC is incredibly permissive. If you don't explicitly configure it, it will compile your code using 25-year-old C++ standards and generate machine code for generic, ancient CPUs, destroying both performance and modern C++17 safety features. 

## Prerequisites
- [02-compilation](../02-compilation/README.md)
- [11-arm-none-eabi](../11-arm-none-eabi/README.md)

## Learning Outcomes
1. Enforce specific language standards (e.g., `-std=c++17`).
2. Target specific hardware architectures (e.g., `-mcpu=cortex-m4`).
3. Differentiate between compilation flags and linker flags.
