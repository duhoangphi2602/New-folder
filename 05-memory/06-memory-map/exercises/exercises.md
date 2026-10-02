# Exercises: The Memory Map

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hard Fault
You are writing an embedded C++ program on an STM32. You accidentally write the following code:
```cpp
uint32_t* ptr = (uint32_t*)0x10000000;
*ptr = 42;
```
When this line executes, the CPU immediately crashes with a "Hard Fault" (Bus Error). 
**Task:** Look at the standard ARM memory map. Why did writing to `0x10` cause a hardware crash, whereas writing to `0x20000000` would work perfectly?

## Exercise 2: Peripherals
You want to blink an LED. You look at the datasheet and see that GPIO Port C is located at address `0x40011000`. You define a pointer:
`volatile uint32_t* GPIOC = (uint32_t*)0x40011000;`
**Task:** Why are hardware peripherals located in the `0x40000000` region instead of the `0x20000000` (RAM) region? What would happen if peripherals were mapped to the exact same addresses as RAM?
