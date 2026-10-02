# Memory Padding

## What is this topic?
This topic explains **Padding**, the mechanism by which the C++ compiler automatically injects invisible, empty bytes into your `struct` definitions to satisfy the hardware's memory alignment rules.

## Why is it important?
Because the CPU requires Natural Alignment (e.g., a 4-byte integer must sit on an address divisible by 4), the compiler cannot simply pack struct members back-to-back. If a 1-byte `char` is followed by a 4-byte `int`, the compiler will waste 3 bytes of RAM between them to force the `int` onto a legal address. If you don't understand padding, a struct that you think takes 5 bytes might actually consume 8 bytes, causing massive RAM bloat or breaking your network packet layouts.

## Prerequisites
- [07-alignment](../07-alignment/README.md)
- [03-padding-alignment](../../03-structural-data/03-padding-alignment/README.md)

## Learning Outcomes
1. Learn how to manually calculate the size of a struct with padding.
2. Understand trailing padding (padding at the end of a struct).
3. Learn how to reorder struct members to save RAM.
