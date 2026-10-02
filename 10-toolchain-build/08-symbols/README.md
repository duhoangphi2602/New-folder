# Symbols (nm and readelf)

## What is this topic?
This topic dives deeper into **Symbols**, the currency of the Linker. It explains how to inspect the final `.elf` file to find exactly where variables and functions were placed in physical memory.

## Why is it important?
Sometimes a program crashes, and the debugger gives you nothing but a raw memory address (e.g., "Hard Fault at `0x0800104A`"). By understanding how to read the final Symbol Table, you can manually reverse-engineer that raw address back to the exact C++ function that caused the crash.

## Prerequisites
- [04-object-files](../04-object-files/README.md)
- [06-elf](../06-elf/README.md)

## Learning Outcomes
1. Use `nm` to dump the final Symbol Table of an `.elf` file.
2. Filter and search the Symbol Table to find variable addresses.
3. Understand how C++ Name Mangling affects symbols.
