# Exercises: Race Conditions

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Danger
Examine the following 4 snippets of code. Assume `x`, `arr`, and `flag` are global variables shared between an RTOS Task and an ISR. Which of these are susceptible to Race Conditions?
1. `uint8_t flag = 1;` (On a 32-bit ARM Cortex-M)
2. `x = x * 2;`
3. `arr[i] = 5;`
4. `if (x == 5) { do_something(); }`

## Exercise 2: The Silent Symptom
**Task:** Why are Race Conditions notoriously difficult to reproduce and debug during the software testing phase?
