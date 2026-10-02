# Exercises: Context Switching

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Context Switch Overhead
A junior developer decides to architect an RTOS project by breaking the system down into **50 micro-tasks**. 
Task 1 reads a GPIO pin and sends it to Task 2. Task 2 checks the value and sends it to Task 3... all the way to Task 50. 
To make this work seamlessly, the developer configures the SysTick timer to fire every **10 microseconds** (100,000 Hz tick rate).
**Task:** Identify two massive, system-destroying problems with this architectural design regarding Context Switching overhead.

## Exercise 2: Stack Sizing
When you call `xTaskCreate` in FreeRTOS, you must specify the Stack Depth (e.g., `128` words).
Task A does simple math: `int z = x + y;`
Task B declares a large local buffer: `char rx_buffer[512];`
**Task:** If a Context Switch requires saving all 16 CPU registers (approx 64 bytes total) onto the Stack, what is the absolute minimum Stack Size (in bytes) you must allocate for Task A to survive a context switch without causing a Stack Overflow? What about Task B?
