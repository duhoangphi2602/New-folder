# Function Pointers

## What is this topic?
This topic explores **Function Pointers**, which are variables that store the memory address of a function rather than the address of data. 

## Why is it important?
In C and bare-metal embedded programming, function pointers are the primary mechanism for implementing **Callbacks** (e.g., telling an interrupt what to do when a UART byte arrives) and **Dispatch Tables** (e.g., parsing network packets without massive `switch` statements). They are the C-language equivalent of polymorphism and dependency injection.

## Prerequisites
- [06-functions](../06-functions/README.md)
- [02-pointers-arrays/02-pointer-basics](../../02-pointers-arrays/02-pointer-basics/README.md)

## Learning Outcomes
1. Understand the complex syntax of declaring function pointers.
2. Implement a callback mechanism.
3. Understand the difference between a raw C function pointer and C++ alternatives like `std::function` or lambdas.
