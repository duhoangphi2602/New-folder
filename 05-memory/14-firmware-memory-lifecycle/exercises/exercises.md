# Exercises: Firmware Memory Lifecycle

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Giant Array
You want to store a 50KB pre-calculated sine-wave audio file on a microcontroller that has 32KB of RAM and 128KB of Flash.
1. If you declare `uint8_t audio[50000];` inside `main()`, what specific memory crash will happen?
2. If you declare `uint8_t audio[50000];` globally, what specific linker error will happen?
3. What exact C++ keyword must you add to make this compile and run successfully?

## Exercise 2: System Architecture Review
Explain the relationship between the **Linker Script**, the **Vector Table**, and the **Startup Code**. How do these three distinct files work together to boot the microcontroller?
