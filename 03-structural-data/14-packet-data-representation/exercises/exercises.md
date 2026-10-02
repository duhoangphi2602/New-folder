# Exercises: Packet Data Representation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Serialization Logic
You need to send a 16-bit temperature sensor reading (`uint16_t temp = 0x1234;`) over I2C. The I2C protocol requires you to send the Most Significant Byte (MSB) first, followed by the Least Significant Byte (LSB).
**Task:** Write two lines of C++ code using bitwise operators (`>>` and `&`) to extract the `msb` and the `lsb` into two separate `uint8_t` variables.

## Exercise 2: Deserialization Logic
You receive 2 bytes over UART representing a 16-bit battery voltage. The documentation says the first byte received is the LSB, and the second byte received is the MSB (This means the network protocol is Little Endian).
```cpp
uint8_t byte0 = 0xAA; // LSB
uint8_t byte1 = 0x05; // MSB
```
**Task:** Write the single line of C++ code to combine these two bytes back into a `uint16_t voltage` variable.
