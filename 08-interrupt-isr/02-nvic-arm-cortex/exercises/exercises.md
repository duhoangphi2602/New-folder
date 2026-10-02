# Exercises: The NVIC

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Preemption Puzzle
You configure the ARM Cortex-M NVIC with the following priorities (Lower number = Higher Priority):
- UART ISR: Priority 6
- I2C ISR: Priority 6
- Motor ISR: Priority 2

**Task 1:** The UART ISR is currently executing. The I2C interrupt fires. What does the NVIC do?
**Task 2:** The UART ISR is currently executing. The Motor interrupt fires. What does the NVIC do?

## Exercise 2: Software vs Hardware
An RTOS system has a `MotorControlTask` configured at Priority 10 (the highest possible software priority). 
The system also has a `ButtonISR` configured at NVIC Priority 15 (the absolute lowest possible hardware priority).
**Task:** The `MotorControlTask` is currently doing heavy math. The user presses the button, triggering the `ButtonISR`. Who wins the CPU, and why?
