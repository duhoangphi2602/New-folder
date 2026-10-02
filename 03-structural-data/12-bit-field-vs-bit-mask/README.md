# Bit-Field vs Bit-Mask

## What is this topic?
This topic compares two different techniques for manipulating sub-byte data (individual bits): the `struct`-based **Bit-Field**, and the bitwise logic-based **Bit-Mask**.

## Why is it important?
While Bit-Fields look incredibly clean (`reg.mode = 2;`), their lack of cross-compiler portability makes them a massive liability in production embedded systems. The industry standard, universally portable way to manipulate bits is using **Bit-Masks** with bitwise operators (`&`, `|`, `~`, `<<`, `>>`). You must master bit-masking to read vendor datasheets and write professional hardware drivers.

## Prerequisites
- [10-bit-field](../10-bit-field/README.md)

## Learning Outcomes
1. Understand the exact bitwise operations used to Set, Clear, Toggle, and Read individual bits.
2. Compare the readability of Bit-Fields vs the portability of Bit-Masks.
3. Learn how to extract and insert multi-bit values using masks and shifts.
