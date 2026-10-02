# Interview Questions: Deadlock

## 1. What are the 4 Coffman Conditions for a Deadlock?
**Answer:** 
1. **Mutual Exclusion:** Resources are unshareable (only one task can hold the Mutex).
2. **Hold and Wait:** A task holds at least one resource while waiting to acquire another.
3. **No Preemption:** Resources cannot be forcibly taken away by the OS.
4. **Circular Wait:** A closed chain of tasks exists where each is waiting for a resource held by the next.

## 2. How does "Strict Lock Ordering" prevent Deadlocks?
**Answer:** It breaks the "Circular Wait" condition. If all tasks in a firmware architecture are forced to acquire Mutexes in a strict, predefined global order (e.g., you must acquire Mutex 1 before Mutex 2, and Mutex 2 before Mutex 3), it is mathematically impossible for a cycle to form. Task B cannot wait for Task A's Mutex 1, because Task B would have been forced to request Mutex 1 before it ever acquired its own Mutex 2.

## 3. If a Deadlock occurs in an RTOS, will a standard Hardware Watchdog reset the system?
**Answer:** Often, no. A Deadlock simply puts the deadlocked tasks into a permanent "Blocked" state. The RTOS Scheduler itself is not frozen; it will continue to schedule and run any other Ready tasks, including the Idle Task. If the Watchdog is being "kicked" by a timer interrupt or a low-priority system monitor task, the Watchdog will see a perfectly healthy CPU and will not reboot the system, leaving the critical tasks permanently paralyzed.
