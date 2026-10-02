# Bare-Metal vs RTOS

## What is this topic?
This topic explores the fundamental architectural shift from a **Bare-Metal Super Loop** to a **Real-Time Operating System (RTOS)**.

## Why is it important?
A `while(1)` Super Loop works perfectly for a microwave or a simple toy. But if you are building a smartwatch with a touchscreen, Bluetooth audio, and biometric sensors, a single loop cannot manage all those asynchronous events. An RTOS transforms your single-core microcontroller into a multi-tasking powerhouse, allowing you to write complex software that behaves as if it has multiple CPUs.

## Prerequisites
- [07-timers](../../11-embedded-peripherals/07-timers/README.md) (SysTick)
- [01-interrupt-vector-table](../../08-interrupt-isr/01-interrupt-vector-table/README.md)

## Learning Outcomes
1. Define the limits and drawbacks of the Bare-Metal Super Loop.
2. Define what an RTOS is and the concept of "Real-Time" (Determinism).
3. Understand how an RTOS allows multiple infinite loops to coexist.
