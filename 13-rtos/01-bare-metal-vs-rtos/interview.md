# Interview Questions: Bare-Metal vs RTOS

## 1. What does the term "Deterministic" mean in the context of a Real-Time Operating System?
**Answer:** Determinism means absolute predictability regarding timing. In a General Purpose OS (like Linux), a high-priority task might execute in 1ms, or it might be delayed by 50ms because the OS decided to flush a disk cache or handle a GUI event. In an RTOS, if a task is given the highest priority, the system mathematically guarantees that it will preempt any lower-priority task and execute within a strictly defined, worst-case time limit (e.g., exactly 2 microseconds), regardless of what else is happening in the system. RTOS prioritizes strict deadlines over general throughput.

## 2. In a Bare-Metal system, how is the Stack managed in RAM? How does this change when you implement an RTOS?
**Answer:** In a Bare-Metal system, there is only one main execution thread (`main()`), so there is exactly **one** physical Stack in RAM. As functions call other functions, this single stack grows downwards. 
When you implement an RTOS, you create multiple independent Tasks. The RTOS must allocate a **separate, dedicated Stack** for every single task. If you have 5 tasks, you have 5 separate Stacks residing in RAM (plus one for ISRs). This drastically increases the baseline RAM consumption of the system and introduces the risk of "Stack Overflow" on a per-task basis if you allocate a stack that is too small for a specific task's local variables.

## 3. Name one specific scenario where a Bare-Metal Super Loop is superior to an RTOS, and one scenario where an RTOS is strictly necessary.
**Answer:** 
- **Bare-Metal is superior** in ultra-low power, deeply constrained sensor nodes (e.g., an ATTiny85 with 512 bytes of RAM that wakes up, reads a humidity sensor, blinks an LED, and sleeps). An RTOS wouldn't even fit in the RAM, and the scheduling overhead would waste battery life for no benefit.
- **RTOS is strictly necessary** in complex, asynchronous IoT systems (e.g., an ESP32 maintaining a persistent SSL WebSocket connection to AWS, while simultaneously driving a 60FPS graphical touch screen and processing audio from a microphone via DMA). Managing those wildly different timing requirements in a single `while(1)` loop would result in unmaintainable spaghetti code and missed audio samples.
