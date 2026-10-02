# Interview Questions: Semaphore

## 1. What is the difference between a Mutex and a Binary Semaphore?
**Answer:** 
1. **Purpose:** A Mutex is for Mutual Exclusion (protecting shared data). A Binary Semaphore is for Synchronization (signaling between tasks/ISRs).
2. **Ownership:** A Mutex has a strict concept of "Ownership". The task that takes the Mutex is the only task allowed to give it back. A Semaphore has no ownership; an ISR can give it, and a Task can take it.
3. **Priority Inheritance:** A Mutex includes a complex algorithm called Priority Inheritance to prevent Priority Inversion deadlocks. A Semaphore does not have Priority Inheritance.

## 2. Why is it acceptable to "Give" a Semaphore from inside an ISR, but illegal to "Give" a Mutex?
**Answer:** Because Mutexes track Ownership. An ISR is not an RTOS Task; it does not have a Task Control Block (TCB). Therefore, the RTOS cannot assign "Ownership" of a Mutex to an ISR. Semaphores do not track ownership; they just increment a counter in memory. FreeRTOS provides special `FromISR` variants of Semaphore APIs specifically designed to be safe inside hardware interrupts.

## 3. What is the "Deferred Interrupt Processing" pattern, and why is it the gold standard for embedded architecture?
**Answer:** Hard Real-Time systems require ISRs (Hardware Interrupts) to execute in mere microseconds so that the CPU is not blinded to other incoming hardware events. However, processing network packets or parsing sensor data takes milliseconds. The Deferred pattern solves this by splitting the work. The ISR copies the raw data and immediately fires a Binary Semaphore. The ISR then exits instantly. The RTOS uses the Semaphore to wake up a standard Task, which performs the slow parsing logic. This keeps the ISRs lightning-fast while safely deferring the heavy lifting to the RTOS Scheduler.
