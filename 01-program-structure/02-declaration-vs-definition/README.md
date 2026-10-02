# Declaration vs Definition

## What is this topic?
This topic distinguishes between **declaring** that something exists and **defining** what it actually is or where it lives in memory.

## Why is it important?
Confusing declarations and definitions leads to the two most common errors in C/C++ development:
1. **Compiler Error**: "Undeclared identifier" (you tried to use something before declaring it).
2. **Linker Error**: "Multiple definition of..." or "Undefined reference to..." (you violated the One Definition Rule).

## Prerequisites
- [01-source-files](../01-source-files/README.md)

## Learning Outcomes
1. Understand the One Definition Rule (ODR).
2. Differentiate between declaring and defining variables, functions, and classes.
3. Master the use of forward declarations to reduce compile times.
