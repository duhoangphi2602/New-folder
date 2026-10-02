# Mutex (Mutual Exclusion)

## What is this topic?
This topic covers the **Mutex**, the standard mechanism for preventing Race Conditions between multiple RTOS Tasks without destroying system latency (like a Critical Section does).

## Why is it important?
When two tasks need to share an I2C bus or a global variable, they must take turns. A Mutex acts as a "key" to a locked door. If Task A has the key, Task B must wait outside until Task A is finished and returns the key. Understanding Mutexes is mandatory for multithreaded architecture.

## Prerequisites
- [06-race-condition](../06-race-condition/README.md)
- [07-critical-section](../07-critical-section/README.md)

## Learning Outcomes
1. Understand the "Token" analogy of a Mutex.
2. Implement Mutex protection using FreeRTOS and C++ `std::lock_guard`.
3. Understand the state transitions of a Task blocked on a Mutex.
