# Exercises: Professional Logging

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Zero Overhead
You have the following code in a motor control loop:
```cpp
void loop() {
    int speed = read_encoder();
    LOG_DEBUG("Speed is: %d", speed);
    set_motor(speed);
}
```
If you compile this with `#define ACTIVE_LOG_LEVEL LEVEL_INFO` (which disables DEBUG logs), exactly how much CPU time will the `LOG_DEBUG` line consume? Why?

## Exercise 2: `__func__`
In addition to `__FILE__` and `__LINE__`, the C/C++ standard provides `__func__` (or `__FUNCTION__` in some compilers). 
**Task:** Write a single `LOG_ERROR` macro that prints the word "[ERROR]", followed by the name of the function where the error occurred (using `__func__`), followed by the formatted user message.
