# SPI (Serial Peripheral Interface)

## What is this topic?
This topic covers **SPI**, a high-speed, synchronous serial communication protocol. It is the de-facto standard for interfacing microcontrollers with sensors, external flash memory, and LCD screens.

## Why is it important?
While UART is great for sending text to a PC, it is too slow and inefficient for hardware-to-hardware communication. SPI is blindingly fast (often 10-50+ MHz). Understanding SPI's Master/Slave architecture and its shift-register mechanics is essential for writing bare-metal driver code.

## Prerequisites
- [02-uart](../02-uart/README.md)

## Learning Outcomes
1. Define the 4 standard SPI wires (MOSI, MISO, SCK, CS/SS).
2. Understand the synchronous Master/Slave architecture.
3. Understand the concept of circular Shift Registers (Every transmission is simultaneously a reception).
