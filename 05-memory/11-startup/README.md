# The Startup Code

## What is this topic?
This topic explores the **Startup Code**, the very first piece of software (usually written in Assembly) that executes when a microcontroller turns on, *before* your `main()` function is ever called.

## Why is it important?
Beginners often think `main()` is the starting point of a program. It is not. When a microcontroller boots, its RAM is completely full of random, corrupted garbage data. If the CPU jumped straight to `main()`, any attempt to read a global variable would result in garbage. The Startup Code is responsible for meticulously preparing the hardware and RAM so that the C/C++ environment is safe for `main()` to execute.

## Prerequisites
- [05-text-rodata-data-bss](../05-text-rodata-data-bss/README.md)
- [02-stack](../02-stack/README.md)

## Learning Outcomes
1. Understand the sequence of events from Power-On to `main()`.
2. Learn how the `.data` segment is copied from Flash to RAM.
3. Learn how the `.bss` segment is zeroed out in RAM.
4. Understand how static C++ object constructors are called before `main()`.
