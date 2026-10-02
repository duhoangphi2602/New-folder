# Interview Questions: ISR Best Practices

## 1. What are the three most important rules for writing an Interrupt Service Routine (ISR)?
**Answer:** 
1. **Keep it short and fast:** Execute the absolute minimum number of instructions necessary (copy data, set a flag) and exit. Never do heavy math or string formatting.
2. **Never Block:** Never use `while` loops waiting for hardware, never call `delay()`, and never use standard blocking RTOS APIs (like Mutexes or standard Queues).
3. **Clear the Interrupt Flag:** You must explicitly clear the hardware pending bit in the peripheral's register, otherwise the CPU will instantly re-enter the ISR upon exiting, causing an infinite loop.

## 2. Why is it dangerous to call `malloc()` or `printf()` inside an ISR?
**Answer:** Both `malloc()` and `printf()` are massive, non-deterministic C standard library functions. `printf()` often blocks the CPU while waiting for a slow UART peripheral to transmit text. `malloc()` walks a linked list in the Heap to find memory, which can take an unpredictable amount of time and often relies on internal software Mutexes to be thread-safe. Calling either inside an ISR will cause massive Interrupt Latency (blocking other critical hardware events) and likely trigger a deadlock or Hard Fault.

## 3. If you receive a massive, complex block of encrypted data inside a UART ISR, how should you architect the decryption process?
**Answer:** You must use the "Deferred Interrupt Processing" pattern. The ISR should simply copy the raw encrypted bytes into a global Ring Buffer (or an RTOS Stream Buffer) and immediately "Give" a Binary Semaphore. The ISR then exits, having taken only a few microseconds. The RTOS Scheduler takes over, sees the Semaphore, and wakes up a dedicated `DecryptionTask`. The Task then performs the heavy decryption math at the software level, allowing other hardware interrupts to continue firing normally.
