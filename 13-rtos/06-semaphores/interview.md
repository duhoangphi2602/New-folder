# Interview Questions: Semaphores

## 1. What is the architectural difference between a Mutex and a Binary Semaphore? Give a use case for each.
**Answer:** The fundamental difference is "Ownership". A Mutex tracks which specific Task locked it, and strictly demands that the same Task unlocks it. A Binary Semaphore has no ownership; anyone (including hardware interrupts) can signal it. 
- **Mutex Use Case:** Protecting a shared resource. Task A takes a Mutex to write data to an I2C OLED screen. Task B must wait until Task A finishes.
- **Binary Semaphore Use Case:** Unidirectional signaling (Deferred Interrupt Processing). A hardware UART interrupt fires, placing data in a buffer. The ISR "Gives" the Semaphore. A high-priority Task, which was sleeping infinitely on a "Take", instantly wakes up and processes the data.

## 2. Why must you use the `FromISR` variants of RTOS API functions (e.g., `xSemaphoreGiveFromISR`) inside a hardware interrupt handler?
**Answer:** Hardware interrupts bypass the RTOS entirely. They execute directly on the physical CPU, preempting whatever the RTOS was currently doing. Standard RTOS APIs (like `xSemaphoreGive`) contain complex logic that might try to put the calling entity to sleep (Block) or trigger an immediate context switch. You cannot put a hardware interrupt into a "Blocked" state, and triggering a context switch directly inside an ISR will corrupt the CPU registers. The `FromISR` functions are specifically written to be mathematically safe to call from raw hardware interrupts; they defer any required context switching until the very end of the ISR using the `portYIELD_FROM_ISR` macro.

## 3. How does "Deferred Interrupt Processing" improve the real-time responsiveness of an embedded system?
**Answer:** In Bare-Metal systems, if an ADC finishes sampling, the CPU jumps to the ISR. If the math to filter the ADC data takes 50 milliseconds, the CPU is trapped inside the ISR for 50ms. During this time, all other hardware interrupts of equal or lower priority are physically blocked. The system becomes unresponsive. 
Deferred Interrupt Processing solves this by moving the heavy math out of the ISR. The ISR simply reads the raw ADC byte, calls `xSemaphoreGiveFromISR`, and exits (taking 1 microsecond). The RTOS then wakes up a dedicated, high-priority Task to do the 50ms math. Because the CPU is now back in "Thread Mode" (Task space), hardware interrupts remain enabled, allowing the system to instantly respond to other critical hardware events while the math happens in the background.
