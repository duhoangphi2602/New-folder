# Exercises: I/O Buffering

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Infinite Loop Trap
A developer writes a loop to monitor a sensor:
```cpp
while (true) {
    int val = read_sensor();
    printf("Val: %d  ", val);
    delay_ms(100);
}
```
When they run this on their embedded system connected via UART, absolutely nothing appears on the screen for the first 30 seconds. Suddenly, a massive block of hundreds of readings appears all at once. Then nothing for another 30 seconds.
**Task:** Explain exactly why this behavior is occurring. How do you fix it with one character?

## Exercise 2: `stdout` vs `stderr`
You are writing a bootloader. When a critical memory corruption is detected, the bootloader must halt the system.
```cpp
if (corruption_detected) {
    fprintf(stdout, "CRITICAL FAULT DETECTED!");
    halt_cpu();
}
```
**Task:** What is the fatal flaw in this error logging code? Rewrite the `fprintf` line to guarantee the message is visible before the CPU halts.
