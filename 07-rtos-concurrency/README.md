# 07 — RTOS & Concurrency

This chapter covers multi-tasking, synchronization, and the concurrent execution patterns found in RTOS-based and bare-metal embedded systems.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Process / Thread / Task](./01-process-thread-task/) | Desktop vs Embedded Linux vs RTOS vs Bare-metal |
| 02 | [Bare-metal](./02-bare-metal/) | Super loop, polling |
| 03 | [RTOS Task](./03-rtos-task/) | Task creation, priority, stack |
| 04 | [Scheduler](./04-scheduler/) | Preemptive vs cooperative |
| 05 | [Context Switch](./05-context-switch/) | Save/restore, overhead |
| 06 | [Race Condition](./06-race-condition/) | Broken example → fixed |
| 07 | [Critical Section](./07-critical-section/) | Interrupt disable, latency trade-off |
| 08 | [Mutex](./08-mutex/) | Ownership, lock/unlock, priority inheritance |
| 09 | [Semaphore](./09-semaphore/) | Binary and counting |
| 10 | [Atomic](./10-atomic/) | `std::atomic`, lock-free |
| 11 | [Mutex vs Semaphore vs Atomic](./11-mutex-vs-semaphore-vs-atomic/) | Comparison table |
| 12 | [Deadlock](./12-deadlock/) | Lock ordering, detection |
| 13 | [Priority Inversion](./13-priority-inversion/) | Priority inheritance |
