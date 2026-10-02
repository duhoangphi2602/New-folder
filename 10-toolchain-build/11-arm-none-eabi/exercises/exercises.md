# Exercises: arm-none-eabi

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Wrong Compiler
You buy a Raspberry Pi Pico (which has an ARM Cortex-M0+ bare-metal microcontroller). 
You download a toolchain online. The binary is named `arm-linux-gnueabihf-gcc`. 
You successfully compile a simple "Blink LED" program with it. 
**Task:** When you flash this binary to the Pico, will it work? Explain what the compiler assumed about your hardware, and why it will crash.

## Exercise 2: ABI Mismatch
You find a cool pre-compiled static library online (`libmath_fast.a`). The author compiled it using `arm-none-eabi-gcc`.
Your project is heavily focused on decimal math, so you configured your project to build using the `arm-none-eabihf-gcc` (Hard Float) compiler to utilize the hardware FPU.
**Task:** When you try to link the pre-compiled `libmath_fast.a` into your project, the Linker throws a massive error complaining about an "ABI Mismatch" or "incompatible float-ABI". Why? What is happening at the register level?
