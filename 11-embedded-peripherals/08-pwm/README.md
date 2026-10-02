# PWM (Pulse Width Modulation)

## What is this topic?
This topic introduces **PWM**, a technique used to simulate analog voltages and control power delivery using purely digital signals. 

## Why is it important?
Digital pins can only output 3.3V (Full Power) or 0.0V (Off). If you want to dim an LED to 50% brightness, or control the speed of a DC motor, you cannot output 1.65V digitally. PWM solves this by rapidly turning the 3.3V pin ON and OFF thousands of times a second.

## Prerequisites
- [01-gpio](../01-gpio/README.md)
- [07-timers](../07-timers/README.md)

## Learning Outcomes
1. Define Frequency vs Duty Cycle.
2. Understand how hardware Timers and the CCR (Capture/Compare Register) generate PWM.
3. Apply PWM to dim LEDs and control Servo motors.
