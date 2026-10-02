# Exercises: Assembly

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Cross-Compilation
A developer on a Windows PC (Intel x86 processor) writes a C++ program for an STM32 microcontroller (ARM Cortex-M processor). 
They use the standard `g++` command on their PC to compile the code. The compiler generates an executable `.exe` file. They try to flash this file onto the STM32, but the microcontroller does absolutely nothing.
**Task:** Why did the microcontroller fail to run the code? What specific toolchain tool (e.g., what prefix) must the developer use instead of `g++`?

## Exercise 2: Disassembly
You lost the source code for an old project, but you still have the final `.bin` file containing the raw hex bytes: `0C 20 08 44 70 47`.
**Task:** Can you completely reconstruct the original C++ code (e.g., variable names, `for` loops) from this binary file? Can you reconstruct the Assembly code? Explain the difference.
