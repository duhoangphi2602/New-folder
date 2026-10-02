# Exercises: Embedded I/O Overview

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Standard
In a typical desktop C program, `printf` outputs to `stdout` (the console). In embedded programming, where does `stdout` physically go by default if you do not configure anything?

## Exercise 2: Communication Protocols
You are designing an embedded system. Match the following requirements to the most appropriate serial protocol (UART, SPI, or I2C):
1. You need to read data from a temperature sensor. Speed doesn't matter, but you want to use the fewest number of wires possible.
2. You need to dump debugging logs (`printf`) to your laptop so you can read them.
3. You need to rapidly write megabytes of image data to a high-speed LCD screen.
