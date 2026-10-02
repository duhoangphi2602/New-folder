# Interview Questions: Race Conditions

## 1. Define a "Race Condition" in the context of an RTOS.
**Answer:** A Race Condition is a software flaw where the final state of shared memory depends on the non-deterministic timing of the OS Scheduler. It occurs when multiple execution contexts (Tasks or ISRs) attempt to read, modify, and write to a shared memory location simultaneously without any synchronization mechanisms, resulting in the CPU instructions interleaving and corrupting the data.

## 2. Why doesn't increasing the RTOS SysTick rate (e.g., from 1ms to 0.1ms) fix a Race Condition?
**Answer:** Increasing the tick rate actually makes Race Conditions *more* likely to occur, not less. A Race Condition happens when a preemption (Context Switch) interrupts an active read-modify-write operation. If you increase the SysTick rate, you are forcing the Scheduler to preempt tasks 10 times more frequently, mathematically increasing the probability that it will interrupt a task exactly in the middle of modifying a shared variable.

## 3. What is the difference between a Race Condition and a Memory Leak?
**Answer:** A Memory Leak occurs when dynamically allocated memory (`malloc`/`new`) is not freed, causing the system to slowly run out of available RAM over time. It is a slow, deterministic failure. A Race Condition is a concurrency bug where memory values are instantly overwritten and corrupted due to timing overlaps. It is an instant, non-deterministic failure.
