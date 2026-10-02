# Deadlock

## What is this topic?
This topic explores the **Deadlock**, a fatal architectural flaw where two or more Tasks become permanently blocked, waiting endlessly for resources held by each other. 

## Why is it important?
A Deadlock does not trigger a Hard Fault. It does not crash the memory. It is a completely silent failure. The OS Scheduler continues to run perfectly, but your critical tasks never wake up again. Preventing deadlocks requires strict architectural discipline.

## Prerequisites
- [08-mutex](../08-mutex/README.md)
- [04-scheduler](../04-scheduler/README.md)

## Learning Outcomes
1. Understand the exact sequence of events that creates a classic "Deadly Embrace".
2. Identify the 4 Coffman Conditions required for a deadlock to exist.
3. Apply architectural patterns (Lock Ordering) to mathematically prevent deadlocks.
