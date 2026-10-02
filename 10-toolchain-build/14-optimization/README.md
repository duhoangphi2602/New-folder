# Optimization Flags

## What is this topic?
This topic explores the Optimization flags (`-O0`, `-O1`, `-O2`, `-O3`, `-Os`, `-Og`) passed to the Compiler in Stage 2.

## Why is it important?
Optimization is a double-edged sword. It can make your code run 10x faster and use 50% less Flash memory. However, if your code has undefined behavior, lacks `volatile` keywords, or relies on precise timing loops, turning on `-O3` will instantly break your firmware. 

## Prerequisites
- [01-volatile](../../09-volatile-atomic-ordering/01-volatile/README.md)
- [02-compilation](../02-compilation/README.md)

## Learning Outcomes
1. Differentiate the goals of `-O0`, `-O3`, and `-Os`.
2. Understand what the Compiler legally can and cannot delete.
3. Understand why delay loops fail under optimization.
