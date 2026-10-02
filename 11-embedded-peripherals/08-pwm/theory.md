# PWM (Pulse Width Modulation)

## 1. The Illusion of Analog
If you turn an LED ON for 1 millisecond, and OFF for 1 millisecond, continuously, the LED is actually flashing 500 times a second. The human eye is too slow to see this flashing. Instead, the eye mathematically averages the light, making the LED appear exactly 50% as bright. This is the magic of PWM.

## 2. Frequency and Duty Cycle
A PWM signal is defined by two parameters:
1. **Frequency:** How fast the complete ON/OFF cycle repeats (e.g., 1000 Hz). This must be fast enough that humans/motors don't perceive the stuttering.
2. **Duty Cycle:** The percentage of time the signal is ON during one cycle.
   - 0% Duty Cycle: 0V (Always Off)
   - 50% Duty Cycle: 1.65V effective (Half Power)
   - 100% Duty Cycle: 3.3V (Always On)

## 3. How Timers Generate PWM
PWM is generated strictly by Hardware Timers, completely independent of the CPU.
You configure the timer's ARR (Auto-Reload Register) to define the **Frequency**.
You configure a third register, the **CCR (Capture/Compare Register)**, to define the **Duty Cycle**.

**The Mechanics:**
1. The timer starts at 0. The GPIO pin is instantly forced HIGH (3.3V).
2. The timer counts up.
3. When the timer matches the `CCR` value, the GPIO pin is forced LOW (0V).
4. The timer keeps counting up until it hits the `ARR` (the ceiling).
5. The timer resets to 0. The GPIO pin goes HIGH again.

If `ARR = 1000`, and `CCR = 250`: The pin is HIGH for the first 25% of the cycle, and LOW for the remaining 75%. This creates a perfect 25% Duty Cycle.

## 4. Hardware Routing
To output this PWM signal to a physical pin, you must configure the GPIO pin into **Alternate Function (AF)** mode. This disconnects the pin from the CPU's software control and connects it directly to the Timer's hardware output channel.

## 5. Servo Motors
PWM is not just for dimming LEDs. Standard hobby Servo motors are controlled via a 50 Hz PWM signal. 
- A 1.0ms pulse (5% Duty Cycle) commands the servo to move to 0 degrees.
- A 2.0ms pulse (10% Duty Cycle) commands it to move to 180 degrees.
By precisely tweaking the CCR register, you can steer a robot with micro-degree precision.

## 6. Example
*(See `examples/` for a visual timeline of the Timer counting).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
