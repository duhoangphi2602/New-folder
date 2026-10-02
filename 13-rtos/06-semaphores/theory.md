# Semaphores

## 1. Mutex vs Semaphore
- **Mutex (Protection):** Has a strict concept of "Ownership". If Task A takes a Mutex, *only* Task A is allowed to give it back. It is a lock for a shared resource.
- **Semaphore (Signaling):** Has NO concept of ownership. Task A can wait (take) the semaphore, and a completely different entity—like a hardware interrupt (ISR)—can give the semaphore. It is a one-way notification system.

## 2. The Binary Semaphore
A Binary Semaphore acts like a flag that can only be `1` (Available) or `0` (Empty).
**The Classic Architecture (Deferred Interrupt Processing):**
1. You create a High Priority Task (`Task_Process_UART`) that immediately calls `xSemaphoreTake(uart_sem, portMAX_DELAY)`. The task instantly goes to sleep.
2. A hardware UART interrupt fires because a byte arrived. The CPU jumps to the ISR.
3. Inside the ISR, you *never* process data. The ISR does exactly one thing: `xSemaphoreGiveFromISR(uart_sem)`. The ISR exits.
4. Giving the semaphore instantly wakes up `Task_Process_UART`. Because it is High Priority, the RTOS preempts whatever was running, processes the byte, and goes back to sleep.
*Result:* Your hardware interrupts stay incredibly short and fast, preventing system lockups.

## 3. The Counting Semaphore
A Counting Semaphore is a bin that can hold a specific number of tokens (e.g., Max 10).
- Every time a Task or ISR "Gives" it, the count increases by 1.
- Every time a Task "Takes" it, the count decreases by 1.
**Use Case:** You have 3 concurrent Tasks that generate logging messages, but your hardware only has a 5-slot deep memory buffer for the logs. You initialize a Counting Semaphore with a count of 5. Tasks can write to the buffer 5 times instantly. The 6th time, `xSemaphoreTake()` will block the task and put it to sleep until a slot frees up.

## 4. The `FromISR` APIs
You are **never** allowed to call standard RTOS APIs (like `xSemaphoreGive()`) from inside a hardware Interrupt Service Routine. ISRs do not run inside the RTOS environment; they preempt the OS itself. 
FreeRTOS provides specific, interrupt-safe versions of all APIs ending in `FromISR` (e.g., `xSemaphoreGiveFromISR()`). These APIs interact with the RTOS Scheduler safely and can trigger a context switch as the ISR exits.

## 5. Example
*(See `examples/` for deferred interrupt processing code).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
