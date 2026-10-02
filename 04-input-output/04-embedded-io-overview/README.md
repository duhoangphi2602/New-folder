# Embedded I/O Overview

## What is this topic?
This topic provides a high-level overview of how physical Input/Output actually works on a bare-metal microcontroller, contrasting it with PC development.

## Why is it important?
When you type `std::cout << "Hello"` on a PC, an operating system (Linux/Windows) takes over, manages the USB drivers, renders fonts on a GPU, and lights up pixels on a monitor. On an embedded microcontroller, there is no OS, no monitor, and no standard "console". You have to manually route bits out of a specific physical metal pin on the chip. Understanding the landscape of embedded I/O (GPIO, UART, SPI, I2C) is the bridge between software code and physical hardware.

## Prerequisites
- [14-memory-mapped-register](../../02-pointers-arrays/14-memory-mapped-register/README.md)

## Learning Outcomes
1. Understand the difference between PC I/O and Embedded I/O.
2. Differentiate between Digital (GPIO) and Serial (UART/SPI/I2C) communication.
3. Understand how memory-mapped registers act as the "API" for physical hardware pins.
