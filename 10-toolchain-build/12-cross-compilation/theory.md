# Cross-Compilation

## 1. Native Compilation
When you build a standard desktop app, you use **Native Compilation**.
- **Host (Where the compiler runs):** Windows 11 PC (x86_64).
- **Target (Where the code runs):** Windows 11 PC (x86_64).
Because the Host and Target are the same, the compiler (`gcc`) automatically links the system libraries on your hard drive, assuming the target machine has exactly the same OS and hardware.

## 2. Cross Compilation
In embedded systems, the Host and Target are vastly different.
- **Host:** Windows 11 PC (x86_64).
- **Target:** STM32 Microcontroller (ARM Cortex-M4, Bare-metal).

If you used the native `gcc` compiler on Windows to build STM32 code, it would generate x86 machine code. If you somehow flashed that onto the STM32, the chip would crash instantly. 

A **Cross-Compiler** (like `arm-none-eabi-gcc`) is an executable program that is designed to run on the Host (it's a standard Windows `.exe` file), but it is programmed to translate C++ code into the Target's dictionary (ARM Machine Code).

## 3. Why cross-compile?
Why not just install GCC directly onto the STM32 and compile the code natively there?
- **Resources:** GCC requires hundreds of Megabytes of RAM to parse Abstract Syntax Trees and perform optimizations. The STM32 has 20 KB of RAM. It physically cannot run the compiler.
- **Speed:** A modern PC compiles code millions of times faster than a 16 MHz microcontroller.

## 4. The Standard Library Problem
The biggest issue in cross-compilation is the C/C++ Standard Library. 
If you write `#include <stdio.h>` and call `printf("Hello");`:
- On a PC, `printf` eventually calls a Windows/Linux OS system call to print to the screen.
- On a bare-metal microcontroller, there is no OS, no screen, and no system calls! 

The `arm-none-eabi` cross-compiler does NOT link your PC's standard library. It comes bundled with a highly optimized, custom library written specifically for microcontrollers (often called `newlib` or `newlib-nano`). This library provides a stripped-down `printf` that you must manually route to a UART hardware peripheral using a technique called "Retargeting".

## 5. Example
*(See `examples/` for a Host vs Target diagram).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
