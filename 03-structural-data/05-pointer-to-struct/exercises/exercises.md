# Exercises: Pointer to Struct

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Dot Precedence Trap
A developer wants to modify the `speed` member of a `Motor` struct via a pointer. They write this:
```cpp
struct Motor { int speed; };

void set_speed(Motor* m_ptr) {
    *m_ptr.speed = 100; 
}
```
**Task:** This code will not compile. Explain exactly why the compiler rejects `*m_ptr.speed`, and provide two different ways to fix the syntax.

## Exercise 2: Hardware Modeling
You are designing a driver for an I2C peripheral. The base address is `0x40005400`. The peripheral has two 32-bit registers: `CR1` (Control Register) at offset `0x00`, and `CR2` at offset `0x04`.
**Task:** Write the C++ code to:
1. Define the struct that models these two registers.
2. Define a `const` pointer to this struct that points to the hardware base address (use `reinterpret_cast`).
3. Write a single line of code that uses the arrow operator to set `CR1` to `0x01`.
