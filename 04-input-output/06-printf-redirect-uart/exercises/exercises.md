# Exercises: Printf Redirection to UART

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The GCC Weak Attribute
In the GNU compiler, standard library hooks like `_write` are often declared with the `__attribute__((weak))` modifier. 
**Task:** Explain what a "weak" function is in C/C++, and why the designers of the standard library use it for these low-level hardware hooks.

## Exercise 2: C++ `std::cout` Redirection
While this topic focused on C's `printf`, C++'s `std::cout` can also be redirected. However, it is vastly more complicated. Instead of overriding a single `_write` function, you must create a custom class that inherits from `std::streambuf` and override its `overflow()` virtual method, then assign it to `std::cout.rdbuf()`.
**Task:** Based on your knowledge of C vs C++ from previous topics, why does redirecting `std::cout` require such a massive, object-oriented, virtual-function approach compared to the simple 5-line C function required for `printf`?
