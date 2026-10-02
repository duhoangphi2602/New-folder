# Stack Overflow

## What is this topic?
This topic examines **Stack Overflow**, the most common and devastating runtime crash in embedded systems, where the Stack grows too large and aggressively overwrites other memory segments.

## Why is it important?
On a PC, if your program causes a Stack Overflow (e.g., via infinite recursion), the Operating System's Memory Management Unit (MMU) catches the violation and safely terminates your program with a "Segmentation Fault". 
On a bare-metal Cortex-M microcontroller, there is usually no MMU. If the Stack overflows, it silently overwrites your global variables (`.data` and `.bss`). Your system won't crash immediately; it will continue running with corrupted data, causing drones to flip upside down, medical devices to administer wrong dosages, and robots to accelerate into walls. You must know how to prevent and detect this.

## Prerequisites
- [02-stack](../02-stack/README.md)
- [05-text-rodata-data-bss](../05-text-rodata-data-bss/README.md)

## Learning Outcomes
1. Visualize the physical memory layout that leads to a Stack Overflow.
2. Understand the silent corruption of the `.bss` and `.data` segments.
3. Learn standard industry techniques for detecting Stack Overflows (Watermarking/Canaries).
