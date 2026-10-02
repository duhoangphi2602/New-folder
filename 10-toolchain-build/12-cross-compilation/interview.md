# Interview Questions: Cross Compilation

## 1. What is Cross-Compilation, and why is it mandatory for bare-metal embedded systems?
**Answer:** Cross-compilation is the process of using a compiler on one architecture (The Host, e.g., an x86_64 Windows PC) to generate executable machine code for a completely different architecture (The Target, e.g., an ARM Cortex-M microcontroller). It is mandatory because microcontrollers lack the RAM, CPU power, and operating system required to run a massive, resource-heavy compiler like GCC locally. 

## 2. You type `arm-none-eabi-gcc` in your Windows command prompt, and it runs successfully. Is the `arm-none-eabi-gcc.exe` file on your hard drive an ARM program or an x86 program?
**Answer:** It is an x86 program! This is a common point of confusion. The cross-compiler itself is a standard Windows executable designed to run on the Intel/AMD hardware inside your PC. It is the *output* of the compiler (the generated `.o` and `.bin` files) that contains the ARM machine code.

## 3. Why can't you easily use `printf` or `malloc` out of the box on a bare-metal microcontroller?
**Answer:** Standard C libraries on desktop PCs (like `glibc`) rely entirely on the Operating System to function. `printf` uses OS System Calls to write to the console screen. `malloc` asks the OS Kernel to dynamically map virtual memory pages. In a bare-metal system, there is no OS to ask. The cross-compiler uses an embedded standard library (like `newlib`), which provides the logic for `printf`, but it leaves the final hardware step blank. The developer must manually "retarget" the library by writing low-level drivers (e.g., overriding the `_write` function to send bytes over a UART serial port instead of a screen).
