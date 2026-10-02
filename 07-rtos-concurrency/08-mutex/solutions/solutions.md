# Solutions: Mutex

## Solution 1: The ISR Crash
**Answer:** A Mutex works by putting the calling Task into a "Blocked" (sleeping) state if the Mutex is unavailable. An ISR is a hardware mechanism, not an RTOS Task. An ISR has no Task Control Block (TCB), no priority, and no RTOS state. Therefore, it is physically impossible for the RTOS to put an ISR to "sleep". If an ISR tries to take a locked Mutex, the RTOS API will attempt to manipulate a non-existent TCB, causing memory corruption and a Hard Fault. If data is shared between a Task and an ISR, you MUST use a Critical Section or a Lock-Free Queue.

## Solution 2: State Transitions
**Answer:** Task B transitions from **RUNNING** to **BLOCKED**. The RTOS Scheduler instantly removes Task B from the CPU and switches context to another Ready task. Because Task B is in the Blocked state, it consumes absolutely zero CPU cycles while waiting. It will remain entirely dormant until Task A releases the Mutex, at which point the RTOS will automatically change Task B's state to READY.
