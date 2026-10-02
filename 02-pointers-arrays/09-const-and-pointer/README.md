# const and Pointers

## What is this topic?
This topic explores the interaction between the `const` keyword and pointers. Because a pointer involves two things—the pointer variable itself, and the data it points to—the `const` keyword can be applied to either one, or both.

## Why is it important?
In C/C++, "const correctness" is a fundamental design principle. When passing a buffer to a transmission function (like `uart_send`), you must guarantee that the function will not accidentally modify the data. Conversely, when passing a buffer to a receive function (like `uart_receive`), the function *must* be allowed to modify the data. Mastering `const` with pointers is required to write safe APIs.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)

## Learning Outcomes
1. Differentiate between "Pointer to const data" and "const Pointer to mutable data".
2. Read C++ declarations right-to-left to instantly understand `const` placement.
3. Understand when to apply `const` to function parameters.
