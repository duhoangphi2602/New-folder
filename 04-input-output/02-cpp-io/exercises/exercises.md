# Exercises: C++ Standard I/O

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hex Trap
A developer wants to print three numbers: the memory address in Hex, followed by two sensor values in Decimal.
```cpp
int addr = 0xAA;
int val1 = 15;
int val2 = 20;

std::cout << std::hex << addr << "\n";
std::cout << val1 << "\n";
std::cout << val2 << "\n";
```
**Task:** What will exactly be printed to the screen by the last two lines (`val1` and `val2`)? Why is this behavior confusing to beginners coming from `printf`?

## Exercise 2: Newline vs Flush
Explain the technical difference in execution between these two lines of code:
```cpp
std::cout << "Processing data...\n";
std::cout << "Processing data..." << std::endl;
```
When should you use `std::endl`?
