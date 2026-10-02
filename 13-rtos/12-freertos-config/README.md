# FreeRTOS Config

## What is this topic?
This topic explores `FreeRTOSConfig.h`, the central configuration header file used to tailor the FreeRTOS Kernel to your specific hardware constraints and application needs.

## Why is it important?
FreeRTOS is designed to run on everything from an 8-bit AVR with 2KB of RAM to a 32-bit ARM Cortex-M7 with 1MB of RAM. The Kernel cannot guess your hardware limits. By tweaking `FreeRTOSConfig.h`, you can disable unused features to save RAM, change the Scheduler's Tick Rate, and enable critical debugging tools like Stack Overflow checking.

## Prerequisites
- [01-bare-metal-vs-rtos](../01-bare-metal-vs-rtos/README.md)
- [02-task-scheduling](../02-task-scheduling/README.md)

## Learning Outcomes
1. Understand how to configure the RTOS Tick Rate (`configTICK_RATE_HZ`).
2. Manage FreeRTOS Heap memory configuration (`configTOTAL_HEAP_SIZE`).
3. Enable Kernel debugging features (`configCHECK_FOR_STACK_OVERFLOW`).
