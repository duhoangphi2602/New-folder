# C++ Standard I/O (std::cout / std::cin)

## What is this topic?
This topic explores the modern C++ stream-based I/O library (`<iostream>`), which provides `std::cout` (Character Output) and `std::cin` (Character Input).

## Why is it important?
In standard PC development (Linux/Windows), `std::cout` is universally used because it is infinitely safer, easier to use, and completely type-safe compared to C's `printf`. However, embedded developers must understand *why* this incredible system is often strictly banned on microcontrollers, and how to use it safely when running code on high-end embedded Linux systems (like a Raspberry Pi).

## Prerequisites
- [01-c-standard-io](../01-c-standard-io/README.md)

## Learning Outcomes
1. Learn how to print text using `std::cout` and the insertion operator `<<`.
2. Understand why `std::cout` is perfectly type-safe.
3. Understand the massive memory and performance overhead of `<iostream>`.
