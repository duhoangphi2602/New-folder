# Semihosting

## What is this topic?
This topic introduces **Semihosting**, an advanced ARM debugging feature that allows a microcontroller to print `printf` messages directly to your PC's IDE without needing a physical UART connection.

## Why is it important?
Sometimes you design a custom PCB and realize you forgot to route the UART pins, or you simply don't have a USB-to-Serial adapter handy. If you have an ST-Link or J-Link hardware debugger connected to the SWD (Serial Wire Debug) pins, Semihosting allows the debugger to "steal" the `printf` data from the chip's RAM and display it on your laptop. It is a powerful backup tool, but it comes with massive performance penalties.

## Prerequisites
- [06-printf-redirect-uart](../06-printf-redirect-uart/README.md)

## Learning Outcomes
1. Understand the architectural magic behind Semihosting.
2. Understand the severe performance penalty of halting the CPU.
3. Know when to use Semihosting vs UART.
