# Exercises: std::atomic

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Multiple Flag Problem
You are designing an embedded system for a coffee machine. 
You have two `std::atomic` variables:
```cpp
std::atomic<bool> is_water_hot = false;
std::atomic<bool> is_cup_present = false;
```
Task A monitors sensors and updates these flags. 
Task B (The Dispenser) runs this code:
```cpp
if (is_water_hot && is_cup_present) {
    dispense_coffee();
}
```
**Task:** Even though both variables are `std::atomic`, this code contains a critical concurrency bug that could result in pouring boiling water everywhere. What is the bug, and why did `std::atomic` fail to prevent it?

## Exercise 2: `is_lock_free()`
The C++ standard library provides a function: `my_atomic_var.is_lock_free()`.
You declare `std::atomic<uint32_t> counter;` and `std::atomic<MyLargeStruct> config;`.
**Task:** If you print `.is_lock_free()` for both variables on a standard 32-bit microcontroller, what will the output be, and what does it physically mean for the embedded system?
