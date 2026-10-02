# Solutions: UART

## Solution 1: The Infinite Hang
**Answer:** The microcontroller will **continue working normally**. 
UART is a "fire-and-forget" asynchronous protocol. The microcontroller hardware has no physical way of knowing if the wire is connected or if anyone is listening on the other side. 
When you write to the Data Register (`UART1->DR`), the hardware peripheral blindly shifts the bits out onto the physical TX pin. As soon as the byte leaves the internal register, the hardware sets the `TXE` (Transmit Empty) flag to 1, regardless of whether the physical voltage actually reached a PC. The `while` loop will break immediately, and the code will run perfectly, just shouting into the void.

## Solution 2: The Baud Rate Math
**Answer:** 
1. **Total Bits per Byte:** A standard `8-N-1` configuration means 1 Start Bit + 8 Data Bits + 1 Stop Bit = 10 bits transferred per byte of actual payload.
2. **Total Bits for File:** `1,048,576 bytes * 10 bits/byte = 10,485,760 total bits.`
3. **Time Calculation:** Baud rate is bits per second. 
   `10,485,760 bits / 115,200 bits/sec = 91.02 seconds.`
It will take just over 1.5 minutes to transmit the file. (This highlights why UART is rarely used for large data transfers compared to USB or Ethernet).
