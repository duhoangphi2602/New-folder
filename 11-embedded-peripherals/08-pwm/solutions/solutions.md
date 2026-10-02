# Solutions: PWM

## Solution 1: The Fading LED
**Answer:** Putting fading logic (which requires precise `HAL_Delay()` calls to slow down the fade) inside the `main` loop is a "Blocking" design. While the CPU is waiting to increment the brightness, it cannot respond to buttons, read sensors, or talk to the PC via UART. The system is paralyzed.
**The Architectural Fix:** 
1. Keep the 10 kHz PWM timer running in the background to drive the LED.
2. Configure a **second** timer to fire an Update Interrupt every 10 milliseconds (100 Hz).
3. Inside this ISR, you simply execute `if (fading_up) CCR++; else CCR--;`. 
The hardware handles the PWM, the ISR handles the fading math instantly in the background, and the `main` loop remains 100% free to do actual system tasks.

## Solution 2: Servo Math
**Answer:**
1. **The ARR (Frequency):** We need 50 Hz. If the timer ticks at 1,000,000 Hz, the total number of ticks required for one full 50 Hz cycle is `1,000,000 / 50 = 20,000`. 
Therefore, `ARR = 19999` (because it's 0-indexed).
2. **The CCR (Duty Cycle):** 
- 0 degrees requires a 1000us pulse.
- 180 degrees requires a 2000us pulse.
- Therefore, exactly in the middle (90 degrees) requires a 1500us pulse.
Since our timer ticks exactly every 1 microsecond, to keep the pin HIGH for 1500 microseconds, we simply set `CCR = 1500`. 
*(Note: A 1500us pulse out of a 20000us total cycle is exactly a 7.5% Duty Cycle).*
