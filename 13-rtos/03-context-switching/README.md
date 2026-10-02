# Context Switching

## What is this topic?
This topic dives into the low-level assembly magic of the RTOS: **The Context Switch**. It explains exactly *how* the RTOS physically pauses one `while(1)` loop and resumes another without corrupting variables.

## Why is it important?
To truly master an RTOS, you must understand the CPU Registers and the RAM Stack. When you realize that the RTOS is just saving and restoring CPU registers, debugging "Stack Overflows" and Hard Faults becomes significantly easier.

## Prerequisites
- [02-task-scheduling](../02-task-scheduling/README.md)
- [06-stack-vs-heap](../../05-memory/06-stack-vs-heap/README.md)

## Learning Outcomes
1. Define what a "Context" is (CPU Registers).
2. Trace the step-by-step process of a Context Switch (Save to Stack, Restore from Stack).
3. Understand why every RTOS Task requires its own dedicated RAM Stack.
