# Hardware Timers

## 1. The Anatomy of a Timer
A Hardware Timer is essentially just a physical counter register that increments by 1 every time it receives a clock pulse.
If the microcontroller is running at 16 MHz, the timer will increment 16,000,000 times per second.

Two critical registers control the timer's speed and limit:
1. **Prescaler (PSC):** A divider. If you set the PSC to 16, the timer ignores 15 clock pulses and only increments on the 16th. A 16 MHz clock is thus scaled down to a 1 MHz timer (it increments 1,000,000 times per second, meaning 1 "tick" = exactly 1 microsecond).
2. **Auto-Reload Register (ARR):** The ceiling. When the timer counter reaches this number, it resets back to 0.

## 2. The Timer Update Interrupt (Overflow)
When the timer hits the ARR ceiling and resets to 0, it fires an **Update Interrupt (UIF)**.
This is the heartbeat of real-time systems.
If your timer ticks at 1 MHz (1 tick = 1us), and you set the ARR to 1000:
- The timer will count from 0 to 1000.
- It will take exactly 1000 microseconds (1 millisecond) to reach the ceiling.
- It will fire an interrupt exactly every 1 millisecond.
- You can put your logic inside this ISR (e.g., read a sensor, update a screen), guaranteeing it runs at exactly 1 kHz, completely immune to `for` loop inaccuracies or CPU load.

## 3. SysTick Timer
Every ARM Cortex-M chip has a dedicated, standardized timer built deep into the core called the **SysTick**. It is almost universally configured to fire an interrupt exactly every 1 millisecond. The OS or HAL library uses this to keep track of a global `uwTick` variable (representing "Milliseconds since boot").

## 4. Non-Blocking Delays
Using the SysTick, you can write delays without freezing the CPU.
```cpp
uint32_t start_time = HAL_GetTick(); // Get current millisecond
while ( (HAL_GetTick() - start_time) < 500 ) {
    // 500ms has not passed yet.
    // We can do OTHER work here while we wait!
    process_background_tasks();
}
```
This is a **Non-Blocking Delay**. It waits 500ms, but allows the CPU to remain productive during the waiting period.

## 5. Example
*(See `examples/` for timer frequency calculation math).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
