# Semaphores

## What is this topic?
This topic introduces the **Semaphore**, a synchronization mechanism used in RTOS to signal events between Tasks, or critically, between a hardware Interrupt (ISR) and a Task.

## Why is it important?
While a Mutex is used for *protection* (a key to a bathroom), a Semaphore is used for *signaling* (a starting pistol for a race). Understanding this difference is crucial. Semaphores allow you to write interrupt handlers (ISRs) that take exactly 1 microsecond to execute, deferring all the heavy lifting to a background RTOS task.

## Prerequisites
- [05-mutexes](../05-mutexes/README.md)
- [05-dma](../../11-embedded-peripherals/05-dma/README.md)

## Learning Outcomes
1. Understand the difference between a Binary Semaphore and a Counting Semaphore.
2. Differentiate a Semaphore from a Mutex (Signaling vs Protection).
3. Architect an ISR-to-Task synchronization system using `FromISR` API calls.
