# The Scheduler

## 1. Concept
A CPU core can only execute **one instruction at a time**. It cannot run two tasks simultaneously. 
The Scheduler is a piece of RTOS software that rapidly switches the CPU between tasks, giving the *illusion* of simultaneous execution. 

## 2. Preemptive vs Cooperative
There are two main styles of Schedulers:
1. **Cooperative:** A task keeps the CPU until it voluntarily decides to give it up (by calling a `yield` function). This is dangerous because a bad task can freeze the system.
2. **Preemptive (FreeRTOS Default):** The Scheduler acts as a dictator. It has the power to forcibly pause (preempt) a running task at any moment to give the CPU to a higher-priority task.

## 3. The Hardware SysTick
How does a Preemptive Scheduler force a task to pause? 
The RTOS configures a hardware timer (the `SysTick` timer on ARM Cortex-M) to generate a hardware interrupt every 1 millisecond. 
When the interrupt fires, the CPU is forced to pause the current task and jump to the Scheduler's ISR. The Scheduler looks at the list of all Tasks and says: *"Who is the highest priority task that is ready to run?"* It then switches the CPU to that task.

## 4. The 4 Task States
To make decisions, the Scheduler tracks every task through a State Machine:
1. **RUNNING:** The task that currently owns the CPU. (Only 1 task can be Running per core).
2. **READY:** The task wants to run, but a higher-priority task is currently Running.
3. **BLOCKED:** The task is sleeping (`vTaskDelay`) or waiting for data (reading an empty Queue). It is completely ignored by the Scheduler, consuming 0 CPU cycles.
4. **SUSPENDED:** The task is explicitly frozen by the developer (`vTaskSuspend`).

## 5. FreeRTOS Scheduling Algorithm
The standard FreeRTOS algorithm is elegantly simple:
**Always run the highest-priority task that is in the READY state.**
- If Task A (Priority 5) is READY, and Task B (Priority 1) is RUNNING... The Scheduler instantly preempts B and runs A.
- If two tasks have the exact same priority, the Scheduler uses **Time-Slicing**: It runs Task A for 1 millisecond, then Task B for 1 millisecond, bouncing back and forth evenly.

## 6. Example
*(See `examples/` for a C++ simulated scheduler state machine).*

## 7. Trade-offs (Latency vs Throughput)
Preemptive scheduling provides incredibly low latency (a high-priority task responds to an event almost instantly). However, preempting a task requires saving all its CPU registers to RAM, which takes time. If the SysTick fires too fast (e.g., 100,000 times a second), the CPU will spend 90% of its time just saving and restoring registers (Context Switching) and only 10% of its time doing actual work. (Usually, the SysTick is set to 1000 Hz).

## 8. Exercises
Please proceed to the `exercises/` folder.

## 9. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
