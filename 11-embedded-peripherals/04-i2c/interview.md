# Interview Questions: I2C

## 1. Why must I2C pins be configured as Open-Drain? What would happen if they were Push-Pull?
**Answer:** I2C is a shared bus. If the pins were configured as Push-Pull, one device (e.g., the Master) might try to transmit a logical `1` by actively pushing 3.3V onto the SDA wire, while another device (e.g., a Slave sending an ACK) tries to transmit a logical `0` by actively pulling the wire to GND. This creates a direct electrical short circuit from VCC to GND, destroying the GPIO pins. Open-Drain ensures that devices can only pull the line to GND, or disconnect from it. If two devices transmit at the same time, the line safely goes to GND without a short circuit.

## 2. In I2C, what is the ACK/NACK mechanism, and how is it used during the Addressing phase?
**Answer:** ACK (Acknowledge) and NACK (Not Acknowledge) are used to verify that data was successfully received. After every 8 bits (1 byte) transmitted, the sender releases the SDA line. The receiver must pull the SDA line low (a 0) during the 9th clock pulse to issue an ACK. If the line remains high (a 1), it is a NACK. 
During the Addressing phase, the Master broadcasts a 7-bit address. If a Slave with that exact address exists on the bus, it issues an ACK. If the Master sees a NACK, it immediately knows that the hardware is disconnected, dead, or the wrong address was used, and it can abort the transaction gracefully without waiting for a timeout.

## 3. What is "Clock Stretching" in I2C?
**Answer:** Clock Stretching is a mechanism that allows a slow Slave device to pause the Master. The Master always controls the SCL (Clock) line. However, if the Master requests data, and the Slave needs 10 milliseconds to read its internal sensors before it can reply, the Slave can physically hold the SCL line LOW. The Master will try to push SCL high to continue the clock, but because I2C is Open-Drain, the Master will see that the line is still LOW. The Master will patiently wait until the Slave releases the SCL line back to HIGH before continuing the transmission.
