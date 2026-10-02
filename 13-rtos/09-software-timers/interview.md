# Interview Questions: Software Timers

## 1. What is the fundamental difference between a Hardware Timer and a FreeRTOS Software Timer?
**Answer:** A Hardware Timer is a physical silicon peripheral inside the microcontroller that counts clock pulses independently of the CPU and fires hardware interrupts. There are a strictly limited number of them (e.g., 4 to 8). 
A Software Timer is a logical construct managed entirely in RAM by the RTOS. It does not use dedicated hardware; instead, it relies on the RTOS counting the OS SysTick interrupts. Because they are just variables in RAM, you can create hundreds of software timers. However, they are less precise than hardware timers (resolution is limited to the OS Tick Rate, e.g., 1ms) and their callbacks run in Task context, not Interrupt context.

## 2. In FreeRTOS, what is the "Timer Service Task" (Daemon Task), and why does it exist?
**Answer:** The Timer Service Task is an automatically created, hidden RTOS task responsible for executing all Software Timer callback functions. When the SysTick interrupt realizes a software timer has expired, it does not execute the user's callback inside the SysTick ISR (which would be dangerous and delay OS scheduling). Instead, the SysTick sends a command to a queue owned by the Timer Service Task. The Timer Service Task then wakes up and safely executes the callback in standard Thread mode. This keeps the OS kernel fast and responsive.

## 3. Why is it a catastrophic architectural error to call `vTaskDelay()` inside a Software Timer Callback function?
**Answer:** Because all software timer callbacks in the entire system are executed sequentially by the single Timer Service Task. If you call `vTaskDelay(100)` inside Callback A, you are putting the entire Timer Service Task to sleep for 100 milliseconds. During this 100ms, if Timer B or Timer C expire, their callbacks cannot be executed because the task responsible for executing them is asleep in the Blocked List. Every software timer in the entire system will be frozen until the delay finishes. Callbacks must always be short, non-blocking functions.
