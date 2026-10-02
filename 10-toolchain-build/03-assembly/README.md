# Assembly (The Assembler)

## What is this topic?
This topic covers **Stage 3** of the toolchain: the Assembler. It explains how human-readable Assembly instructions (`.s` files) are translated into raw binary machine code that the silicon CPU can execute.

## Why is it important?
While you rarely write Assembly code in modern C++, understanding what the Assembler does helps you debug hard-faults and understand the physical limitations of the CPU. The Assembler is the final bridge before your logic becomes electrical voltages.

## Prerequisites
- [02-compilation](../02-compilation/README.md)

## Learning Outcomes
1. Understand the 1-to-1 mapping between Assembly mnemonics and Machine Code.
2. Differentiate between Instruction sets (e.g., ARM Thumb-2 vs x86).
3. Understand why a compiled program for a PC cannot run on an STM32.
