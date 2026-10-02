# Mutexes (Mutual Exclusion)

## What is this topic?
This topic introduces the **Mutex**, the fundamental RTOS tool used to protect shared hardware and variables from being corrupted when multiple tasks try to access them simultaneously.

## Why is it important?
Preemption is dangerous. If a low-priority task is halfway through writing a 20-character string to the UART console, and a high-priority task preempts it and starts writing its own string to the UART, the text on the console will be a corrupted, interleaved mess. Mutexes act as a "lock and key" to prevent these collisions.

## Prerequisites
- [04-priorities-preemption](../04-priorities-preemption/README.md)

## Learning Outcomes
1. Define a "Race Condition" and a "Critical Section".
2. Understand how a Mutex acts as a physical key to shared resources.
3. Differentiate between a Mutex and a standard boolean flag.
