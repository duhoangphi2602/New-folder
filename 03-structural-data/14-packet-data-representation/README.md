# Packet Data Representation (Mini-Project)

## What is this topic?
This topic ties together everything you've learned in Chapter 03 (`struct`, `padding`, `endianness`, and `bit-masking`) into a real-world engineering problem: Designing and parsing a binary network packet.

## Why is it important?
When embedded systems communicate (via UART, SPI, CAN bus, or Ethernet), they don't send human-readable JSON files. JSON takes up too much bandwidth and requires heavy CPU string parsing. Instead, embedded systems send raw **Binary Packets**: tightly packed streams of bytes that perfectly map to C++ structs. Mastering this is the absolute core of embedded communications.

## Prerequisites
- [03-padding-alignment](../03-padding-alignment/README.md)
- [11-bit-field-vs-bit-mask](../11-bit-field-vs-bit-mask/README.md)
- [12-endianness](../12-endianness/README.md)

## Learning Outcomes
1. Learn how to define a cross-platform binary packet struct.
2. Understand how to serialize data (Host to Network) dealing with Endianness.
3. Understand how to deserialize data (Network to Host).
