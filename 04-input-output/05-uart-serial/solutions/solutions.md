# Solutions: UART Serial

## Solution 1: Wiring UART
**Answer:** 
- MCU_A `TX` connects to MCU_B `RX`.
- MCU_A `RX` connects to MCU_B `TX`. (They must be crossed!).
- MCU_A `GND` connects to MCU_B `GND`.
**Why Ground is required:** Voltage is relative. A "High" (1) is 3.3V *relative to ground*. If the two boards do not share a common ground, MCU_B has no reference point to measure the 3.3V coming from MCU_A. The data will be read as random noise.

## Solution 2: Baud Rate Math
**Answer:** You can transmit **11,520 bytes per second**.
**Math:** 
- The baud rate is `115200` bits per second.
- Every byte (8 bits of data) requires `10` bits on the wire due to the Start and Stop bits.
- `115200 / 10 = 11520` characters per second.
*(This is roughly 11.5 Kilobytes per second. This math is crucial for calculating how long your CPU will be blocked in a UART polling loop).*
