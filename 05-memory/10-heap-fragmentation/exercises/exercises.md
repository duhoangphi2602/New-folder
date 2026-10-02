# Exercises: Heap Fragmentation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Root Cause
Two junior developers are arguing. 
Developer A says: "Fragmentation happens because we forgot to call `free()` on our pointers."
Developer B says: "Fragmentation happens because we are allocating and freeing chunks of memory that are all different sizes over a long period of time."
**Task:** Who is right? What is Developer A actually describing?

## Exercise 2: Internal vs External
You decide to use an RTOS Memory Pool to solve fragmentation. The pool is configured to only hand out chunks in exactly 128-byte sizes.
You have a function that receives UART commands. Most commands are 10 bytes long. Sometimes, a command is 100 bytes long.
**Task:** 
1. When you request a block for a 10-byte command, how much RAM is wasted? What type of fragmentation is this?
2. Why is this specific type of waste considered acceptable in aerospace engineering, while the original `malloc` waste is banned?
