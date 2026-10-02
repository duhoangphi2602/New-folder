# Exercises: Lambda

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Dangling Capture
Look at the following code snippet:
```cpp
#include <functional>

std::function<void()> create_counter() {
    int local_count = 0;
    return [&local_count]() {
        local_count++;
        std::cout << local_count << "\n";
    };
}

int main() {
    auto my_counter = create_counter();
    my_counter(); 
}
```
**Task:** What will happen when `my_counter()` is executed in `main()`? Why? How can you fix it?

## Exercise 2: `mutable` Keyword
By default, if you capture a variable by value `[x]`, the lambda treats it as `const` and you cannot modify it.
**Task:** Write a simple lambda that captures an integer `int strikes = 0;` by value, increments it inside the lambda, and prints it. You will need to use a specific keyword to make the compiler allow this.

## Exercise 3: Sorting with Lambdas
You have an array of struct:
```cpp
struct Task { int priority; };
Task tasks[3] = {{3}, {1}, {2}};
```
**Task:** Use the standard C++ `std::sort` function (which takes pointers and a comparison function) to sort the `tasks` array by priority (lowest to highest). Use an inline lambda for the comparison logic.
