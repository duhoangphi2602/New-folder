# Interview Questions: PWM

## 1. How does a digital microcontroller, which can only output 3.3V or 0V, use PWM to make an LED appear 50% bright to the human eye?
**Answer:** The microcontroller toggles the physical GPIO pin between 3.3V and 0V at a frequency much faster than the human eye can perceive (e.g., 1,000 times a second). To achieve 50% brightness, the microcontroller sets the Duty Cycle to 50%, meaning the pin is outputting 3.3V for exactly half the time, and 0V for the other half. The human eye and brain chemically average the rapidly flashing light, perceiving it as a constant, smooth 50% brightness.

## 2. In terms of hardware Timer registers, what is the specific function of the ARR and the CCR in generating a PWM signal?
**Answer:** The **ARR (Auto-Reload Register)** determines the overall Frequency of the PWM signal. It acts as the ceiling; when the timer counts up and hits the ARR value, the timer resets to 0 and the GPIO pin is forced HIGH to begin a new cycle. 
The **CCR (Capture/Compare Register)** determines the Duty Cycle (the width of the pulse). While the timer is counting up, the hardware constantly compares the timer value to the CCR. The exact microsecond they match, the hardware flips the GPIO pin LOW. By altering the CCR relative to the ARR, you control the exact percentage of time the pin spends HIGH versus LOW.

## 3. What is the fundamental difference between using PWM to control an LED versus using PWM to control a Servo Motor?
**Answer:** 
- For an **LED**, the overall frequency doesn't strictly matter (as long as it's > 100 Hz to prevent visible flickering). The brightness is determined purely by the *percentage* of the Duty Cycle (e.g., 50% duty cycle is half power).
- For a **Servo Motor**, the overall frequency is strictly mandated by the hardware (usually exactly 50 Hz). Furthermore, the servo ignores the percentage; it cares only about the *absolute time duration* of the HIGH pulse. A 1.5 millisecond HIGH pulse means "go to 90 degrees", regardless of how long the rest of the 50 Hz cycle is.
