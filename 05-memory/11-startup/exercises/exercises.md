# Exercises: The Startup Code

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Global Pointers
You declare a global pointer to a hardware register:
`volatile uint32_t* hw_register;`
You forget to initialize it.
**Task:** Based on what you know about the `.bss` segment and the Startup Code, what exact memory address will this pointer point to when `main()` starts? What happens if you try to write to it (`*hw_register = 5;`)?

## Exercise 2: Global Constructors
You have a global C++ class `Logger` with a constructor that sends a "System Booting" message over the UART serial port.
```cpp
Logger system_logger; // Global
```
**Task:** The hardware UART peripheral requires a clock signal to be turned on before it can transmit data. Usually, you turn on this clock inside `main()`. Why will this specific global object cause the system to crash during the Startup Code?
