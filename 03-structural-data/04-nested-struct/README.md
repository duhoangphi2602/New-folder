# Nested Structs

## What is this topic?
This topic explores the ability to place a struct inside another struct.

## Why is it important?
Real-world embedded systems are complex. A "Sensor Node" might contain a GPS module, an accelerometer, and a battery monitor. If you define all of these variables in a single flat struct, it becomes a massive, unreadable mess of 50 variables. Nested structs allow you to compose small, logical, reusable components (like a `Coordinates` struct) and embed them inside larger systems, perfectly mapping complex object hierarchies into contiguous memory.

## Prerequisites
- [01-struct](../01-struct/README.md)

## Learning Outcomes
1. Learn how to declare nested structs in C and C++.
2. Understand how to access members of nested structs using chained dot operators.
3. Observe how the compiler calculates the memory layout of nested structs.
