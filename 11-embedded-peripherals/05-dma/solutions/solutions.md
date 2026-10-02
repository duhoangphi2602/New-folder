# Solutions: DMA

## Solution 1: The Address Increment
**Answer:** 
- **`Memory_Increment_Mode` must be ENABLED.** The array in RAM is sequential. The DMA must read byte 0 from address `0x20000000`, then increment its internal pointer to read byte 1 from `0x20000001`, and so on. If you didn't increment, it would just send the first byte of the array 100 times.
- **`Peripheral_Increment_Mode` must be DISABLED.** The UART hardware only has *one* physical Data Register located at a fixed address (e.g., `0x40001004`). Every single byte must be written to that exact same address. If you incremented the peripheral address, the DMA would write the first byte to the UART, and the second byte to a random register next door (like the Baud Rate register), instantly crashing the system.

## Solution 2: The Half-Transfer Interrupt
**Answer:** If you only used the Transfer Complete (TC) interrupt at byte 1000, the CPU would wake up to process the 1000 bytes. However, because the DMA is in Circular Mode, the DMA *instantly* wraps around to index 0 and starts recording new audio. If the CPU takes too long to process the array, the DMA will overwrite the data the CPU is currently trying to read.
**The Fix (Double Buffering Concept):** 
1. When the **Half-Transfer (HT)** interrupt fires (byte 500), the CPU wakes up and safely processes the *first half* of the array (bytes 0-499), while the DMA safely records into the *second half* (bytes 500-999).
2. When the **Transfer Complete (TC)** interrupt fires (byte 1000), the CPU wakes up and processes the *second half* of the array, while the DMA has wrapped around and is safely recording into the *first half*. 
This ping-pong approach guarantees the CPU and DMA never collide.
