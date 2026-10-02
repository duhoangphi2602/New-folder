# Exercises: Function Pointers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Typedef Translation
Translate the following C-style `typedef` into the modern C++11 `using` syntax.
```c
typedef float (*math_op_t)(float, float);
```

## Exercise 2: The Null Pointer Crash
A driver provides the following API:
```c
void exti_register_callback(void (*cb)(void));
```
An application calls `exti_register_callback(NULL);` to disable the interrupt behavior.
Later, the hardware interrupt fires, and the driver executes this code:
```c
void EXTI_IRQHandler(void) {
    // Acknowledge hardware flag...
    user_callback(); // Executes the callback
}
```
**Task:** What will happen? How must the driver author fix the `EXTI_IRQHandler` implementation?

## Exercise 3: Lambdas vs Function Pointers
You are writing C++ firmware. A C-driver requires a function pointer callback:
```cpp
extern "C" void set_timer_isr( void (*isr_cb)(void) );
```
You want to use a lambda to toggle a specific GPIO pin that is passed into your setup function:
```cpp
void setup_timer(int pin_number) {
    set_timer_isr( [pin_number]() {
        toggle_gpio(pin_number);
    });
}
```
**Task:** This code will fail to compile. Why? What rule governs the conversion of C++ lambdas to C function pointers?
