# Solutions: Timers

## Solution 1: The 16-Bit Limit
**Answer:** The timer is a **16-bit** hardware register. The absolute maximum value it can hold is $2^{16} - 1 = 65,535$. 
You tried to write `5,000,000` into the ARR register. This caused an integer overflow during configuration, and the hardware truncated it to a random small number, causing the timer to fire wildly fast.
**The Fix:** You must use a much larger Prescaler to slow the timer down enough so the ARR can fit under 65,535.
Let's divide the 16 MHz clock by 16,000. 
`PSC = 15999`. 
The timer now ticks at 1,000 Hz (1 tick = 1 millisecond).
To wait 5 seconds, you need 5,000 ticks.
`ARR = 4999`. 
5000 easily fits inside the 16-bit limit (65,535). The timer will now legally fire every 5 seconds.

## Solution 2: `uwTick` Overflow
**Answer:** 
1. A `uint32_t` has a maximum value of $2^{32} - 1 = 4,294,967,295$.
2. It increments once every 1 millisecond.
3. Therefore, it will overflow after `4,294,967,295` milliseconds.
4. Convert to seconds: `/ 1000 = 4,294,967` seconds.
5. Convert to minutes: `/ 60 = 71,582` minutes.
6. Convert to hours: `/ 60 = 1,193` hours.
7. Convert to days: `/ 24 = 49.7` days.
If your IoT device runs for 50 days straight, the millisecond counter will suddenly warp back to 0. If you wrote a naive `if (current_time > target_time)` delay, this rollover will instantly break your logic and crash the device. Professional delay functions always use subtraction (`(current_time - start_time) > target_delay`) which mathematically survives integer rollover.
