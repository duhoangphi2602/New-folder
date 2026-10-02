# Solutions: Critical Section

## Solution 1: The Missing Exit
**Answer:** If the buffer is full, the function hits `return` and skips `taskEXIT_CRITICAL()`. 
Because hardware interrupts are physically disabled at the CPU level, the SysTick timer can no longer trigger the Scheduler. Furthermore, no hardware peripherals (UART, Timers, Buttons) can trigger ISRs. The current task will run forever, but the OS Scheduler is dead. The system has completely frozen (a catastrophic deadlock) because the CPU is permanently deaf to the outside world. (This is why C++ RAII is critical).

## Solution 2: Latency Analysis
**Answer:** The motor will crash. 
The priority system in an RTOS only applies when the Scheduler is active. A Critical Section forcibly turns off the hardware interrupt controller (NVIC on ARM). Even if the Motor ISR is the most important hardware signal in the world, the CPU physically cannot process it while the Critical Section is active. The Motor ISR will be delayed for a massive 3ms while the screen clears. This violates the 1ms Hard Real-Time deadline, causing the motor to become unbalanced and fail. Critical Sections must NEVER contain slow code.
