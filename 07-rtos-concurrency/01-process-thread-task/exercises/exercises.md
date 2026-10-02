# Exercises: Process, Thread, and Task

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Crash Blast Radius
An engineer writes two programs. 
Program A is a Python script running on a Raspberry Pi (Linux). It runs a heavy data-processing Thread.
Program B is C++ firmware running on an STM32 (FreeRTOS). It runs a heavy data-processing Task.
Both the Thread and the Task accidentally attempt to read a NULL pointer (`*ptr = 5`), causing a fatal memory fault.
**Task:** Describe the "blast radius" of the crash in both systems. What happens to the other running threads/tasks on the Raspberry Pi vs the STM32?

## Exercise 2: Stack Allocation
When you spawn an RTOS Task in FreeRTOS using `xTaskCreate`, you must explicitly tell the RTOS how big the Task's Stack should be (e.g., 256 words).
**Task:** If a system has 4 Tasks, how many Stacks does the system have? If you oversize every Stack "just to be safe", what resource will you immediately run out of?
