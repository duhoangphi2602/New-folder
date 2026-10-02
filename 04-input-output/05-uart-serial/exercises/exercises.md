# Exercises: UART Serial

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Wiring UART
You have two microcontrollers, MCU_A and MCU_B. Both have UART peripherals with pins labeled TX, RX, and GND.
**Task:** How exactly do you wire these three pins between the two boards so they can communicate? Explain what happens if you forget to connect the GND (Ground) wire.

## Exercise 2: Baud Rate Math
UART is asynchronous, so both devices must agree on a Baud Rate (bits per second). A standard UART frame consists of:
- 1 Start Bit
- 8 Data Bits
- 1 Stop Bit
(Total = 10 bits per character).
**Task:** If your system is configured to a baud rate of `115200`, what is the maximum number of **bytes (characters)** you can transmit per second?
