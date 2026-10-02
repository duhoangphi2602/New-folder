# UART Serial Communication

## What is this topic?
This topic delves into **UART (Universal Asynchronous Receiver-Transmitter)**, the most ubiquitous and historically significant hardware communication protocol in the embedded world. 

## Why is it important?
UART is the absolute bedrock of embedded debugging. When you want your microcontroller to print log messages to your PC screen, you use UART. When you want to talk to a Bluetooth module, a GPS receiver, or a 4G cellular modem, you use UART. Every embedded software engineer must deeply understand how UART transmits data and how to write a basic UART driver.

## Prerequisites
- [04-embedded-io-overview](../04-embedded-io-overview/README.md)
- [14-memory-mapped-register](../../02-pointers-arrays/14-memory-mapped-register/README.md)

## Learning Outcomes
1. Understand the hardware structure of UART (TX, RX, Baud Rate).
2. Learn how UART wraps raw data bytes in Start and Stop bits.
3. Observe how a basic Blocking UART driver is implemented in C++.
