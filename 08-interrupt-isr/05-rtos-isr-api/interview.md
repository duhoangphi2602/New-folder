# Interview Questions: RTOS ISR API

## 1. Why does calling a standard FreeRTOS API (like `vTaskDelay` or `xQueueReceive`) inside an ISR cause a system crash?
**Answer:** Standard RTOS APIs are designed to change the state of the calling entity from "Running" to "Blocked" (sleeping) if a resource is unavailable or a delay is requested. However, an ISR is a hardware interrupt context, not an RTOS software Task. It does not possess a Task Control Block (TCB) and therefore the RTOS has no structural way to put it to "sleep". When the RTOS attempts to manipulate the TCB of the caller, it dereferences a NULL pointer or corrupts memory, triggering a hardware Hard Fault.

## 2. Explain the purpose of `portYIELD_FROM_ISR()`. What problem does it solve?
**Answer:** When an ISR gives a Semaphore or sends data to a Queue, it often wakes up a high-priority RTOS Task that was waiting for that data. However, when the ISR exits, the CPU will naturally return to whatever lower-priority task it was executing before the interrupt fired. The newly awoken high-priority task won't execute until the next SysTick timer fires (which could be 1ms away). `portYIELD_FROM_ISR()` solves this latency. It evaluates if a higher-priority task was woken, and if so, it forces an immediate Context Switch the exact nanosecond the ISR exits, guaranteeing zero-latency response for critical tasks.

## 3. What does it mean that `...FromISR` APIs are strictly "non-blocking"?
**Answer:** It means they will never attempt to pause the CPU or wait for a resource. If an ISR attempts to write to an RTOS Queue using `xQueueSendFromISR()`, and the Queue is already 100% full, the function will not wait for space to clear up. It will immediately return an error code (e.g., `errQUEUE_FULL`) and allow the ISR to continue executing. This guarantees that ISRs execute at deterministic, lightning-fast speeds without freezing the hardware.
