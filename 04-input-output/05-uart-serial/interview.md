# Interview Questions: UART Serial

## 1. What is the difference between Synchronous (SPI/I2C) and Asynchronous (UART) communication?
**Answer:** Synchronous protocols include a dedicated clock wire (e.g., SCL/SCK) that physically pulses to tell the receiver exactly when to read the data bits, guaranteeing perfect synchronization. Asynchronous protocols (UART) have no clock wire. Both the sender and receiver must be pre-configured to operate at the exact same speed (Baud Rate), and the receiver relies on the physical edge of a "Start Bit" to align its internal timing timer to read the incoming data.

## 2. In a blocking UART driver, why do you check the Status Register before writing to the Data Register?
**Answer:** Hardware peripherals are infinitely slower than the CPU core. If you write to the Data Register, the hardware takes time to physically shift those bits out of the pin. If the CPU immediately loops around and writes the next character into the Data Register before the hardware is finished, the first character will be permanently overwritten and destroyed. You must poll the Status Register (checking the TXE - Transmit Empty flag) to ensure the hardware is ready.

## 3. What happens if the Baud Rates on the sender and receiver are slightly mismatched?
**Answer:** Because UART relies on precise internal timers triggered by the Start Bit, a slight mismatch (usually > 3% to 5%) will cause the receiver's timer to drift out of sync with the sender's data over the course of the 8 data bits. By the time it tries to read the final bits or the Stop Bit, it might read the wrong voltage level. This results in "Framing Errors" and corrupted, garbage characters appearing on the terminal.
