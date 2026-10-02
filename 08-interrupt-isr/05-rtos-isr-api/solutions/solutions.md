# Solutions: RTOS ISR API

## Solution 1: The Missing Parameter
**Answer:** When the ISR fires, it successfully gives the Semaphore and changes `Task_UI`'s state from BLOCKED to READY. `Task_UI` is now the highest priority ready task (5 > 2). 
However, because the developer forgot to call `portYIELD_FROM_ISR`, the CPU does *not* switch context when the ISR exits. Instead, the CPU blindly returns to `Task_Background`. `Task_Background` continues to run until the next hardware SysTick interrupt fires (usually up to 1 millisecond later). At that point, the Scheduler finally runs, notices `Task_UI`, and switches to it. 
**Result:** The button press is processed successfully, but the developer has accidentally introduced up to 1 millisecond of "Jitter" (random latency) into the UI response.

## Solution 2: Why two APIs?
**Answer:** The entire purpose of an RTOS Task is to block (go to sleep) when a resource is unavailable, yielding the CPU to other tasks. Standard APIs (like `xQueueSend(..., portMAX_DELAY)`) handle this blocking automatically. 
`FromISR` APIs are strictly non-blocking. If a Task used `xQueueSendFromISR` and the queue was full, the function would instantly return an error. The Task would then have to write a `while` loop to repeatedly retry sending. This turns the Task into a CPU-burning Polling loop, destroying the entire efficiency model of the RTOS. You must use standard blocking APIs in Tasks, and non-blocking `FromISR` APIs in hardware interrupts.
