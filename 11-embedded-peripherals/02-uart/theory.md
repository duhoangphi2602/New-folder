# UART (Universal Asynchronous Receiver-Transmitter)

## 1. The Hardware Connection
UART is incredibly simple. It requires only 3 wires to achieve full-duplex (two-way simultaneous) communication:
- **TX (Transmit):** Sends data.
- **RX (Receive):** Receives data.
- **GND (Ground):** The shared electrical reference.
**Crucial Rule:** You must cross the lines. The TX pin of Microcontroller A connects to the RX pin of Microcontroller B, and vice versa.

## 2. Asynchronous vs Synchronous
- **Synchronous (like SPI/I2C):** Uses a dedicated Clock wire. The sender pulses the clock wire to tell the receiver exactly when to read the data line.
- **Asynchronous (UART):** There is NO clock wire. How does the receiver know when one bit ends and the next begins? 

## 3. The Baud Rate
Because there is no clock wire, both devices must pre-agree on a strict timing speed called the **Baud Rate** (bits per second). 
If the agreed baud rate is `115200`, both microcontrollers configure internal timers to mathematically sample the TX/RX line exactly 115,200 times per second. 
If Device A transmits at 115200 baud, but Device B is listening at 9600 baud, Device B will read absolute gibberish.

## 4. The Data Frame
Since there is no clock, the receiver needs a trigger to start its timer.
- **Idle State:** The line is held HIGH (`1`).
- **Start Bit:** The sender pulls the line LOW (`0`). This wakes up the receiver and starts its baud-rate timer.
- **Data Bits:** Usually 8 bits (1 byte) of actual data, sent LSB (Least Significant Bit) first.
- **Parity Bit (Optional):** A primitive error-checking bit. Rarely used today.
- **Stop Bit:** The sender pulls the line HIGH (`1`) for at least 1 bit duration to reset the line for the next byte.

## 5. Receiving Data: Polling vs Interrupts
- **Polling (Blocking):** The CPU runs a `while(1)` loop constantly checking a hardware flag (`RXNE` - Receive Buffer Not Empty) to see if a byte arrived. This wastes 100% of the CPU's time.
- **Interrupts (Non-Blocking):** The CPU goes to sleep or does other math. When the UART hardware receives a full byte, it fires an Interrupt request. The CPU pauses, jumps to the ISR, grabs the byte, and resumes work.

## 6. Example
*(See `examples/` for a visualization of a UART data frame).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
