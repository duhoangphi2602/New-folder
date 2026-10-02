# Exercises: Priority Inversion

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Mars Pathfinder Fix
When the Mars Pathfinder was resetting on Mars due to Priority Inversion, NASA engineers did not send a new firmware binary to the rover. Instead, they flipped a single boolean flag in the C code from `false` to `true` using a debug terminal. 
**Task:** Based on your knowledge of FreeRTOS/VxWorks mechanisms, what specific feature do you think they enabled via that flag to save the mission?

## Exercise 2: Binary Semaphores
A developer uses a `Binary Semaphore` instead of a `Mutex` to protect a shared I2C bus. Task L (Priority 1) takes the semaphore. Task H (Priority 10) tries to take it and blocks. 
**Task:** Explain mechanistically why the RTOS *cannot* apply Priority Inheritance to Task L in this scenario.
