# new and delete

## What is this topic?
This topic introduces `new` and `delete`, the C++ native replacements for `malloc` and `free`. 

## Why is it important?
You cannot use `malloc` to create C++ objects because `malloc` does not understand Constructors. `new` solves this by allocating the memory *and* calling the Constructor in a single step. However, raw `new` and `delete` still suffer from all the memory leak dangers of `malloc` and `free`. In modern C++ (C++11/17), using raw `new` and `delete` is generally considered a bad practice, but you must know how they work to understand the engine underneath modern Smart Pointers.

## Prerequisites
- [01-malloc-free](../01-malloc-free/README.md)

## Learning Outcomes
1. Understand the difference between `malloc` (raw memory) and `new` (object initialization).
2. Learn the syntax for allocating single objects and arrays.
3. Understand why mixing `new` and `free`, or `new[]` and `delete` causes catastrophic crashes.
