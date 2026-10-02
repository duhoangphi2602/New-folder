# Solutions: SPI

## Solution 1: The Infinite Wait
**Answer:** The code hangs because in SPI, a Slave can never initiate a transmission. The Master *must* generate the SCK clock pulses to force the Slave to shift data out. The hardware only generates clock pulses when you write data *into* the Transmit Data Register. 
Because you just sat in a `while` loop waiting for data to arrive without ever transmitting anything, the clock line remained dead silent, and the Slave couldn't send the byte.
**The Fix:** You must transmit a "Dummy Byte" to generate the clock pulses:
```cpp
uint8_t read_flash_byte() {
    // 1. Transmit Dummy Byte to generate 8 clock pulses
    SPI1->DR = 0xFF; 
    
    // 2. NOW wait for the shift register to swap the byte
    while ((SPI1->SR & RXNE_FLAG) == 0) { }
    
    // 3. Read and return the real data
    return SPI1->DR;
}
```

## Solution 2: Connecting the Wires
**Answer:** 
1. The Master's `MOSI` pin connects directly to the Slave's `MOSI` pin. (Master Out goes to Slave In).
2. The Master's `MISO` pin connects directly to the Slave's `MISO` pin. (Slave Out goes to Master In).
3. **Contrast with UART:** In UART, the pins are symmetrical (both devices are peers). You MUST cross them (TX to RX, RX to TX). In SPI, the pins are named strictly from the Master's perspective. Therefore, you wire them straight-through, identically matching the names.
