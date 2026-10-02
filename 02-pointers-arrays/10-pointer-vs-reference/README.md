# Pointer vs Reference

## What is this topic?
This topic compares the C-style **Pointer** (`*`) with the C++-style **Reference** (`&`). Both mechanisms allow you to indirectly access data in memory without copying it, but they have fundamentally different syntactic and safety rules.

## Why is it important?
Modern C++ design heavily favors References over Pointers for function arguments and return values because they are inherently safer (they cannot be null). However, in embedded programming, you still *must* use pointers for hardware access, C-interoperability, and dynamic buffer parsing. Knowing exactly when to use which is a core skill of an embedded C++ engineer.

## Prerequisites
- [02-pointer-basics](../02-pointer-basics/README.md)
- [08-nullptr](../08-nullptr/README.md)

## Learning Outcomes
1. Understand the core differences in initialization, nullability, and syntax.
2. Know exactly when to use `const Type&` vs `const Type*` in function parameters.
3. Understand why references cannot completely replace pointers in hardware-level code.
