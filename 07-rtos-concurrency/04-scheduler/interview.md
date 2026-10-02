# Interview Questions: The Scheduler

## 1. Explain the difference between Preemptive and Cooperative scheduling.
**Answer:** In a Preemptive scheduler (like FreeRTOS or Linux), the OS uses a hardware timer to forcibly interrupt a running task, evaluate priorities, and switch context to a higher-priority task without the running task's permission. In a Cooperative scheduler, the OS cannot force a switch; the running task must manually call a "yield" function to hand control back to the OS. Cooperative is simpler and avoids race conditions, but a single buggy infinite loop will permanently freeze the entire device.

## 2. In FreeRTOS, if two tasks have the exact same Priority and neither ever Blocks, how does the Scheduler handle them?
**Answer:** FreeRTOS uses "Round-Robin Time-Slicing" for tasks of equal priority. Every time the SysTick interrupt fires (usually every 1 millisecond), the Scheduler will preempt the currently running task, place it at the back of the Ready Queue for that priority level, and start running the other task. The two tasks will evenly split the CPU, bouncing back and forth every 1 millisecond.

## 3. What does it mean for a task to be in the "Blocked" state, and why is it crucial for CPU efficiency?
**Answer:** A Blocked task is waiting for an event to occur (like a Timer elapsing, or a byte arriving on a UART Queue). The Scheduler completely removes this task from its "Ready to Run" list. When evaluating which task to run, the Scheduler wastes zero CPU cycles on Blocked tasks. This allows the CPU to immediately run lower-priority tasks, or drop into a low-power hardware Sleep mode (via the Idle Task), dramatically saving battery life compared to a bare-metal architecture that continuously polls hardware flags.
