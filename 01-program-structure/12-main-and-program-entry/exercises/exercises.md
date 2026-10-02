# Exercises: main() and Program Entry

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Accidental Return
A junior developer writes this firmware for a smart thermostat:
```cpp
int main(void) {
    sensor_init();
    display_init();

    int temp = read_temperature();
    if (temp > 100) {
        display_warning("FIRE!");
        return -1; // Abort program due to critical error
    }

    while (1) {
        // normal operation loop
    }
}
```
**Task:** Explain what will happen to the microcontroller if the temperature exceeds 100 degrees. What is the correct way to handle this critical error in a bare-metal environment?

## Exercise 2: `argc` and `argv`
In desktop C++, `main` is usually defined as `int main(int argc, char** argv)`.
In bare-metal embedded C++, it is usually defined as `int main(void)`.
**Task:** Why doesn't the bare-metal version use `argc` and `argv`?

## Exercise 3: Order of Operations
Put the following events in the exact chronological order they occur when an ARM Cortex-M microcontroller is powered on:
A. `main()` is called.
B. The CPU hardware jumps to the Reset Vector address.
C. Global C++ constructors are called.
D. The Super Loop begins executing.
E. Global variables are copied from Flash to RAM.
