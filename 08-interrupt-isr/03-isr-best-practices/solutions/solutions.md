# Solutions: ISR Best Practices

## Solution 1: The "While" Trap
**Answer:** An ISR must execute as fast as physically possible. By placing a `while` loop inside an ISR, the developer is forcing the CPU to block inside a hardware interrupt context. 
If the I2C wire becomes physically disconnected, `I2C_READY` will never become 1. The CPU will be permanently trapped inside this `while` loop. Because it is in an ISR, all lower-priority interrupts and the entire RTOS Scheduler are blocked from running. The entire device freezes completely. 
Hardware waiting must be done at the Task level (using timeouts), NEVER in an ISR.

## Solution 2: RTOS API Selection
**Answer:** The standard `xQueueSend` function is a blocking software API. If the queue is full, the `portMAX_DELAY` argument tells the RTOS to put the caller to "sleep" (Blocked state) until space is available. Because an ISR is hardware, not an RTOS Task, it is physically impossible to put an ISR to sleep. Attempting to do so causes a Hard Fault.
**The Fix:** You must use the special ISR-safe version: `xQueueSendFromISR()`. This version is non-blocking. If the queue is full, it simply returns an error code instantly and exits, ensuring the ISR completes rapidly and safely.
