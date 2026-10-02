# Blocking vs Non-Blocking I/O

## What is this topic?
This topic explores the architectural difference between **Blocking** (Polling) I/O and **Non-Blocking** (Interrupt/DMA) I/O. It is the most critical architectural decision an embedded software engineer makes.

## Why is it important?
In a desktop environment with a 4GHz CPU and an OS scheduler, a blocking `scanf()` just puts the thread to sleep while other threads run. In a bare-metal microcontroller, a blocking UART read (`while (!data_received);`) physically halts the *entire chip*. Understanding how to decouple the CPU from slow hardware peripherals using Non-Blocking I/O is the key to building responsive, professional embedded systems.

## Prerequisites
- [05-uart-serial](../05-uart-serial/README.md)
- [06-printf-redirect-uart](../06-printf-redirect-uart/README.md)

## Learning Outcomes
1. Understand the severe limitations of Blocking I/O (Polling).
2. Learn the concept of Hardware Interrupts and how they free the CPU.
3. Understand Direct Memory Access (DMA) as the ultimate Non-Blocking solution.
