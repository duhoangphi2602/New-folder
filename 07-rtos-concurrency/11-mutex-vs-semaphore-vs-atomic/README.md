# Mutex vs Semaphore vs Atomic

## What is this topic?
This topic acts as the ultimate cheat sheet for RTOS synchronization. It provides clear, strict rules on when to use Mutexes, Semaphores, Critical Sections, and Atomics. 

## Why is it important?
Applying the wrong concurrency mechanism is the #1 cause of firmware crashes. If you use a Mutex in an ISR, the system Hard Faults. If you use a Critical Section to wait for an I2C bus, the system freezes. You must memorize these architectural boundaries.

## Prerequisites
- [07-critical-section](../07-critical-section/README.md)
- [08-mutex](../08-mutex/README.md)
- [09-semaphore](../09-semaphore/README.md)
- [10-atomic](../10-atomic/README.md)

## Learning Outcomes
1. Master the decision matrix for choosing a concurrency tool.
2. Understand the strict boundaries between Task-to-Task and ISR-to-Task communication.
