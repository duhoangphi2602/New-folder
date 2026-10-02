# The Linker Script (.ld)

## What is this topic?
This topic explores the **Linker Script**, the blueprint that the Linker uses to map the abstract `.text` and `.data` sections into absolute physical memory addresses (Flash and RAM).

## Why is it important?
When you buy an STM32, the datasheet tells you Flash starts at `0x08000000` and RAM starts at `0x20000000`. But the C++ Compiler doesn't read datasheets. It has no idea what physical chip you are using. The Linker Script is the *only* place in your entire software architecture where hardware memory constraints are defined.

## Prerequisites
- [13-linker-script](../../05-memory/13-linker-script/README.md) (Cross-reference to the Memory chapter)
- [05-linking](../05-linking/README.md)

## Learning Outcomes
1. Define the `MEMORY` block and `SECTIONS` block in a `.ld` file.
2. Understand the difference between VMA (Virtual Memory Address) and LMA (Load Memory Address).
3. Export Linker Script symbols (like `_sdata`) to C/C++ code.
