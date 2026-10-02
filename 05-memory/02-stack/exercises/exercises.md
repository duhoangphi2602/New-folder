# Exercises: The Stack

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Stack Frame
When a CPU executes a function call, it pushes a "Stack Frame" into RAM.
**Task:** Name three distinct pieces of information that the CPU stores inside a Stack Frame. (Hint: How does it know where to go when the function finishes?)

## Exercise 2: Recursion
In typical computer science classes, students are taught to use Recursion (a function calling itself) to solve problems like calculating factorials or traversing trees.
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```
**Task:** In professional bare-metal embedded programming (like MISRA C++ standards), recursion is strictly **banned**. Why is recursion completely unacceptable on a microcontroller?
