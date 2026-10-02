# Embedded Startup

## What is this topic?
This topic explores the **Startup Sequence**, the critical bridge between the moment a microcontroller receives electrical power and the moment the C++ `main()` function is executed.

## Why is it important?
Without an operating system, the C/C++ environment does not exist by magic. The CPU needs RAM to be mapped, global variables to be populated with their initial values, and the stack pointer to be set. A deep understanding of the startup code is required to debug hard faults, optimize boot times, and write linker scripts.

## Prerequisites
- [12-main-and-program-entry](../12-main-and-program-entry/README.md)
- [05-memory/13-linker-script](../../05-memory/13-linker-script/README.md) (Optional but highly recommended)

## Learning Outcomes
1. Trace the boot sequence of an ARM Cortex-M microcontroller.
2. Understand exactly why `.data` is copied and `.bss` is zeroed.
3. Learn how startup code bridges the gap between hardware (Reset Vector) and C/C++ logic.
