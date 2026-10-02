# Exercises: Watchdog

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Bootloader Trap
You write a custom Bootloader. The bootloader turns on the Independent Watchdog (IWDG) with a 2-second timeout, verifies the firmware, and then jumps to the main Application code.
The main Application code was written by a junior developer who did not know the watchdog existed. The Application code does not contain any code to "kick the dog".
**Task:** What will happen exactly 2 seconds after the Application code starts running? Can the Application code simply execute a command to disable the IWDG?

## Exercise 2: RTOS Multi-Threaded Watchdog
You are using an RTOS (Real-Time Operating System) with 3 separate threads:
1. `Thread_Sensors`
2. `Thread_WiFi`
3. `Thread_UI`
You initialize the Watchdog Timer with a 5-second timeout.
**Task:** Where should you place the "Kick" command? 
If you put the kick command inside `Thread_Sensors`, what happens if the `Thread_WiFi` gets permanently stuck in an infinite loop? 
Propose an architecture that ensures the watchdog resets the system if *any single thread* crashes, but stays alive if all 3 threads are healthy.
