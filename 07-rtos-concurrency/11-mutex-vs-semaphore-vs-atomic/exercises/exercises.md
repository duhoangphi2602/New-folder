# Exercises: Mutex vs Semaphore vs Atomic

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Architectural Review
For each of the following scenarios, identify the best concurrency mechanism (Mutex, Binary Semaphore, Counting Semaphore, Atomic, or Critical Section) and explain why.

1. **Scenario A:** A UART ISR receives a 100-byte packet. It needs to tell the `ParsingTask` to wake up and process it.
2. **Scenario B:** Three different Tasks all need to write debug logs to a single UART peripheral.
3. **Scenario C:** A Timer ISR increments a `uint32_t system_uptime_seconds` variable. A UI Task reads this variable to display on a screen.
4. **Scenario D:** You need to execute an inline assembly command to soft-reboot the microcontroller.

## Exercise 2: The Junior Developer's Mistake
A junior developer writes this code to wait for a hardware ADC conversion to finish:
```cpp
void read_adc() {
    start_adc_hardware();
    taskENTER_CRITICAL(); // Disable all interrupts!
    while(ADC_IS_NOT_READY) {
        // Spin and wait... usually takes 5 milliseconds
    }
    taskEXIT_CRITICAL();
}
```
**Task:** Identify the two catastrophic flaws in this code. What tool should be used instead?
