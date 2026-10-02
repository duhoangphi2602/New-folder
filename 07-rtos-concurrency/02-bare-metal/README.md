# Bare-Metal Programming (The Super Loop)

## What is this topic?
This topic explains the "Bare-Metal" architecture, also known as the **Super Loop**. This is how microcontrollers operate before an RTOS is introduced, where your `main()` function contains a single, infinite `while(1)` loop that sequentially processes all tasks.

## Why is it important?
Not every embedded project needs an RTOS. Adding FreeRTOS consumes around 4KB of Flash and requires a few kilobytes of RAM for Stacks. For extremely simple, low-cost microcontrollers (like an 8-bit AVR or a tiny Cortex-M0 doing a single task), a Bare-Metal Super Loop is often the best, simplest, and most efficient architecture. You must know when to use it and when it breaks down.

## Prerequisites
- [12-main-and-program-entry](../../01-program-structure/12-main-and-program-entry/README.md)
- [06-isr-buffer-pattern](../../08-interrupt-isr/06-isr-buffer-pattern/README.md)

## Learning Outcomes
1. Implement a standard Bare-Metal Super Loop.
2. Understand the crippling latency issues caused by blocking functions (`delay_ms`).
3. Transition from blocking code to state-machine based non-blocking code.
