# Volatile vs Atomic

## What is this topic?
This topic addresses the most common and dangerous misconception in embedded systems programming: the false belief that the `volatile` keyword makes a variable thread-safe.

## Why is it important?
Thousands of embedded systems crash randomly in production because developers use `volatile int counter;` to share data between an ISR and a main task, assuming `volatile` protects against Data Races. It does not. Understanding the distinct difference between **Compiler optimization boundaries (`volatile`)** and **CPU execution boundaries (`atomic`)** is critical to writing stable firmware.

## Prerequisites
- [01-volatile](../01-volatile/README.md)
- [06-race-condition](../../07-rtos-concurrency/06-race-condition/README.md)

## Learning Outcomes
1. Clearly differentiate the problem solved by `volatile` (Compiler) vs `atomic` (Hardware).
2. Trace a Race Condition on a `volatile` variable at the Assembly level.
3. Determine when to use `volatile` alone, `atomic` alone, or both together.
