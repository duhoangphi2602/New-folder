# Exercises: Mutex

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The ISR Crash
A developer has a shared buffer protected by a Mutex. 
Task A takes the Mutex, writes to the buffer, and gives the Mutex.
A UART Hardware Interrupt (ISR) fires when a byte arrives. The ISR tries to take the Mutex, writes the byte to the buffer, and gives the Mutex.
**Task:** When the developer runs this code, the system immediately triggers a Hard Fault and reboots when the ISR fires. Explain mechanistically why a Mutex can NEVER be used inside an ISR.

## Exercise 2: State Transitions
Task B (Priority 2) is RUNNING. It attempts to take a Mutex that is currently owned by Task A (Priority 2).
**Task:** Describe the exact change in Task B's RTOS State (Running, Ready, Blocked, Suspended). Does Task B consume any CPU cycles while it is waiting for the Mutex?
