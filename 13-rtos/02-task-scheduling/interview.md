# Interview Questions: Task Scheduling

## 1. What triggers the RTOS Scheduler to evaluate which task should run?
**Answer:** The RTOS Scheduler is fundamentally driven by a hardware timer interrupt, almost universally the **SysTick** timer on ARM Cortex-M processors. This timer is configured by the OS to fire an interrupt at a specific interval (the Tick Rate, usually every 1 millisecond). Every time the SysTick interrupt fires, the CPU execution jumps into the RTOS Kernel code, allowing the Scheduler to update Blocked timers, check the Ready List, and decide if a Context Switch (Preemption or Round-Robin) is required.

## 2. Differentiate between a Task in the "Ready" state and a Task in the "Blocked" state.
**Answer:** 
- A **Ready** task wants to execute immediately. It has all the data it needs, but it is currently waiting in the Ready List because a higher-priority task (or an equal-priority task taking its time-slice) currently holds the physical CPU in the "Running" state.
- A **Blocked** task is intentionally asleep. It has called an OS API function (like `vTaskDelay` or `xQueueReceive`) indicating it is waiting for time to pass or an event to occur. The Scheduler completely ignores tasks in the Blocked state when deciding who gets the CPU next, which makes RTOS extremely efficient.

## 3. If two Tasks, Task A and Task B, are both assigned Priority 2, and no other tasks exist, how does a Preemptive FreeRTOS scheduler handle them?
**Answer:** Because they have the exact same priority, the scheduler uses a concept called **Time Slicing** (or Round-Robin scheduling). Task A will be put into the Running state for exactly one SysTick interval (e.g., 1 millisecond). When the SysTick fires, the scheduler will forcibly pause Task A, put it back in the Ready List, and put Task B into the Running state for the next millisecond. The OS will alternate them back and forth indefinitely, giving each exactly 50% of the CPU time in 1ms chunks.
