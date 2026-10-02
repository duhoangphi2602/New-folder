# Exercises: Constructor Initialization

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hardware Crash
You write a `SystemClock` class that configures the PLL to run the MCU at 72MHz. You also write an `I2C_Driver` class that initializes the I2C peripheral. 
The I2C peripheral hardware requires the system clock to be running at 72MHz before it can be configured.
You instantiate both as globals:
```cpp
I2C_Driver g_i2c;
SystemClock g_clock;
```
**Task:** Why might this code cause a Hard Fault before `main()` even begins?

## Exercise 2: Meyer's Singleton Drawback
Meyer's Singleton (using a `static` local variable inside a function) is the standard C++ solution for lazy initialization.
```cpp
Uart& get_uart() {
    static Uart instance;
    return instance;
}
```
**Task:** Think deeply about the assembly code the compiler must generate to make this work. Every time `get_uart()` is called, the CPU must guarantee it doesn't call the constructor again. What hidden runtime cost does this introduce on every single access to `get_uart()`?

## Exercise 3: Global Destructors
In a desktop C++ application, when `main()` returns, the C runtime loops through `.fini_array` to call all global destructors, cleaning up memory.
**Task:** Why does an embedded bare-metal build system often use linker flags to explicitly strip out and delete the `.fini_array` entirely?
