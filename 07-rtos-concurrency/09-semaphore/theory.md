# Semaphore

## 1. Concept (The Signal Flare)
A Mutex is a "Key" used to lock a door. 
A Semaphore is a **"Signal Flare"**. 
Task A is asleep, waiting for something to happen. Task B (or an ISR) fires the Signal Flare. The RTOS sees the flare, wakes up Task A, and Task A processes the event. 

## 2. Binary vs Counting Semaphores
- **Binary Semaphore:** Has a maximum count of 1. It is either "Fired" or "Not Fired". Used to signal a single event (e.g., "A button was pressed").
- **Counting Semaphore:** Has a maximum count of N. Every time you fire it, the count goes up. Every time a task receives it, the count goes down. Used for resource counting (e.g., "There are 5 parking spaces left").

## 3. The Core Pattern: Deferred Interrupt Processing
The most important use of a Binary Semaphore in an RTOS is the **Deferred Interrupt**.
Hardware Interrupts (ISRs) must be as short as physically possible. If a UART ISR receives a complex network packet, it should *not* process the packet inside the ISR. 
Instead:
1. The ISR copies the packet to a buffer.
2. The ISR **"Gives"** a Binary Semaphore (fires the flare).
3. The ISR exits instantly (taking only 2 microseconds).
4. The RTOS instantly wakes up the `NetworkTask` (which was blocked on `Take(Semaphore)`).
5. The `NetworkTask` processes the complex packet at the Task level, allowing other higher-priority hardware interrupts to continue firing.

## 4. Syntax (FreeRTOS)
```cpp
SemaphoreHandle_t packet_semaphore = xSemaphoreCreateBinary();

// 1. The Hardware Interrupt (ISR)
void UART_ISR() {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    // Fire the flare! (Note the special "FromISR" API)
    xSemaphoreGiveFromISR(packet_semaphore, &xHigherPriorityTaskWoken);
    
    // Force a context switch if the woken task has higher priority
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken); 
}

// 2. The RTOS Task
void NetworkTask() {
    while(1) {
        // Sleep indefinitely until the flare is fired
        if (xSemaphoreTake(packet_semaphore, portMAX_DELAY) == pdTRUE) {
            process_complex_packet(); 
        }
    }
}
```

## 5. Semaphore vs Mutex (The Golden Rule)
- **Mutex:** The Task that Takes the Mutex MUST be the one that Gives it back. (Ownership).
- **Semaphore:** Task A (or an ISR) Gives the Semaphore. Task B Takes the Semaphore. (Signaling).

## 6. Example
*(See `examples/` for a C++ thread simulation of the Deferred Interrupt pattern).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
