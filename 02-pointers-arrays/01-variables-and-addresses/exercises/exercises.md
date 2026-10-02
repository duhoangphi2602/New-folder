# Exercises: Variables and Addresses

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Stack Addresses
Write a simple C++ program with the following variables declared consecutively inside `main()`:
```cpp
uint32_t a = 1;
uint32_t b = 2;
uint32_t c = 3;
```
Print the addresses of `a`, `b`, and `c`. 
**Task:** Are the addresses increasing or decreasing? What is the exact mathematical difference (in bytes) between the address of `a` and the address of `b`? Explain why.

## Exercise 2: `cout` and `uint8_t`
A junior developer writes this code:
```cpp
uint8_t status = 5;
std::cout << "Address: " << &status << "\n";
```
Instead of printing a hexadecimal address like `0x7ffeefbff5a8`, the terminal prints a weird invisible character or garbage text. 
**Task:** Why does `std::cout` do this for `uint8_t` (which is often aliased to `unsigned char`), and how do you force it to print the actual memory address?
