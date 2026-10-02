# RTOS ISR APIs (`...FromISR`)

## What is this topic?
This topic explains the strict architectural split in FreeRTOS between standard APIs (used inside Tasks) and ISR APIs (used inside Hardware Interrupts). 

## Why is it important?
If you accidentally call a standard RTOS function like `xQueueSend()` inside an ISR, your microcontroller will crash with a Hard Fault. You must understand *why* the RTOS provides special `...FromISR()` variants, and the mechanical difference in how they interact with the Scheduler.

## Prerequisites
- [03-isr-best-practices](../03-isr-best-practices/README.md)
- [04-scheduler](../../07-rtos-concurrency/04-scheduler/README.md)

## Learning Outcomes
1. Understand why standard RTOS APIs are lethal inside an ISR.
2. Use FreeRTOS `...FromISR` APIs correctly.
3. Understand the role of `pxHigherPriorityTaskWoken` in manually triggering a Context Switch from an ISR.
