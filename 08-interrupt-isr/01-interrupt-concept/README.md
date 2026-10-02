# Interrupt Concept

## What is this topic?
This topic introduces the **Hardware Interrupt**, the fundamental mechanism that allows a microcontroller to react instantly to the outside physical world without wasting CPU power.

## Why is it important?
In a desktop environment (Python/C#), you rarely interact with hardware directly. In an embedded system, your software is physically wired to buttons, sensors, and motors. If you use a `while(1)` loop to constantly check if a button is pressed (Polling), you waste 100% of the CPU's battery and processing power. Interrupts solve this by letting the CPU sleep or do other work until the exact microsecond the hardware needs attention.

## Prerequisites
- [02-bare-metal](../../07-rtos-concurrency/02-bare-metal/README.md)
- [05-context-switch](../../07-rtos-concurrency/05-context-switch/README.md)

## Learning Outcomes
1. Differentiate between Polling and Interrupts.
2. Understand what an ISR (Interrupt Service Routine) is.
3. Trace the hardware execution sequence when an interrupt fires.
