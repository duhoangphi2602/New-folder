# gcc vs g++

## What is this topic?
This topic explains the difference between the two most common compiler commands in the GNU Compiler Collection: `gcc` and `g++`.

## Why is it important?
A common mistake for beginners migrating from C to C++ is continuing to use the `gcc` command to build their projects. While `gcc` *can* compile C++ files, it will spectacularly fail during the Linker stage when you try to use any standard C++ features (like `new/delete` or `#include <iostream>`). Understanding exactly what `g++` does under the hood prevents hours of frustrating debugging.

## Prerequisites
- [05-linking](../05-linking/README.md)

## Learning Outcomes
1. Understand how the GNU Compiler Collection routes source files based on extensions.
2. Differentiate between `gcc` (the C frontend) and `g++` (the C++ frontend).
3. Explain why `g++` is strictly required to link the C++ Standard Library.
