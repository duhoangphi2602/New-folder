# Exercises: Timers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The 16-Bit Limit
You have an STM32 with a `16 MHz` system clock.
You want to configure Timer 2 (which is a **16-bit** timer) to fire an interrupt exactly once every **5 seconds**.
You set the Prescaler (PSC) to `15` (Dividing by 16). The timer now ticks at exactly 1 MHz (1,000,000 ticks per second).
To wait 5 seconds, you try to set the Auto-Reload Register (ARR) to `5,000,000`.
**Task:** When you compile this code, the timer fires an interrupt wildly fast, completely ruining the 5-second delay. Why? What hardware limitation did you ignore, and how can you fix the PSC and ARR to achieve the 5-second delay legally?

## Exercise 2: `uwTick` Overflow
The global `uwTick` variable (incremented by the SysTick timer every 1 millisecond) is typically defined as a `uint32_t`.
```cpp
uint32_t uwTick;
```
**Task:** If you turn on your IoT device and leave it running continuously, eventually `uwTick` will reach its maximum value and "overflow" back to 0. Mathematically calculate how many **days** it will take for this `uint32_t` variable to overflow if it increments every 1 millisecond.
