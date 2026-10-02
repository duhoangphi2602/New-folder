# ELF Format (Executable and Linkable Format)

## What is this topic?
This topic analyzes the `.elf` file, the primary output of the Linker in embedded Linux and ARM Cortex-M toolchains. 

## Why is it important?
You cannot directly flash an ELF file into a microcontroller's ROM. However, the ELF file is the most important file in your build directory. It contains not just the machine code, but also a massive wealth of debugging metadata. Without the ELF file, GDB (the GNU Debugger) cannot function.

## Prerequisites
- [05-linking](../05-linking/README.md)

## Learning Outcomes
1. Understand the internal structure of an ELF file (Headers, Sections, Debug Symbols).
2. Explain why an ELF file is much larger than the physical Flash memory of the microcontroller.
3. Use the `readelf` command to inspect ELF headers.
