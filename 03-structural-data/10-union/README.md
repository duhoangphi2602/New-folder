# Union

## What is this topic?
This topic introduces the `union` keyword, a memory-sharing construct that allows multiple variables to physically occupy the exact same memory address.

## Why is it important?
In embedded programming, RAM is extremely scarce. If a device has three different sensors, but only ever activates one sensor at a time, allocating memory for all three simultaneously wastes precious RAM. A `union` allows them to share the same memory space. Additionally, `unions` are heavily used to "type pun" (e.g., easily converting 4 individual bytes received over UART into a single 32-bit floating-point number).

## Prerequisites
- [01-struct](../01-struct/README.md)
- [02-struct-memory-layout](../02-struct-memory-layout/README.md)

## Learning Outcomes
1. Understand the difference in memory allocation between a `struct` and a `union`.
2. Learn how to use a `union` to overlay data structures.
3. Understand the concept of "Type Punning" and how `std::memcpy` or `std::bit_cast` (C++20) is safer in modern C++.
