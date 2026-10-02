# Exercises: C-Style Enums

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Value
Given the following enum:
```cpp
enum PinState {
    PIN_LOW,
    PIN_HIGH,
    PIN_FLOATING = 5,
    PIN_PULLUP,
    PIN_PULLDOWN
};
```
**Task:** What are the underlying integer values of `PIN_LOW`, `PIN_HIGH`, `PIN_PULLUP`, and `PIN_PULLDOWN`?

## Exercise 2: The Name Prefix Hack
Because of Namespace Pollution, C programmers developed a strict naming convention to prevent naming collisions between different enums. 
For example, instead of naming the states of an I2C peripheral `IDLE`, `BUSY`, and `ERROR`, they named them `I2C_STATE_IDLE`, `I2C_STATE_BUSY`, and `I2C_STATE_ERROR`.
**Task:** Explain exactly why this was necessary in C. What would happen if they just used `IDLE`, and the SPI driver also used `IDLE`?
