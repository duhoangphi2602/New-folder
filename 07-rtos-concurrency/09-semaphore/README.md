# Semaphore

## What is this topic?
This topic introduces the **Semaphore**, a signaling mechanism used in RTOS environments. While it looks very similar to a Mutex, its purpose is fundamentally different: Semaphores are used for *Synchronization* (signaling between Tasks/ISRs), whereas Mutexes are used for *Protection* (Mutual Exclusion).

## Why is it important?
Confusing a Mutex with a Binary Semaphore is the most common mistake junior embedded engineers make. Using a Mutex when you meant to use a Semaphore will cause priority inversion bugs and crash your ISRs. You must understand the philosophical and mechanical differences between them.

## Prerequisites
- [08-mutex](../08-mutex/README.md)
- [06-isr-buffer-pattern](../../08-interrupt-isr/06-isr-buffer-pattern/README.md)

## Learning Outcomes
1. Understand the difference between a Binary Semaphore and a Counting Semaphore.
2. Implement the standard "Deferred Interrupt" pattern using an ISR and a Semaphore.
3. Understand why Semaphores do not have Priority Inheritance.
