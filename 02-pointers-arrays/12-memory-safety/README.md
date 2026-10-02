# Memory Safety

## What is this topic?
This topic consolidates the concepts of pointers and arrays into the broader paradigm of **Memory Safety**. It covers the philosophy of defensive programming in C and C++, focusing on preventing crashes before they happen.

## Why is it important?
In C and C++, you are driving a car with no seatbelts. The compiler trusts you completely and will happily translate code that overwrites critical memory. In an embedded system, a memory violation (like a buffer overflow or dangling pointer) doesn't just crash an app—it halts the entire device, which might be a pacemaker, a car braking system, or a satellite.

## Prerequisites
- [04-arrays](../04-arrays/README.md)
- [11-dangling-pointer](../11-dangling-pointer/README.md)

## Learning Outcomes
1. Identify the 4 deadliest memory bugs (Buffer Overflow, Dangling Pointer, Null Dereference, Uninitialized Memory).
2. Learn how modern C++17 paradigms (like `std::array` and `std::span`) mitigate these bugs.
3. Understand defensive initialization techniques.
