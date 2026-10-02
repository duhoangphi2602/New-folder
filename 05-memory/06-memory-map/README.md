# The Memory Map

## What is this topic?
This topic explores the **Memory Map**, the architectural blueprint that defines exactly where Flash, RAM, and hardware peripherals are physically located within the 32-bit address space of a microcontroller.

## Why is it important?
In a 32-bit system, the CPU can point to `2^32` (4.2 Billion) different memory addresses (ranging from `0x00000000` to `0xFFFFFFFF`). The silicon designers assign specific meaning to specific address ranges. For example, addresses starting with `0x08` might point to Flash, `0x20` to RAM, and `0x40` to hardware peripherals (UART, GPIO). If you don't understand the Memory Map, you cannot write Linker Scripts or Memory-Mapped Register drivers.

## Prerequisites
- [01-memory-concepts](../01-memory-concepts/README.md)
- [14-memory-mapped-register](../../02-pointers-arrays/14-memory-mapped-register/README.md)

## Learning Outcomes
1. Understand the 4GB flat address space of a 32-bit CPU.
2. Read and interpret a silicon vendor's Memory Map datasheet.
3. Understand how Aliasing and Bit-Banding fit into the memory map.
