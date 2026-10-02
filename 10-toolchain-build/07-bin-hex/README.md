# Binary and Hex Files (.bin / .hex)

## What is this topic?
This topic explains how to extract the raw, flashable machine code payload from an `.elf` file using `objcopy`, resulting in `.bin` or `.hex` files.

## Why is it important?
While intelligent debuggers (like OpenOCD) can parse an ELF file directly, many factory programming tools, bootloaders, and Over-The-Air (OTA) update systems require raw memory images. Understanding the difference between a raw Binary file and an Intel Hex file is critical for firmware deployment.

## Prerequisites
- [06-elf](../06-elf/README.md)

## Learning Outcomes
1. Use `objcopy` to strip metadata from an ELF file.
2. Differentiate between `.bin` (raw binary) and `.hex` (ASCII representation).
3. Understand why a `.hex` file is roughly 2.5x larger than a `.bin` file.
