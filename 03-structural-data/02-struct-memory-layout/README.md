# Struct Memory Layout

## What is this topic?
This topic explores how a C/C++ compiler maps the members of a struct into physical memory bytes.

## Why is it important?
When you define a struct with three `uint8_t` variables and one `uint32_t` variable, you might logically assume the struct takes up exactly 7 bytes. However, you will often find that `sizeof(MyStruct)` returns 8, 12, or even 16 bytes! Understanding how compilers secretly insert "invisible" padding bytes between your variables is critical for minimizing RAM usage and ensuring structs map perfectly to hardware registers or network packets.

## Prerequisites
- [01-struct](../01-struct/README.md)
- [13-alignment](../../02-pointers-arrays/13-alignment/README.md)

## Learning Outcomes
1. Visualize how struct members are laid out contiguously in memory.
2. Understand that the order of declaration determines the order in memory.
3. Observe how the compiler calculates the total size of a struct.
