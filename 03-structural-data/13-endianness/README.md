# Endianness

## What is this topic?
This topic explains **Endianness**: the order in which a computer's CPU stores the individual bytes of a multi-byte variable (like a `uint32_t`) in memory. 

## Why is it important?
A 32-bit integer consists of 4 bytes. Does the CPU store the "largest" byte first, or the "smallest" byte first? Different CPUs do it differently! ARM Cortex-M and x86 processors are **Little Endian**, while many network protocols and legacy processors are **Big Endian**. If a Little Endian microcontroller sends a 32-bit sensor reading over the internet to a Big Endian server, the number will be read completely backwards, resulting in corrupted data.

## Prerequisites
- [09-union](../09-union/README.md)
- [11-bit-field-vs-bit-mask](../11-bit-field-vs-bit-mask/README.md)

## Learning Outcomes
1. Understand the difference between Little Endian and Big Endian byte orders.
2. Write C++ code to detect the endianness of the current system.
3. Learn how to safely swap bytes to communicate across different architectures (Network Byte Order).
