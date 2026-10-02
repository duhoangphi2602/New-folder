# Critical Section

## What is this topic?
This topic introduces the most brutal, absolute method of preventing Race Conditions: **The Critical Section**. It solves concurrency by physically turning off the CPU's ability to be interrupted.

## Why is it important?
While Mutexes are the standard way to protect memory between two Tasks, Mutexes *cannot* be used inside Hardware Interrupts (ISRs). If an ISR and a Task need to share data, a Critical Section is the *only* software-based way to guarantee memory safety.

## Prerequisites
- [06-race-condition](../06-race-condition/README.md)
- [08-interrupt-isr](../../08-interrupt-isr/01-interrupt-concept/README.md) (Concept of Interrupts)

## Learning Outcomes
1. Define a Critical Section in an RTOS context.
2. Implement Critical Sections using FreeRTOS macros (`taskENTER_CRITICAL`).
3. Understand why Critical Sections destroy System Latency.
