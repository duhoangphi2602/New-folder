# The NVIC (Nested Vectored Interrupt Controller)

## What is this topic?
This topic explores the **NVIC**, the dedicated hardware subsystem inside ARM Cortex-M processors that acts as the "traffic cop" for all interrupts. 

## Why is it important?
When two hardware events occur at exactly the same microsecond (e.g., a Timer fires and a UART byte arrives), which ISR does the CPU run first? What happens if an interrupt fires *while* you are already inside an ISR? The NVIC handles these chaotic situations. Understanding the NVIC is critical to preventing your most important hardware signals from being ignored.

## Prerequisites
- [01-interrupt-concept](../01-interrupt-concept/README.md)

## Learning Outcomes
1. Understand the purpose and function of the NVIC in ARM Cortex-M.
2. Define "Nested" interrupts and Interrupt Priorities.
3. Distinguish between Hardware Priorities (NVIC) and Software Priorities (RTOS Tasks).
