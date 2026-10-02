# Exercises: Pointer Basics

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Follow the Pointers
Trace the following code without running it. What are the final values of `a` and `b`?
```cpp
int a = 10;
int b = 20;
int* p1 = &a;
int* p2 = &b;

*p1 = *p2;
*p2 = 30;
p1 = p2;
*p1 = 40;
```

## Exercise 2: Type Sizes
Assume you are programming on a 32-bit ARM Cortex-M4 microcontroller.
You have the following variables:
```cpp
uint8_t   val_a = 5;
uint32_t  val_b = 10;
uint8_t*  ptr_a = &val_a;
uint32_t* ptr_b = &val_b;
```
**Task:** What is the output of the following operations?
1. `sizeof(val_a)`
2. `sizeof(val_b)`
3. `sizeof(ptr_a)`
4. `sizeof(ptr_b)`

## Exercise 3: The Danger of Uninitialized Pointers
A junior developer writes this code:
```cpp
void update_sensor() {
    int* status_ptr;
    *status_ptr = 1;
}
```
**Task:** This code will compile successfully, but what will happen when it is executed? Why is this significantly more dangerous than forgetting to initialize a normal `int` variable?
