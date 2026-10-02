# Task Scheduling & The SysTick

## 1. The SysTick Heartbeat
An RTOS is just software; it cannot magically take control of the CPU. It relies on a hardware interrupt.
When you start FreeRTOS (`vTaskStartScheduler()`), it configures the ARM Cortex-M **SysTick Timer** to fire a hardware interrupt exactly once every 1 millisecond (the standard "Tick Rate", 1000 Hz).
Every single millisecond, the CPU is forced to pause the current Task, jump into the RTOS Kernel (the ISR), and evaluate: *"Should the current Task keep running, or should I give the CPU to a different Task?"*

## 2. The 4 Task States
To make this decision, the Scheduler maintains lists of Tasks based on their State:
1. **Running:** The ONE task currently executing on the physical CPU.
2. **Ready:** Tasks that are perfectly ready to run right now, but are waiting in line because another task has the CPU.
3. **Blocked:** Tasks that are explicitly "Sleeping". (e.g., A task that called `vTaskDelay(100)`, or is waiting for UART data to arrive). The Scheduler *completely ignores* Blocked tasks, saving massive amounts of CPU time.
4. **Suspended:** Tasks that are essentially paused indefinitely (`vTaskSuspend()`). They will never run until explicitly resumed.

## 3. How the Scheduler Decides
Every millisecond (when the SysTick fires), the Scheduler looks at the **Ready List**.
- **Rule 1 (Priority):** The highest priority task in the Ready List gets the CPU. Always.
- **Rule 2 (Round-Robin):** If there are two tasks with the *exact same* highest priority in the Ready List, the Scheduler uses "Time Slicing" (Round-Robin). It gives Task A the CPU for 1ms. On the next SysTick, it kicks Task A out and gives the CPU to Task B for 1ms. It alternates them fairly.

## 4. Preemptive vs Cooperative
- **Cooperative (Old School):** The RTOS will not take the CPU away from a Task unless the Task willingly calls an OS function (like `vTaskDelay`). If a task runs a long math calculation, it hogs the system.
- **Preemptive (Modern FreeRTOS):** The RTOS acts as a dictator. If Task A (Low Priority) is doing math, and a SysTick occurs where Task B (High Priority) suddenly wakes up from a Blocked state, the RTOS will violently pause Task A mid-calculation and give the CPU to Task B. This is called **Preemption**, and it guarantees Real-Time responsiveness.

## 5. Example
*(See `examples/` for a timeline visualization of the Scheduler).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
