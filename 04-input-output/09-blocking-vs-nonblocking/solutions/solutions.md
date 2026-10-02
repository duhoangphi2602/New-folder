# Solutions: Blocking vs Non-Blocking I/O

## Solution 1: The "Delay" Trap
**Answer:** The consequence is that the `read_emergency_stop_button()` function is only executed once every 1,000 milliseconds. If an operator presses the emergency stop button 10 milliseconds after the LED toggles, the CPU will literally ignore the button for the next 990 milliseconds because it is trapped inside the blocking `delay()` loop. In a robotic system, a 1-second delay in an emergency stop is catastrophic. (This is why professional systems use non-blocking Timer Interrupts or an RTOS instead of `delay()`).

## Solution 2: Selecting an Architecture
**Answer:**
1. **The Bootloader:** **Polling**. Bootloaders need to be as small and simple as possible. Because no other complex code is running during boot, blocking the CPU to print a few characters is perfectly fine.
2. **The User Interface:** **Interrupts**. Humans are incredibly slow. The CPU cannot afford to poll the UART waiting for a human to press a key. An interrupt guarantees the CPU is instantly notified the exact microsecond a key is pressed, while leaving the CPU 100% free the rest of the time.
3. **The Camera:** **DMA**. Moving 2 Megabytes of data would require 2 million separate Interrupts, which would overwhelm the CPU with context-switching overhead. DMA allows the hardware to stream the data autonomously in the background, allowing the CPU to process the next image simultaneously.
