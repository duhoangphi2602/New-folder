# Solutions: Bare-Metal Programming

## Solution 1: The Infinite Latency Bug
**Answer:** The system will fail catastrophically and drop almost all the GPS data. 
While `write_to_sd_card()` is executing, the CPU is trapped in that function for 50 milliseconds. During those 50ms, the GPS hardware will send 25 new bytes of data. Because the UART hardware only has a 1-byte buffer, the 2nd byte will overwrite the 1st byte, the 3rd will overwrite the 2nd, etc. (an Overrun Error). When the CPU finally returns to `read_gps()`, 24 bytes have been permanently lost.

## Solution 2: Solving the Bug
**Answer:** You must use Hardware Interrupts. 
You configure the UART peripheral to generate an **Interrupt (ISR)** every time a single byte arrives. The moment the byte arrives, the CPU instantly pauses `write_to_sd_card()`, jumps to the ISR, copies the byte into a large `std::array` software Ring Buffer, and immediately resumes writing to the SD card. Later, when the Super Loop calls `read_gps()`, it simply reads from the software Ring Buffer rather than the hardware. This pattern (Hardware ISR -> Software Buffer -> Main Loop) is the backbone of all bare-metal systems.
