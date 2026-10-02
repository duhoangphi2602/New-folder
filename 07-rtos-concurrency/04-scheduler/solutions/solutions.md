# Solutions: The Scheduler

## Solution 1: The Race
**Answer:**
1. At the first SysTick, Task C is still BLOCKED. The Scheduler ignores it. The only contenders are A (10) and B (5). Task A is the highest priority READY task. The Scheduler picks Task A to continue running.
2. 100ms later, the RTOS changes Task C's state from BLOCKED to READY. Now the contenders are A (10), B (5), and C (15). The Scheduler picks Task C. Task A is preempted (paused and moved to the READY state), and Task C becomes RUNNING.

## Solution 2: While(1) vs vTaskDelay
**Answer:** Task A and Task B have the same priority (2). 
Task B runs, but quickly hits `vTaskDelay(10)`, transitioning to the BLOCKED state for 10 milliseconds. 
This leaves Task A as the only READY task at Priority 2. Task A does *not* have a delay. It spins in an infinite mathematical loop.
Task C is at Priority 1. Because Task A is always READY and has a higher priority (2 > 1), the Scheduler will *always* choose Task A over Task C. 
Therefore, Task A gets almost 100% of the CPU. Task B gets tiny bursts of CPU every 10ms. **Task C suffers total starvation and executes 0 instructions.**
