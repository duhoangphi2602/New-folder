# Translation Unit

## What is this topic?
This topic explores the concept of a **translation unit**, which is the fundamental unit of code that the C/C++ compiler actually processes.

## Why is it important?
Many confusing compilation and linking errors (like "undefined reference", "multiple definition", or "undeclared identifier") are easily solved once you understand that the compiler is completely blind to the rest of the project and only processes one translation unit at a time.

## Prerequisites
- [01-source-files](../01-source-files/README.md)
- [02-declaration-vs-definition](../02-declaration-vs-definition/README.md)

## Learning Outcomes
1. Understand what exactly constitutes a translation unit.
2. Understand how the preprocessor constructs it.
3. Understand how the compiler and linker interact with translation units.
