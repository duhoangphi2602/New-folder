# std::array (C++11)

## What is this topic?
This topic introduces `std::array`, the modern C++ replacement for traditional C-style arrays. It is a thin wrapper around a fixed-size array that provides a safer, more feature-rich interface without sacrificing any performance.

## Why is it important?
C-style arrays are notorious for causing bugs because they "decay" into pointers and lose their size information, leading to buffer overflows. `std::array` solves this by keeping its size information and providing safe bounds-checked access, making it the definitive standard for statically sized buffers in modern embedded C++.

## Prerequisites
- [04-arrays](../04-arrays/README.md)
- [05-array-vs-pointer](../05-array-vs-pointer/README.md)

## Learning Outcomes
1. Understand how `std::array` solves the array decay problem.
2. Learn how to pass `std::array` safely to functions.
3. Understand that `std::array` has zero runtime overhead compared to C-arrays.
