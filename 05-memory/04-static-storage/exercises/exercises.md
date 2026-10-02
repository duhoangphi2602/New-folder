# Exercises: Static Storage Duration

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Initialization Trap
A developer writes a state machine that relies on a static variable to track the current state:
```cpp
void run_state_machine() {
    static int state = 0;
    
    if (state == 0) {
        state = 1;
        // Do init...
    } else if (state == 1) {
        // Do work...
    }
}
```
**Task:** The code works perfectly. However, the system requires a "Software Reset" feature that restarts the logic without physically rebooting the hardware. If the developer simply calls `run_state_machine()` again after a software reset, why will the state machine fail to run its initialization logic?

## Exercise 2: `static` vs `extern`
You are writing a driver split across two files: `uart.cpp` and `main.cpp`.
Inside `uart.cpp`, you declare a global variable: `int uart_baud_rate = 9600;`
Inside `main.cpp`, a junior developer accidentally declares: `int uart_baud_rate = 115200;`
**Task:** When the compiler tries to build this, it will throw a fatal "Multiple Definition" Linker error. How can you use the `static` keyword in `uart.cpp` to solve this collision and "hide" the variable?
