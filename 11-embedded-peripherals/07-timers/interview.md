# Interview Questions: Timers

## 1. Why should you never use `for(int i=0; i<10000; i++)` to create a delay in a production embedded system?
**Answer:** 
1. **Compiler Optimization:** If the compiler is set to `-O2` or `-O3`, it will identify the loop as having no observable side effects (Dead Code) and simply delete it, turning your 1-second delay into a 0-second delay.
2. **Interrupt Interference:** Even if you use `volatile` to prevent deletion, any hardware interrupt (like UART receiving a byte or SysTick firing) that occurs during the loop will pause the CPU. This adds unpredictable, variable amounts of time to your loop, making the delay highly inaccurate. 
Hardware timers operate independently of the CPU and compiler, guaranteeing microsecond-perfect precision.

## 2. What is the difference between a "Blocking Delay" and a "Non-Blocking Delay"?
**Answer:** 
- A **Blocking Delay** (like `HAL_Delay()`) puts the CPU into an infinite `while` loop, forcing it to do absolutely nothing but wait for the timer to reach a certain value. This paralyzes the system. 
- A **Non-Blocking Delay** compares a starting timestamp against the current timestamp. If the desired time has not elapsed, the function immediately returns `false` (or exits the `if` block), allowing the CPU to execute the rest of the Super Loop (e.g., updating a screen or checking a sensor). It allows the system to multitask efficiently on a single core.

## 3. How do you safely configure a Hardware Timer to fire an interrupt exactly once per second on an 84 MHz system using 16-bit registers?
**Answer:** Because the registers are 16-bit, the maximum value for both the Prescaler (PSC) and Auto-Reload Register (ARR) is 65,535. 
1. We cannot set PSC to 0 and ARR to 84,000,000, because 84 million exceeds 65,535. 
2. We must divide the clock significantly. If we set `PSC = 8399` (dividing by 8400), the timer ticks at exactly 10,000 Hz.
3. To get a 1-second delay, we need 10,000 ticks. We set `ARR = 9999`.
Both `8399` and `9999` fit comfortably inside the 16-bit limit. The timer will fire perfectly at 1 Hz.
