# Solutions: Mutex vs Semaphore vs Atomic

## Solution 1: Architectural Review
**Answer:**
1. **Scenario A (Binary Semaphore):** This is the classic "Deferred Interrupt" pattern. The ISR Gives the Semaphore, the Task Takes it. 
2. **Scenario B (Mutex):** Multiple tasks sharing a hardware resource must use Mutual Exclusion to prevent their log messages from becoming interleaved (jumbled). 
3. **Scenario C (`std::atomic<uint32_t>`):** An ISR cannot use a Mutex. We are only sharing a primitive 32-bit integer. `std::atomic` is the fastest, safest way to share primitives between an ISR and a Task.
4. **Scenario D (Critical Section):** When rebooting the system, you absolutely do not want a Timer or UART interrupt to suddenly fire midway through the reboot sequence and corrupt the CPU state.

## Solution 2: The Junior Developer's Mistake
**Answer:**
1. **The Freeze:** The developer used a Critical Section, which turns off all hardware interrupts globally. During those 5 milliseconds, no other hardware on the board can function.
2. **The Infinite Deadlock:** Usually, ADC hardware tells the CPU it is finished by triggering an ADC Hardware Interrupt! But because the developer called `taskENTER_CRITICAL()`, the ADC interrupt is physically blocked from firing. `ADC_IS_NOT_READY` will never change to true. The system is permanently frozen.

**The Fix:** The hardware should be configured to trigger an ISR when finished. The ISR should Give a **Binary Semaphore**. The `read_adc()` function should simply Take that Semaphore (putting the task to sleep for 5ms without blocking the rest of the CPU).
