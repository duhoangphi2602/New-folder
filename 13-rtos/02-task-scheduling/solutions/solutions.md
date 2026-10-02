# Solutions: Task Scheduling

## Solution 1: The Idle Task
**Answer:** The CPU is physical hardware; it can never "stop" executing instructions (unless put into deep sleep). It must always fetch the next instruction from memory. 
If all user tasks call `vTaskDelay()`, they are all moved to the **Blocked List**. The **Ready List** becomes completely empty. When the SysTick fires and the Scheduler looks for a task to run, it would crash because there is no code to execute.
The `Idle Task` guarantees that the Ready List is *never* empty. Priority 0 ensures it only runs when absolutely every other task is asleep. (Advanced RTOS designs use the Idle Task to execute a WFI (Wait For Interrupt) assembly instruction, safely putting the CPU into low-power sleep to save battery until the next SysTick).

## Solution 2: Blocking vs Polling
**Answer:** 
- **Developer A (Polling):** Because there is no `vTaskDelay` or OS blocking call, this task is permanently in the **Running** or **Ready** state. Because it is Priority 3, the RTOS will give it 100% of the CPU forever. All lower priority tasks (Priority 1 and 2) will be permanently starved and will never execute for 10 hours. This is a catastrophic failure of RTOS design.
- **Developer B (Blocking):** The `xSemaphoreTake` function is an RTOS API. It instantly moves the task into the **Blocked** state. For the next 10 hours, the RTOS Scheduler completely ignores this task. It consumes exactly 0.00% CPU time, allowing Priority 1 and Priority 2 tasks to run perfectly. The exact millisecond the button is pressed (via an interrupt), the OS instantly wakes up Developer B's task (moving it to the Ready List), preempts everything, and fires the missile. **Developer B's design is the only correct way to write RTOS code.**
