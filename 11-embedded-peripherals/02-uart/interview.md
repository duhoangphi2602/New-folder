# Interview Questions: UART

## 1. UART is an "Asynchronous" protocol. What does this mean, and how does it affect the communication design compared to SPI or I2C?
**Answer:** Asynchronous means there is no dedicated clock line shared between the transmitter and receiver. In SPI or I2C, the Master generates a clock pulse, and the Slave reads the data line exactly when the clock pulses. In UART, because there is no clock, both the sender and receiver must be independently configured to the exact same transmission speed (Baud Rate) beforehand. The receiver relies on the "Start Bit" to synchronize its internal timer and sample the data line at the mathematically agreed-upon intervals.

## 2. If you configure your microcontroller UART to `115200` baud, but the PC terminal software is accidentally set to `9600` baud, what will you see on the screen?
**Answer:** You will see complete gibberish, often referred to as "garbage characters" (like `?#%`). Because the microcontroller is sending bits 12 times faster than the PC expects, the PC's UART hardware will sample the data line at the wrong times. It will interpret random clusters of bits as valid bytes, resulting in corrupted, non-ASCII data being printed to the screen.

## 3. Why is relying on "Polling" to receive UART data dangerous in a complex embedded system?
**Answer:** Polling involves running a continuous `while` loop that blocks the CPU while waiting for the `RXNE` (Receive Buffer Not Empty) flag to become `1`. 
1. It is incredibly inefficient; the CPU wastes 100% of its processing power doing nothing.
2. If the CPU is busy doing complex math elsewhere in the code when a UART byte arrives, it might miss the byte entirely. If a second byte arrives before the CPU reads the first one, the hardware register will be overwritten (an "Overrun Error"), and data is permanently lost. To receive UART safely, you must use Interrupts or DMA, allowing the hardware to save the data instantly in the background.
