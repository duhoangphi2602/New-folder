# GPIO (General Purpose Input/Output)

## What is this topic?
This topic covers **GPIO**, the most fundamental hardware peripheral of any microcontroller. It allows the software to physically interact with the outside world by reading voltages (Input) or outputting voltages (Output) on the physical pins of the chip.

## Why is it important?
Every other peripheral (UART, SPI, I2C, Timers) relies on GPIO pins to physically connect to the outside world. If you cannot configure a pin as an output to blink an LED, or as an input to read a button, you cannot build an embedded system.

## Prerequisites
- [04-volatile-in-isr](../../08-interrupt-isr/04-volatile-in-isr/README.md)
- [03-structural-data](../../03-structural-data/README.md) (Bitwise Operations)

## Learning Outcomes
1. Configure a GPIO pin as Input, Output, or Alternate Function.
2. Understand the electrical concepts of Pull-Up and Pull-Down resistors.
3. Understand the difference between Push-Pull and Open-Drain output modes.
