# SPI (Serial Peripheral Interface)

## 1. The 4-Wire Bus
Unlike UART's 3 wires, SPI requires 4 wires:
1. **SCK (Serial Clock):** Generated *only* by the Master. Synchronizes the data.
2. **MOSI (Master Out, Slave In):** Data flows from the Master to the Slave.
3. **MISO (Master In, Slave Out):** Data flows from the Slave to the Master.
4. **CS / SS (Chip Select / Slave Select):** A dedicated wire to wake up a specific Slave. Usually Active Low (pulled to 0V to activate).

*Note: Unlike UART, you DO NOT cross MOSI and MISO. Master MOSI connects to Slave MOSI.*

## 2. Master / Slave Architecture
SPI is a strict dictatorship. The Slave device (e.g., a temperature sensor) cannot speak unless spoken to. It cannot generate a clock pulse. 
If the Master wants to read data, the Master must generate clock pulses so the Slave can shift its data out on the MISO line.

## 3. The Shift Register Illusion
The most critical concept in SPI is that it is a **circular shift register**.
When you write an 8-bit byte to the SPI Data Register, the hardware clocks it out on the MOSI line. 
Simultaneously, for every clock pulse that pushes a bit out on MOSI, a bit is pulled in on MISO.
**In SPI, every Transmission is identically a Reception. You cannot transmit without receiving, and you cannot receive without transmitting.**

If you want to read a byte from a sensor, you must transmit a "Dummy Byte" (usually `0x00` or `0xFF`). The Master transmits the dummy byte to generate the 8 clock pulses, which forces the Slave to push its real data back to the Master.

## 4. Multiple Slaves
How do you connect 3 sensors to 1 Master?
- SCK, MOSI, and MISO are shared (connected in parallel) across all 3 sensors.
- You must use **3 separate Chip Select (CS)** GPIO pins on the Master. 
- To talk to Sensor 1, the Master pulls CS_1 LOW, talks, and pushes it HIGH. Sensor 2 and 3 ignore the shared bus because their CS lines are HIGH.

## 5. Clock Polarity (CPOL) and Phase (CPHA)
Because there is a clock line, both devices must agree on exactly *when* to read the data line.
- **CPOL:** Is the clock line resting at 0V (Idle Low) or 3.3V (Idle High)?
- **CPHA:** Do we read the data on the *first* edge of the clock pulse, or the *second* edge?
These two settings create 4 "SPI Modes" (Mode 0, 1, 2, 3). You must check the sensor's datasheet to match the mode.

## 6. Example
*(See `examples/` for a conceptual visualization of the Shift Register).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
