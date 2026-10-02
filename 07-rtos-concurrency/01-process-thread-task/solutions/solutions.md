# Solutions: Process, Thread, and Task

## Solution 1: The Crash Blast Radius
**Answer:**
- **Raspberry Pi (Linux):** The MMU detects the memory fault and instantly kills the *Process* that owns the Thread. All other Python threads inside that process die. However, the Linux OS itself, and all other background applications (like the web server or SSH daemon) continue running perfectly safely.
- **STM32 (FreeRTOS):** The microcontroller does not have an MMU (only an MPU at best). A null pointer dereference will trigger a hardware Hard Fault. Because the entire firmware is a single Process, the entire microcontroller will halt and reboot. The crash of one minor Task brings down the entire system.

## Solution 2: Stack Allocation
**Answer:** The system has 4 Stacks (plus 1 tiny stack used by the CPU for ISRs/Scheduler). Every time you create a Task, the RTOS permanently carves out a chunk of global RAM to act as that Task's private Stack. If you oversize every Stack (e.g., giving every task 4KB of stack when they only need 200 bytes), you will instantly run out of total SRAM. This forces embedded developers to perform careful "Stack Sizing Analysis" to give each task exactly the minimum stack memory it requires.
