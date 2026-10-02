# Exercises: const and Pointers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Read Right-to-Left
Translate the following C++ declarations into plain English using the right-to-left reading rule:
1. `float const * ptr;`
2. `char * const ptr;`
3. `const uint16_t * const ptr;`

## Exercise 2: API Design
You are writing a driver for a cryptographic hashing peripheral (like SHA-256). 
The function needs to take an input buffer (the data to hash), an output buffer (where to write the 32-byte hash result), and the length of the input data.
**Task:** Write the exact function signature (name, return type, and arguments). Use `const` appropriately to guarantee to the user that their input data will not be corrupted by your driver.

## Exercise 3: The Compile Error
A developer writes this code:
```cpp
const char* greeting = "Hello World";
char* modifier = greeting;
modifier[0] = 'h';
```
**Task:** The compiler will throw an error on line 2. What is the error, and why is the compiler protecting the developer here?
