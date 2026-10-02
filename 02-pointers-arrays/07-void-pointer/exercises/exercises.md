# Exercises: void Pointer

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Generic Swap
You want to write a function that can swap the bytes of any two variables of the same size. 
```cpp
void generic_swap(void* a, void* b, size_t size) {
    // Implementation here
}
```
**Task:** Explain step-by-step how you would implement the body of this function. Why can't you just write `void* temp = *a; *a = *b; *b = temp;`?

## Exercise 2: C++ Strictness
A C developer is migrating an old embedded codebase to compile with a C++17 compiler (`g++`). They have hundreds of lines of code that look like this:
```c
uint8_t* buffer = malloc(1024);
```
**Task:** When they run the C++ compiler, this line generates an error. What is the error, why does C++ enforce this rule, and how must they fix the line of code?
