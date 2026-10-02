# Solutions: I2C

## Solution 1: The Missing Resistors
**Answer:** You forgot to add the physical **Pull-Up Resistors** to the SDA and SCL lines.
Because the microcontroller pins are configured as Open-Drain, they can only pull the voltage down to GND; they physically cannot push the voltage up to 3.3V. Without the external pull-up resistors connecting the wires to VCC, the lines will float or get stuck at 0V. The microcontroller sees that the lines are LOW and assumes another Master is currently using the bus, so it waits infinitely for the bus to go HIGH (Idle state), which will never happen.

## Solution 2: Comparing SPI and I2C
**Answer:**
1. **SPI Pins:** You will need **8 pins**. 3 shared pins (MOSI, MISO, SCK) + 5 dedicated Chip Select (CS) pins (one for each sensor).
2. **I2C Pins:** You will need exactly **2 pins** (SDA, SCL). 
**The Issue:** Because I2C relies on software addresses, every device on the bus must have a unique address. If all 5 sensors are identical, they likely have the exact same hardcoded I2C address (e.g., `0x40`). If the Master sends `0x40`, all 5 sensors will try to reply simultaneously, corrupting the data. (To fix this, you either need sensors with configurable address pins, or you must use an I2C Multiplexer chip).
