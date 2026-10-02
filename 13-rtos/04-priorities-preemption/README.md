# Priorities & Preemption

## What is this topic?
This topic explores the dictatorship of the RTOS Scheduler. It covers **Priorities** and the concept of **Preemption**—how a high-priority task violently interrupts a low-priority task.

## Why is it important?
Assigning priorities incorrectly is the #1 cause of RTOS failures. If you give a heavy math task the highest priority, your RTOS devolves into a Bare-Metal system, starving all other tasks and defeating the purpose of the OS entirely.

## Prerequisites
- [02-task-scheduling](../02-task-scheduling/README.md)
- [03-context-switching](../03-context-switching/README.md)

## Learning Outcomes
1. Understand the golden rule of RTOS Priorities.
2. Define Task Starvation and how to prevent it.
3. Architect a system by assigning priorities based on "Deadline constraints" (Rate Monotonic Scheduling).
