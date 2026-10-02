# The Scheduler

## What is this topic?
This topic explores the **Scheduler**, the central "brain" of the Real-Time Operating System. It determines exactly which Task gets to use the CPU at any given microsecond.

## Why is it important?
Writing RTOS code without understanding the Scheduler is like driving a car blindfolded. If you do not understand the rules the Scheduler uses to pick the next Task (Preemption and Priorities), you will write code that causes lower-priority tasks to starve, or high-priority tasks to miss critical hardware deadlines.

## Prerequisites
- [03-rtos-task](../03-rtos-task/README.md)

## Learning Outcomes
1. Understand the difference between Preemptive and Cooperative scheduling.
2. Trace the 4 states of an RTOS Task (Running, Ready, Blocked, Suspended).
3. Understand the role of the Hardware SysTick Timer in driving the Scheduler.
