# Solutions: Queues

## Solution 1: The String Pointer Bug
**Answer:** The developer committed a fatal RTOS memory architecture sin: passing a pointer to a local stack variable.
The array `local_buffer` exists in the local RAM stack of `vTaskUart`. When the task calls `read_uart_string`, the bytes are stored there. The task pushes the *memory address* of that stack array onto the queue.
Then, `vTaskUart` immediately loops back to the top and starts reading the *next* UART string. This physically overwrites the bytes inside `local_buffer`!
By the time the Consumer task wakes up, receives the pointer, and looks at that memory address, the bytes have already been destroyed or replaced by the Producer task.
**The Fix:** Either pass the data by Copy (make the queue hold `struct{ char buf[100]; }`), or allocate memory dynamically via `malloc` for every string, pass the pointer, and force the Consumer task to call `free()` when done.

## Solution 2: Queue Sizing
**Answer:** 
1. The Producer (ISR) generates 1 byte every 5 milliseconds.
2. The Consumer (`Task_Process`) might be frozen for up to 50 milliseconds.
3. During that 50ms freeze, the ISR will fire `50ms / 5ms = 10 times`.
4. The ISR will attempt to push 10 bytes onto the queue. Because the Consumer is frozen, it isn't reading them, so the queue is filling up.
5. If the queue holds less than 10 items, the 10th push will fail, and data will be permanently lost.
Therefore, the absolute minimum depth is **10 items** (though in professional engineering, you would add a 20-30% safety margin and size it for 15).
