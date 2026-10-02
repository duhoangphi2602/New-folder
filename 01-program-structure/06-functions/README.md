# Functions

## What is this topic?
This topic covers the fundamental building block of C/C++ programs: **Functions**. It explains how functions are declared, defined, and how arguments are passed into them.

## Why is it important?
Writing modular, reusable code requires functions. In embedded systems, understanding exactly *how* arguments are passed (by value, pointer, or reference) is critical because passing large objects incorrectly can instantly overflow the tiny microcontrollers stack memory or waste precious CPU cycles.

## Prerequisites
- [02-declaration-vs-definition](../02-declaration-vs-definition/README.md)

## Learning Outcomes
1. Understand the syntax of function declarations and definitions.
2. Master the difference between Pass-by-Value, Pass-by-Pointer, and Pass-by-Reference.
3. Understand the memory implications (stack usage) of function calls in embedded systems.
