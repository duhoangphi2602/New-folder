# Exercises: Volatile vs Atomic

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Boolean Flag Exception
You have a global variable: `volatile bool is_pressed = false;`.
An Interrupt Service Routine executes `is_pressed = true;`. 
The main loop checks `if (is_pressed)`.
**Task:** This variable is NOT atomic. However, in standard 32-bit embedded systems (like ARM Cortex-M), this specific code is perfectly safe and will not suffer a Race Condition. Why is a simple boolean write inherently safe even without `std::atomic`?

## Exercise 2: Selecting the right tool
For each of the following scenarios, state whether you should use `Normal`, `volatile`, `std::atomic`, or a `Mutex`.
1. A pointer holding the memory address of the I2C Data Register (`0x40005410`).
2. A 32-bit integer keeping track of the total uptime in seconds, which is incremented by a Timer ISR, and read by an RTOS task.
3. A large 1024-byte `struct` representing network configuration data, read and written by three different RTOS tasks (No ISRs involved).
