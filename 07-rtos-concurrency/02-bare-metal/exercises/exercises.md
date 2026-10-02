# Exercises: Bare-Metal Programming

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Infinite Latency Bug
A developer writes the following Super Loop:
```cpp
void main() {
    while(1) {
        read_gps();
        write_to_sd_card(); // Takes 50 milliseconds
        update_display();
    }
}
```
**Task:** The GPS hardware sends a new byte of data over UART every 2 milliseconds. The UART hardware only has a 1-byte buffer. Will this Super Loop successfully read the GPS data? Why or why not?

## Exercise 2: Solving the Bug
**Task:** How would you re-architect the system from Exercise 1 to ensure that no GPS bytes are lost, *without* upgrading to an RTOS? (Hint: Think about hardware capabilities outside of the `main()` function).
