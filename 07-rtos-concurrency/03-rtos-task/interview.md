# Interview Questions: RTOS Task

## 1. What happens if you assign a 128-byte Stack to a Task, but the Task allocates a 256-byte array locally (`int buf[64];`)?
**Answer:** The Task will suffer a Stack Overflow. Because the array is allocated on the Stack, writing to the array will write past the 128 bytes allocated by the RTOS. This will overwrite whatever memory sits physically adjacent to the stack—usually the Task Control Block (TCB) of another task, or the Stack of another task. The system will suffer a catastrophic and highly unpredictable crash.

## 2. In FreeRTOS, what is the Idle Task?
**Answer:** The Idle Task is a special task created automatically by the RTOS Scheduler when it starts. It has the absolute lowest possible priority (Priority 0). It executes only when *every other task in the system* is currently sleeping or blocked. Its primary purpose is to ensure the CPU always has valid instructions to execute. It is also commonly used to put the CPU into a low-power hardware sleep state to save battery.

## 3. How does `vTaskDelay` differ from a bare-metal `delay_ms`?
**Answer:** A bare-metal `delay_ms` usually consists of a `while` loop that spins the CPU doing useless math (like counting `NOP` instructions) until the time has elapsed. It consumes 100% CPU power and blocks the system. `vTaskDelay` does not spin the CPU. It changes the Task's state in the RTOS from "Ready" to "Blocked", and instructs the Scheduler to immediately switch the CPU to another task. This wastes 0 CPU cycles.
