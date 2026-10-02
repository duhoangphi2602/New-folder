# Solutions: Priorities & Preemption

## Solution 1: The Greedy Math Task
**Answer:** The system will **NOT** miss the button press. 
Task A is Priority 1 (Low). Task B is Priority 3 (High).
When Task B calls `vTaskDelay(10)`, it is moved to the Blocked List. The RTOS sees Task A is the only Ready task, so it lets Task A run its matrix math.
Exactly 10ms later, the SysTick interrupt fires. The RTOS Kernel wakes up Task B and moves it to the Ready List. Because Task B (Prio 3) is higher than Task A (Prio 1), the RTOS instantly **preempts** Task A, violently pausing its math calculation. Task B checks the button, finishes in 10 microseconds, and calls `vTaskDelay` again. The RTOS puts Task B back to sleep and resumes Task A's math exactly where it left off. Task A acts as a background "sink" for unused CPU cycles.

## Solution 2: Same Priority Collision
**Answer:** Both LEDs will blink (very, very fast). 
Because both tasks share the exact same Priority (2), and neither ever yields the CPU by sleeping, the FreeRTOS Scheduler falls back to **Time Slicing (Round-Robin Scheduling)**.
When the SysTick interrupt fires (every 1ms), the RTOS will preempt `Task_RedLED`, save its context, and switch to `Task_BlueLED` for exactly 1ms. On the next SysTick, it switches back to `Task_RedLED`. Each task gets exactly 50% of the CPU time in 1-millisecond intervals. (While functional, this is highly inefficient due to constant Context Switching overhead).
