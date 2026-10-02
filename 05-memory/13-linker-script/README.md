# The Linker Script

## What is this topic?
This topic demystifies the **Linker Script** (`.ld` file), the powerful configuration file that tells the compiler exactly how to map the software's memory segments (`.text`, `.data`, `.bss`) onto the physical hardware's Memory Map.

## Why is it important?
When you compile `main.cpp`, the compiler just generates a generic chunk of assembly code. It has no idea if the microcontroller has 16KB of RAM or 1MB of RAM, or what address the Flash starts at. The Linker Script provides this physical hardware map to the Linker. If you want to allocate a specific region of RAM for a DMA buffer, or partition your Flash to write a Custom Bootloader, you *must* know how to edit the Linker Script.

## Prerequisites
- [05-text-rodata-data-bss](../05-text-rodata-data-bss/README.md)
- [06-memory-map](../06-memory-map/README.md)

## Learning Outcomes
1. Understand the `MEMORY` block and how it defines physical boundaries.
2. Understand the `SECTIONS` block and how it maps software segments to hardware regions.
3. Learn how the Linker Script provides `_sdata` and `_edata` variables to the Startup Code.
