# typedef and using

## What is this topic?
This topic covers Type Aliasing, which is the ability to give an existing data type a new, custom name. 

## Why is it important?
In C, `typedef` is heavily used to simplify complex pointer syntax and to create hardware-specific type names (like `uint32_t`). In modern C++, the `using` keyword has largely replaced `typedef` because it is far more readable and works with C++ templates. Understanding both is critical, as you will constantly interface with legacy C libraries that use `typedef`, while you should be writing your new code with `using`.

## Prerequisites
- [01-struct](../01-struct/README.md)
- [06-pointer-to-pointer](../../02-pointers-arrays/06-pointer-to-pointer/README.md)

## Learning Outcomes
1. Understand how to use the C-style `typedef`.
2. Learn the modern C++11 `using` syntax.
3. Understand how type aliasing makes complex function pointers readable.
