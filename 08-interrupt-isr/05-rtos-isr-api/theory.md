# RTOS ISR APIs

## 1. The Ban on Standard APIs
Standard FreeRTOS functions (like `xSemaphoreTake`, `xQueueSend`, `vTaskDelay`) are designed specifically for Tasks. 
If a Task calls `xQueueSend` and the queue is full, the API puts the Task into a **BLOCKED (Sleeping)** state. 
If an **ISR** calls `xQueueSend` and the queue is full, the API tries to put the ISR to sleep. But an ISR is not a Task! It has no Task Control Block (TCB). The RTOS attempts to read a NULL pointer, and the system instantly crashes (Hard Fault).

## 2. The `...FromISR` Solution
FreeRTOS solves this by providing parallel versions of almost every API, appending `FromISR` to the name (e.g., `xQueueSendFromISR`, `xSemaphoreGiveFromISR`).
These special versions are **strictly non-blocking**.
If an ISR calls `xQueueSendFromISR` and the queue is full, the function simply returns an `errQUEUE_FULL` status instantly. It never attempts to put the caller to sleep, ensuring the ISR remains lightning fast and crash-free.

## 3. The Context Switch Problem
There is a second reason `FromISR` functions are special.
Imagine this sequence:
1. `Task_Low` is currently running.
2. An Interrupt fires! The CPU jumps to the ISR.
3. Inside the ISR, we call `xSemaphoreGiveFromISR()`. 
4. This semaphore wakes up `Task_High` (changes its state from BLOCKED to READY).
5. The ISR exits.
**Who runs next?**
Because the SysTick timer hasn't fired yet, the Scheduler hasn't run. The CPU will automatically resume `Task_Low`. `Task_High` is awake, but it won't actually execute until the *next* SysTick (which could be 1 millisecond away). This introduces 1ms of unacceptable latency!

## 4. `pxHigherPriorityTaskWoken` (Manual Preemption)
To solve the latency problem, `FromISR` functions accept a special pointer argument: `BaseType_t* pxHigherPriorityTaskWoken`.
When you call the API, if waking the target task results in a higher-priority task being ready, the RTOS sets this variable to `pdTRUE`.
You then pass this variable to `portYIELD_FROM_ISR()`. This macro forces an instant, manual Context Switch the exact microsecond the ISR exits, guaranteeing `Task_High` runs immediately!

## 5. Syntax (FreeRTOS)
```cpp
void UART_ISR() {
    // 1. Create the variable, initialized to false
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    uint8_t data = UART_DATA_REG;

    // 2. Call the FromISR API. Pass the address of the variable!
    xQueueSendFromISR(my_queue, &data, &xHigherPriorityTaskWoken);

    // 3. Request a context switch if needed
    // If the queue woke up a high priority task, this forces the CPU 
    // to jump to it immediately upon exiting this ISR.
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
```

## 6. Example
*(See `examples/` for a simulated logic flow of `portYIELD_FROM_ISR`).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
