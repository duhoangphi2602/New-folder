# UART (Universal Asynchronous Receiver-Transmitter)

## What is this topic?
This topic introduces **UART**, the most common and robust serial communication protocol used in embedded systems for debugging and PC communication.

## Why is it important?
Because bare-metal microcontrollers do not have screens, the standard `printf("Hello World")` function goes nowhere. UART is the primary bridge to send text from the microcontroller to a console on your PC, making it the most critical debugging tool in your arsenal.

## Prerequisites
- [01-gpio](../01-gpio/README.md)
- [01-interrupt-vector-table](../../08-interrupt-isr/01-interrupt-vector-table/README.md)

## Learning Outcomes
1. Understand the hardware architecture of a UART connection (TX/RX lines).
2. Explain the concept of Baud Rate and why it is critical for Asynchronous communication.
3. Contrast Polling vs Interrupt-driven UART reception.
