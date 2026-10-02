# Event Groups

## What is this topic?
This topic introduces **Event Groups**, a powerful RTOS synchronization mechanism used to wait for *multiple* conditions to be met before a task is allowed to execute.

## Why is it important?
A Semaphore lets a task wait for one event (e.g., "Wait for the Button"). But what if a task needs to wait for three events? (e.g., "Wait until WiFi is connected AND the GPS has a fix AND the SD card is initialized"). If you try to use three separate Semaphores, you will easily create system-halting Deadlocks. Event Groups solve this perfectly using bitwise flags.

## Prerequisites
- [03-structural-data](../../03-structural-data/README.md) (Bitwise Operations)
- [06-semaphores](../06-semaphores/README.md)

## Learning Outcomes
1. Define what an Event Group is (a 24-bit integer of boolean flags).
2. Use an Event Group to synchronize multiple producer tasks with a single consumer task.
3. Understand the difference between "Wait for ANY" and "Wait for ALL" conditions.
