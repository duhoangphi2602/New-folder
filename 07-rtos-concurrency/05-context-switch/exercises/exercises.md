# Exercises: Context Switching

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Floating Point Penalty
You are running FreeRTOS on a Cortex-M4F (which includes a hardware Floating Point Unit). 
Task A only does basic integer math (e.g., `int x = 5 + 5`). 
Task B performs complex sensor trigonometry (`float y = sin(0.5)`). 
**Task:** In FreeRTOS, if you tell the RTOS that Task B uses the FPU, the context switch away from Task B will take significantly more CPU cycles than the context switch away from Task A. Mechanically, why does this happen?

## Exercise 2: Stack Usage during Switching
**Task:** When the SysTick interrupt fires and the RTOS executes a Context Switch, where exactly are the CPU registers stored? Why is this specific location chosen instead of storing them globally inside the RTOS `.data` section?
