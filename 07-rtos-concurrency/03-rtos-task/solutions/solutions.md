# Solutions: RTOS Task

## Solution 1: The Starvation Bug
**Answer:** The Wi-Fi connection will drop and completely fail. Because the MotorTask has a higher priority (5 > 2) and never enters a "Sleeping" state, the RTOS Scheduler will mathematically mandate that the MotorTask occupies the CPU for 100% of the available time. The Wi-Fi Task will suffer from "Task Starvation" and will execute exactly 0 CPU instructions. Every task *must* yield or block to allow lower-priority tasks a chance to execute.

## Solution 2: Task Return Values
**Answer:** An RTOS task represents an infinite, independent execution thread. There is no "Operating System Command Line" to return an exit code to (unlike returning to Linux/Windows from `main`). If a task actually executes a `return;` statement (or reaches the closing brace `}`), the CPU attempts to return to whatever called the task. But nothing called the task—it was launched by the Scheduler. The CPU will pop invalid data off the stack, jump to a random memory address, and instantly trigger a Hard Fault crash. (If a task must die, it must explicitly call `vTaskDelete(NULL)`).
