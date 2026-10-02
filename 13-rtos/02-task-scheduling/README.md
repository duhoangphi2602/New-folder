# Task Scheduling & The SysTick

## What is this topic?
This topic explores the heart of the RTOS: The **Scheduler**. It explains how the RTOS decides which Task gets to use the CPU at any given millisecond.

## Why is it important?
To use an RTOS effectively, you must understand that your Tasks do not actually run at the same time. The CPU is a single-core machine. The Scheduler rapidly switches the CPU between tasks based on the "Tick Interrupt". If you don't understand how the Scheduler thinks, you will accidentally design tasks that starve other tasks, leading to system lockups.

## Prerequisites
- [01-bare-metal-vs-rtos](../01-bare-metal-vs-rtos/README.md)
- [07-timers](../../11-embedded-peripherals/07-timers/README.md)

## Learning Outcomes
1. Define the 4 states of an RTOS Task (Running, Ready, Blocked, Suspended).
2. Understand the role of the SysTick hardware timer in driving the Scheduler.
3. Contrast Preemptive Scheduling vs Cooperative (Round-Robin) Scheduling.
