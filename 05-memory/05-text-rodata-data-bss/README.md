# Memory Segments (.text, .rodata, .data, .bss)

## What is this topic?
This topic pulls back the curtain on how a C++ compiler categorizes every single line of code and every variable you write into four specific "Memory Segments": `.text`, `.rodata`, `.data`, and `.bss`.

## Why is it important?
When you compile your embedded project, the compiler generates a `.bin` or `.elf` file. You need to know exactly how much RAM and how much Flash your program will consume. By understanding these four segments, you can look at a Linker Map file and immediately identify why your program is out of RAM (e.g., "Ah, my `.bss` section is 30KB because of that massive uninitialized array").

## Prerequisites
- [01-memory-concepts](../01-memory-concepts/README.md)
- [04-static-storage](../04-static-storage/README.md)

## Learning Outcomes
1. Learn the exact contents of the `.text` and `.rodata` (Flash) segments.
2. Learn the exact contents of the `.data` and `.bss` (RAM) segments.
3. Understand the "BSS zero-initialization" rule in standard C/C++.
