# Exercises: Atomic Operations

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Limit
A developer wants to use `std::atomic` to protect an array of 5 temperature readings so they can be safely read from an I2C task without using a slow Mutex. 
```cpp
struct TempData {
    int t1, t2, t3, t4, t5;
};
std::atomic<TempData> my_data;
```
**Task:** Will this code actually provide hardware-level lock-free atomicity on a 32-bit Cortex-M4? Why or why not?

## Exercise 2: Compare-and-Swap (Advanced)
A core feature of `<atomic>` is the `compare_exchange_weak` function, which atomically does the following: *"Look at the variable. If it equals X, change it to Y. Otherwise, do nothing and return false."*
**Task:** Why is this combined "Check-then-Set" operation mathematically required to be atomic? What Race Condition would occur if you just used a standard `if(var == X) { var = Y; }` statement?
