# RTOS Task

## What is this topic?
This topic introduces the structural foundation of a Real-Time Operating System: **The Task**. It explains how to create multiple independent, infinite loops that appear to run simultaneously on a single CPU core.

## Why is it important?
In bare-metal, everything lives inside one giant `while(1)` loop in `main()`. In an RTOS, you break your program into multiple isolated "miniature `main()` functions" called Tasks. Understanding how Tasks are created, prioritized, and given memory is the absolute prerequisite to using an RTOS effectively.

## Prerequisites
- [01-process-thread-task](../01-process-thread-task/README.md)
- [02-bare-metal](../02-bare-metal/README.md)

## Learning Outcomes
1. Learn the syntax and structure of an RTOS Task (using FreeRTOS as the model).
2. Understand the three critical arguments for task creation: Function Pointer, Stack Size, and Priority.
3. Understand the concept of the Task Control Block (TCB).
