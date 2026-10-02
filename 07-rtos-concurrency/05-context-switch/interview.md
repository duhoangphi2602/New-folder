# Interview Questions: Context Switching

## 1. What data must be saved to memory during a Context Switch?
**Answer:** The entire "Context" of the CPU core must be saved. This includes the Program Counter (so the task resumes at the exact right instruction), the Status Register (so flags like Overflow or Zero are maintained), the Stack Pointer, and all General Purpose Registers (`R0-R15` on ARM) that the task might be actively using for calculations. 

## 2. In FreeRTOS, what is the difference between `taskYIELD()` and waiting for the SysTick?
**Answer:** The SysTick generates a hardware interrupt at a fixed interval (e.g., every 1ms), forcing an involuntary context switch. `taskYIELD()` is a software macro that allows a task to voluntarily trigger a context switch instantly. If a task finishes its work in 0.1ms, it shouldn't spin in a `while` loop for 0.9ms waiting for the SysTick. Calling `taskYIELD()` (or a blocking API like `vTaskDelay`) instantly hands the CPU to the next ready task, maximizing system throughput and preventing wasted CPU cycles.

## 3. Why is it dangerous to set the RTOS Tick Rate (SysTick frequency) too high, such as 10,000 Hz?
**Answer:** Context switching consumes CPU cycles (Overhead). If a context switch takes 3 microseconds, and you set the tick rate to 10,000 Hz (which fires every 100 microseconds), the CPU will spend 3% of its total processing power just shuffling registers in and out of memory. This drastically reduces the CPU time available for your actual application code (Throughput). Standard RTOS Tick rates are usually 100 Hz to 1000 Hz.
