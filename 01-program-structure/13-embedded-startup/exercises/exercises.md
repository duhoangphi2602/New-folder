# Exercises: Embedded Startup

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Identifying Memory Sections
Consider the following global variables in a C++ firmware project:
```cpp
int system_status = 0;
int max_retries = 5;
int buffer[1024];
const int hardware_id = 0xAABBCCDD;
```
**Task:** Identify which section (`.data`, `.bss`, or `.rodata`) each variable belongs to. Explain what the Startup Code does (or doesn't do) for each of them.

## Exercise 2: The Missing Startup File
You are migrating a project from an STMicroelectronics HAL environment to a custom Make build system. You successfully compile all your `.c` and `.cpp` files into `.o` files, and the linker completes successfully, producing a `.bin` file. 
However, when you flash the MCU, absolutely nothing happens. You attach a debugger and see that the program counter (PC) is pointing to a completely random memory address like `0x200014B2`.
**Task:** Based on your knowledge of the Cortex-M boot sequence, what critical file did you forget to compile and link into your project? Why is the PC pointing to a random address?

## Exercise 3: Bootloader Interactions
You write a custom bootloader that lives at `0x08000000`. Its job is to verify a checksum, and then jump to the main application firmware which lives at `0x08040000`. 
**Task:** Before the bootloader can safely jump to the application's `Reset_Handler`, what two hardware pointers must it update or configure?
