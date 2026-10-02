# Exercises: nullptr

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hardware Reset Bug
You are writing a driver for a sensor. The driver takes a pointer to a callback function that it fires when data is ready. If no callback is needed, the user should pass a null pointer.
```cpp
void set_callback(void (*cb)()) {
    // ... logic ...
}

void set_callback(int interrupt_priority) {
    // ... logic ...
}
```
**Task:** A user calls `set_callback(NULL);` intending to disable the callback. What happens and why?

## Exercise 2: `std::nullptr_t`
You want to write a function that *only* accepts `nullptr` as an argument (perhaps as a specialized template overload). 
**Task:** What is the exact data type of `nullptr` in C++ that you would use in the function signature?
