# Namespace

## What is this topic?
This topic introduces the C++ **Namespace** feature, a mechanism used to group related functions, classes, and variables under a specific name to prevent name collisions in large projects.

## Why is it important?
In C, if two libraries both define a function named `init()`, the program will not link. C developers solve this with verbose prefixes (e.g., `uart_init()`, `spi_init()`). C++ solves this cleanly with namespaces, allowing you to organize code logically without runtime overhead. 

## Prerequisites
- [02-declaration-vs-definition](../02-declaration-vs-definition/README.md)
- [08-inline-static-extern](../08-inline-static-extern/README.md)

## Learning Outcomes
1. Understand how to define and use namespaces.
2. Learn the modern C++17 syntax for nested namespaces.
3. Understand why `using namespace` in header files is a fatal design flaw.
