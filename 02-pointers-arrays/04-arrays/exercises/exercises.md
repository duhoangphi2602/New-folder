# Exercises: Arrays

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding Array Length
In C/C++, C-style arrays do not have a built-in `.length()` method. 
Write the standard C-style macro or mathematical expression used to calculate the number of elements in an array at compile time. Given:
```cpp
uint32_t my_array[17];
```
How do you dynamically calculate `17` using the `sizeof` operator?

## Exercise 2: Out of Bounds
What happens when you execute the following code? Does the compiler stop you?
```cpp
uint32_t scores[3] = {10, 20, 30};
scores[5] = 99;
```

## Exercise 3: Zero Initialization
A developer wants an array of 100 integers, all initialized to the number `5`. They write:
```cpp
int buffer[100] = {5};
```
**Task:** What are the actual values of `buffer[0]`, `buffer[1]`, and `buffer[99]` after this line executes?
