# Interview Questions: SPI

## 1. What makes SPI significantly faster than UART and I2C?
**Answer:** 
1. **Clock Line (vs UART):** Because SPI has a dedicated hardware SCK line, the receiver doesn't have to guess or mathematically sample the data based on a pre-agreed Baud Rate. The clock perfectly synchronizes the data, allowing speeds upwards of 50 MHz.
2. **Push-Pull vs Open-Drain (vs I2C):** I2C uses Open-Drain pins with Pull-Up resistors. Relying on a resistor to physically pull a wire's voltage back up to 3.3V takes time (due to wire capacitance), limiting I2C to about 400 KHz (or 1 MHz max). SPI uses Push-Pull pins; the transistors violently and instantly force the voltage to 3.3V or 0V, allowing for massively higher frequencies.
3. **Full Duplex:** SPI shifts data in and out simultaneously.

## 2. In an SPI system, how does the Master communicate with multiple Slaves? Does it use addresses?
**Answer:** SPI does not use software addresses (unlike I2C). Instead, it relies on physical hardware routing. The Master must have a dedicated GPIO output pin acting as a Chip Select (CS) for *every single Slave* on the bus. All Slaves share the SCK, MOSI, and MISO lines. To talk to Slave #2, the Master pulls CS2 LOW. Slaves 1 and 3 see their CS lines are HIGH, so they physically disconnect their MISO pins from the bus (High Impedance) and ignore the clock, ensuring only Slave 2 interacts with the Master.

## 3. Explain the concept of the "Dummy Byte" in SPI.
**Answer:** Because SPI is fundamentally a circular shift register, every transmission is identically a reception. The Master generates the clock pulses, but it only does so when the software writes data into the Transmit register. If the Master wants to read data from a sensor, it must physically push 8 bits out on MOSI to generate the 8 clock pulses required to pull 8 bits in on MISO. The Master usually writes `0x00` or `0xFF` to the Transmit register. The sensor ignores this "Dummy" data, but utilizes the resulting clock pulses to shift its real data back to the Master.
