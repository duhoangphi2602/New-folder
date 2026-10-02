# DMA (Direct Memory Access)

## What is this topic?
This topic introduces **DMA**, an independent hardware coprocessor on the microcontroller that moves data around without involving the main CPU.

## Why is it important?
If you want to update a color LCD screen over SPI, you need to send 150,000 bytes of color data. If you use Polling or Interrupts, the main CPU is 100% paralyzed during the transfer, doing nothing but moving bytes from RAM to the SPI register. DMA completely offloads this grunt work, freeing the CPU to execute AI algorithms or calculate physics while the screen updates magically in the background.

## Prerequisites
- [02-uart](../02-uart/README.md)
- [03-spi](../03-spi/README.md)

## Learning Outcomes
1. Understand how DMA offloads CPU work.
2. Differentiate between Memory-to-Memory, Peripheral-to-Memory, and Memory-to-Peripheral modes.
3. Understand Circular vs Normal DMA modes.
