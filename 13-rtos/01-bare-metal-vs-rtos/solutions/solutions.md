# Solutions: Bare-Metal vs RTOS

## Solution 1: The Infinite Loop Trap
**Answer:** You forgot to put the task to sleep (e.g., calling `vTaskDelay(10)` or blocking on a semaphore). 
In an RTOS, if a High Priority task wants to run, the RTOS gives it 100% of the CPU. If the task never calls an OS function to explicitly say *"I am done for now, go to sleep"*, the RTOS assumes the task is still doing critical work. Because of the `while(1)`, the Motor Task runs in a perfectly tight loop forever. The RTOS will never switch the CPU to the lower-priority WiFi or Screen tasks. This is called **Task Starvation**. Every RTOS `while(1)` loop MUST contain a blocking API call to yield the CPU back to the OS.

## Solution 2: When NOT to use an RTOS
**Answer:** You should strictly use a **Bare-Metal Super Loop**.
1. **RAM Constraints:** FreeRTOS itself consumes roughly 2-4 KB of RAM just for its internal lists. Every task you create requires its own Stack (usually min 512 bytes). With only 8 KB of total RAM, an RTOS will consume almost all of it, leaving nothing for your actual application data.
2. **Complexity & Power:** The application is entirely linear and sequential (Wake -> Read -> Update -> Sleep). There are no asynchronous background tasks (like maintaining a continuous WiFi socket) that need to run in parallel. Firing up the RTOS Scheduler takes CPU cycles and power. Bare-metal is vastly simpler, uses less battery, and requires far less RAM for this specific use-case.
