# Exercises: Fixed-Width Integers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Overflow Bug
A junior developer wrote a timeout function for an ARM Cortex-M CPU (where `int` is 32-bit):
```c
void delay_ms(int milliseconds) {
    // Wait...
}
```
Five years later, the code is ported to an 8-bit Microchip AVR (where `int` is 16-bit). A task requests a 60-second delay: `delay_ms(60000);`
**Task:** Explain what will mechanically happen when this code runs on the 8-bit processor.

## Exercise 2: Selecting Types
You are writing a driver for a new GPS module. Which `<cstdint>` type should you use for the following variables?
1. `latitude_microdegrees` (Values range from -90,000,000 to +90,000,000).
2. `num_satellites_visible` (Values range from 0 to 24).
3. `uptime_milliseconds` (The device must run continuously for up to 2 years without overflowing).
