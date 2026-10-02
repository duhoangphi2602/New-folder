# Arrays

## What is this topic?
This topic covers **C-style Arrays**, which are contiguous blocks of memory holding multiple elements of the same type. While modern C++ prefers `std::array`, bare-metal hardware drivers often expose memory as C-style arrays.

## Why is it important?
When you read 64 bytes of data from a UART peripheral using DMA, the hardware dumps it into a C-style array. You must know how arrays are declared, initialized, and how they behave in memory before moving on to pointers and `std::array`.

## Prerequisites
- [01-variables-and-addresses](../01-variables-and-addresses/README.md)

## Learning Outcomes
1. Declare and initialize C-style arrays.
2. Understand contiguous memory layout.
3. Learn how to calculate the size of an array using `sizeof`.
