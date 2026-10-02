# Exercises: Namespace

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Global Pollution Bug
A junior developer writes the following header file for a math utility:
```cpp
// math_util.h
#pragma once
#include <cmath>

using namespace std;

float calculate_distance(float x, float y);
```
**Task:** Why is `using namespace std;` inside this header file considered a catastrophic practice in large codebases? Give a concrete example of how it could break compilation for another developer.

## Exercise 2: C++17 Refactoring
Refactor the following nested namespaces into the modern C++17 syntax.
```cpp
namespace Drivers {
    namespace Sensors {
        namespace I2C {
            class TemperatureSensor {
                // ...
            };
        }
    }
}
```
**Task:** Write the equivalent code using C++17 features.

## Exercise 3: Internal Linkage
You are tasked with writing a helper function `crc32()` inside `uart_driver.cpp`. This function should NEVER be accessible to other parts of the program.
**Task:** Write two different ways to achieve this data hiding (one using a C keyword, and one using a C++ feature). Which one is generally preferred in modern C++?
