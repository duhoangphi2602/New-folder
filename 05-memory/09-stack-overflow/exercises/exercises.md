# Exercises: Stack Overflow

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Printf Trap
A junior developer is debugging a sensor. The sensor data looks weird, so they add `printf("Sensor Value: %f\n", data);` inside the sensor reading function.
Suddenly, the microcontroller starts rebooting infinitely every time the sensor is read.
**Task:** `printf` is a massive, complex function inside the C standard library. Based on the concepts of the Call Stack, why did simply adding `printf` cause a system crash on a microcontroller with 2KB of RAM?

## Exercise 2: Watermark Canaries
You are tasked with implementing a "Stack Canary" to detect overflows. 
You fill the unused RAM with the value `0xCD`. 
**Task:** Why must this check be performed inside a periodic background loop or a low-priority RTOS task? What is the danger of waiting to check the Canary until the very end of `main()`?
