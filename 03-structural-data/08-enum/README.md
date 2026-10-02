# Enum (Legacy C-Style)

## What is this topic?
This topic explores the traditional C-style `enum` (Enumeration). An enumeration is a user-defined data type that consists of integral constants, providing a way to assign readable names to numbers.

## Why is it important?
Code riddled with "magic numbers" (`if (status == 2)`) is unreadable and impossible to maintain. Enums allow you to replace magic numbers with meaningful names (`if (status == STATUS_ERROR)`). In embedded programming, enums are universally used to represent states (e.g., State Machines), configuration modes, and error codes.

## Prerequisites
- [01-struct](../01-struct/README.md)

## Learning Outcomes
1. Learn how to declare a C-style `enum`.
2. Understand how enums map to underlying integers.
3. Learn about the "Namespace Pollution" flaw inherent to C-style enums.
