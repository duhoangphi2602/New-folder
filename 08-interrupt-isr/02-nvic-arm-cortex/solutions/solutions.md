# Solutions: The NVIC

## Solution 1: The Preemption Puzzle
**Answer:**
**Task 1:** The NVIC puts the I2C interrupt into a "Pending" state. Because I2C (Pri 6) is not strictly higher priority than UART (Pri 6), it cannot preempt it. The CPU will finish the UART ISR completely, and then immediately execute the I2C ISR before returning to the main loop.
**Task 2:** The NVIC instantly preempts the UART ISR. Because Motor (Pri 2) is higher priority than UART (Pri 6), the CPU pauses the UART ISR, saves its context to the stack, executes the Motor ISR to completion, and then resumes the UART ISR. This is a Nested Interrupt.

## Solution 2: Software vs Hardware
**Answer:** The `ButtonISR` wins instantly. 
Software priorities (RTOS Tasks) and Hardware priorities (NVIC ISRs) exist in completely different universes. An RTOS Task only runs when the CPU is in "Thread Mode". An ISR runs when the CPU is in "Handler Mode". **Handler Mode always preempts Thread Mode.** Therefore, even the lowest-priority Hardware ISR will instantly preempt the highest-priority RTOS Task. The RTOS Scheduler has zero power to stop a hardware interrupt.
