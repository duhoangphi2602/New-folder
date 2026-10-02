# Bit-Field

## What is this topic?
This topic covers the C/C++ `bit-field` syntax, which allows you to define integer struct members with a specific, custom bit width (e.g., exactly 3 bits, or exactly 1 bit).

## Why is it important?
Embedded systems constantly deal with data that does not fit neatly into standard 8, 16, or 32-bit boundaries. For example, a hardware register might pack five different 1-bit flags and a 3-bit status code into a single 8-bit byte. Bit-fields allow you to map these sub-byte fields directly to C/C++ struct members.

## Prerequisites
- [03-structural-data/01-struct](../01-struct/README.md)
- [03-structural-data/02-struct-memory-layout](../02-struct-memory-layout/README.md)

## Learning Outcomes
1. Understand the syntax of defining bit-fields in structs.
2. Recognize the convenience of accessing bits using the `.` (dot) operator.
3. Understand the severe portability and ABI (Application Binary Interface) risks associated with bit-fields in embedded systems.
