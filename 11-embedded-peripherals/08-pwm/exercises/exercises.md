# Exercises: PWM

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Fading LED
You want to make an LED "breathe" (smoothly fade from 0% to 100% brightness, and back down to 0% over 2 seconds).
You configure a Timer to generate a 10 kHz PWM signal with an `ARR` of `1000`.
You write a `while(1)` loop in your `main()` function to constantly change the `CCR` register from 0 to 1000.
**Task:** Why is putting this logic in the `main()` `while(1)` loop a bad architectural design? How can you use a **second** hardware timer (and its interrupt) to perfectly automate the fading without blocking the main loop?

## Exercise 2: Servo Math
A standard SG90 Servo motor requires a precise **50 Hz** PWM signal. 
The servo moves based on the exact width of the HIGH pulse:
- 1000 microseconds (1.0 ms) = 0 degrees
- 2000 microseconds (2.0 ms) = 180 degrees
Your timer ticks at exactly **1 MHz** (1 tick = 1 microsecond). 
**Task:** 
1. What must you set the `ARR` register to in order to achieve the 50 Hz frequency?
2. What must you set the `CCR` register to in order to turn the servo exactly to **90 degrees** (center position)?
