# The Vector Table

## What is this topic?
This topic introduces the **Vector Table**, an array of function pointers located at the very beginning of Flash memory. It tells the CPU hardware exactly what function to execute when a specific hardware event (like a Reset, a Hard Fault, or a UART Interrupt) occurs.

## Why is it important?
When you write an Interrupt Service Routine (ISR) like `void UART_IRQHandler()`, how does the hardware know to execute *that specific function* when the UART receives a byte? It checks the Vector Table. If the Vector Table is misconfigured, your interrupts will trigger the wrong functions, or the system won't boot at all.

## Prerequisites
- [11-startup](../11-startup/README.md)
- [07-function-pointers](../../02-pointers-arrays/07-function-pointers/README.md)

## Learning Outcomes
1. Understand the structure of the ARM Cortex-M Vector Table.
2. Understand why Address `0x00000000` and `0x00000004` are the most important addresses in the chip.
3. Learn how "Weak Aliasing" is used to provide default fault handlers.
