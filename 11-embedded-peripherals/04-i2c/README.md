# I2C (Inter-Integrated Circuit)

## What is this topic?
This topic covers **I2C** (often pronounced I-squared-C), a highly popular synchronous serial protocol. It is slower than SPI but drastically reduces hardware complexity by requiring only 2 wires to connect up to 127 devices.

## Why is it important?
Sensors (accelerometers, gyroscopes, OLED screens, EEPROMs) heavily favor I2C because it saves pins on the microcontroller. While SPI requires a new physical wire (CS) for every device you add, I2C uses software addresses, allowing you to daisy-chain dozens of devices onto the exact same two wires. 

## Prerequisites
- [01-gpio](../01-gpio/README.md) (Specifically Open-Drain)
- [03-spi](../03-spi/README.md)

## Learning Outcomes
1. Define the 2 standard I2C wires (SDA, SCL).
2. Understand why Open-Drain GPIO and external Pull-Up resistors are strictly mandatory.
3. Trace the sequence of an I2C transaction (Start, Address, ACK, Data, Stop).
