# Exercises: Semaphore

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing Events
A hardware UART peripheral triggers an ISR every time a byte is received. 
The ISR "Gives" a Binary Semaphore. 
The Task "Takes" the Semaphore and prints the byte. 
**Task:** If the hardware receives 3 bytes extremely quickly (in 10 microseconds), but the Task takes 50 microseconds to wake up and process a byte, what will happen to the 2nd and 3rd Semaphore signals? 

## Exercise 2: Counting Solution
**Task:** How could you solve the problem in Exercise 1 using a different type of Semaphore? Explain the mechanical difference in how it would operate.
