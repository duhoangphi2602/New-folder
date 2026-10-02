# Queues

## What is this topic?
This topic introduces the **Queue**, the primary Inter-Process Communication (IPC) mechanism in FreeRTOS used to safely move data (variables, arrays, structs) from one Task to another.

## Why is it important?
A Semaphore can tell a Task *that* an event happened, but it cannot tell the Task *what* the data is. You might be tempted to just use global variables (e.g., `global_temp = 25;`), but global variables are highly susceptible to Race Conditions. Queues act as thread-safe conveyor belts, allowing tasks to pass data safely without stepping on each other's toes.

## Prerequisites
- [03-structural-data](../../03-structural-data/README.md) (Structs)
- [05-mutexes](../05-mutexes/README.md) (Race Conditions)

## Learning Outcomes
1. Define FIFO (First-In, First-Out).
2. Understand Pass-by-Copy vs Pass-by-Reference in RTOS Queues.
3. Architect a Producer/Consumer system using Queues.
