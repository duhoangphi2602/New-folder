# Exercises: Declaration vs Definition

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Spot the Violation
Look at the following code snippet. 
```cpp
// file: math_utils.h
#pragma once
int multiply(int a, int b) {
    return a * b;
}
```
`math_utils.h` is included in `main.cpp` and `calculator.cpp`. 
**Task:** Will this compile? Will it link? Explain what rule is violated and how to fix it in two different ways.

## Exercise 2: Global Variables
You need a global variable `bool is_system_running` that can be read and modified by multiple source files (`main.cpp`, `sensor.cpp`, `motor.cpp`).

**Task:** Write the code for what goes in `system_state.h` and what goes in `system_state.cpp` to correctly share this variable without violating ODR.

## Exercise 3: Forward Declaration
You have a class `Wheel` and a class `Car`. A `Car` has 4 wheels.
```cpp
// car.h
#pragma once
class Wheel; // Forward declaration

class Car {
private:
    Wheel wheels[4];
};
```
**Task:** Will `car.h` compile? Why or why not? What if `wheels` was changed to `Wheel* wheels[4]`?
