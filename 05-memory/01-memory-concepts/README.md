# Memory Concepts (RAM vs ROM)

## What is this topic?
This topic introduces the fundamental physical memory hierarchy of an embedded system, specifically differentiating between Volatile Memory (RAM) and Non-Volatile Memory (ROM/Flash).

## Why is it important?
When you write a C++ program on a PC, you rarely think about where the code lives; the OS loads everything from the hard drive into RAM. In an embedded system, RAM is so scarce (often < 64KB) that the CPU must execute the program instructions *directly* from the Flash memory (ROM). If you don't understand the difference between RAM and ROM, you will accidentally declare large lookup tables in RAM and instantly crash your microcontroller with an Out-Of-Memory error.

## Prerequisites
- Basic understanding of C++ variables.

## Learning Outcomes
1. Differentiate between Volatile (RAM) and Non-Volatile (ROM/Flash) memory.
2. Understand the concept of Execute-In-Place (XIP).
3. Learn how to explicitly force variables into ROM using the `const` keyword to save RAM.
