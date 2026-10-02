# Deadlocks

## What is this topic?
This topic covers **Deadlocks**, the most notorious and difficult-to-debug architectural flaw in concurrent programming, where two or more tasks permanently freeze each other.

## Why is it important?
Unlike a Hard Fault (which crashes the system instantly and leaves a stack trace), a Deadlock is silent. The RTOS Scheduler continues to run perfectly, hardware interrupts continue to fire, but your application tasks are frozen forever. Understanding the mathematical conditions that cause a Deadlock is the only way to architect a system that prevents them.

## Prerequisites
- [05-mutexes](../05-mutexes/README.md)
- [04-priorities-preemption](../04-priorities-preemption/README.md)

## Learning Outcomes
1. Define a Deadlock (The Deadly Embrace).
2. Understand the "Circular Wait" condition required for a Deadlock.
3. Apply architectural rules to guarantee a Deadlock can never occur.
