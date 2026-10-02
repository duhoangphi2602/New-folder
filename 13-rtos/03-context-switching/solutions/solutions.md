# Solutions: Context Switching

## Solution 1: The Context Switch Overhead
**Answer:** This architecture will catastrophically fail due to overhead.
1. **CPU Starvation:** A Context Switch is not free. Pushing and popping 16 registers to RAM takes dozens of CPU cycles. If the SysTick fires every 10us, the CPU will jump into the RTOS Kernel, spend 5us saving/restoring context, execute the user Task for 5us, and instantly fire the SysTick again. The CPU will spend 50%+ of its processing power *just switching between tasks*, rather than doing actual work. (This is why standard Tick Rates are 1ms).
2. **RAM Exhaustion:** Every RTOS task requires its own dedicated Stack in RAM (minimum ~512 bytes) and a TCB (Task Control Block). 50 tasks will consume at least 25-30 KB of RAM purely for OS overhead. For a small microcontroller, this will instantly cause a malloc failure.

## Solution 2: Stack Sizing
**Answer:**
- **Task A Minimum Stack:** The task has 3 local integer variables (`x`, `y`, `z` = 12 bytes). When the SysTick fires, the OS will violently push 16 registers (64 bytes) on top of those local variables. Total required memory = 12 + 64 = **76 bytes**. If you allocate less than 76 bytes, the OS will push the CPU registers outside the bounds of Task A's stack memory, overwriting whatever sits next to it in RAM (a classic Stack Overflow).
- **Task B Minimum Stack:** The task has a massive local array (`512 bytes`). Plus the OS registers (`64 bytes`). Minimum requirement = **576 bytes**. 
*(Note: In FreeRTOS, `configMINIMAL_STACK_SIZE` is usually set to 128 WORDS (512 bytes) to ensure there is always enough room for the Context Switch plus minor function calls).*
