# Priority Inversion

## What is this topic?
This topic covers **Priority Inversion**, the most famous and dangerous bug in Real-Time Operating Systems. It famously caused the near-loss of NASA's Mars Pathfinder rover in 1997.

## Why is it important?
When you mix Task Priorities (High vs Low) with Mutexes (Locks), you create a fatal vulnerability. A medium-priority task can accidentally hijack the CPU and indefinitely starve the highest-priority task in the system. Understanding how this happens, and how to fix it with Priority Inheritance, is a hallmark of a Senior RTOS Engineer.

## Prerequisites
- [04-priorities-preemption](../04-priorities-preemption/README.md)
- [05-mutexes](../05-mutexes/README.md)

## Learning Outcomes
1. Trace the exact sequence of events that causes a Priority Inversion.
2. Understand why a Medium Priority task is the actual culprit.
3. Explain how Priority Inheritance Mutexes mathematically solve the problem.
