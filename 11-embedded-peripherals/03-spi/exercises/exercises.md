# Exercises: SPI

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Infinite Wait
You are writing a C++ driver to read data from an SPI Flash chip. You write the following code to read one byte:
```cpp
uint8_t read_flash_byte() {
    // 1. Wait for RX buffer to not be empty (RXNE flag)
    while ((SPI1->SR & RXNE_FLAG) == 0) { }
    
    // 2. Read and return the data
    return SPI1->DR;
}
```
You run the code. The microcontroller freezes completely inside the `while` loop. The `RXNE` flag never goes to 1. 
**Task:** Why does this code hang? What fundamental rule of SPI circular shift registers did you violate? How do you fix it?

## Exercise 2: Connecting the Wires
You have a microcontroller (Master) and an LCD Screen (Slave).
You need to wire them together.
**Task:** 
1. Which pin on the Master connects to the `MOSI` pin on the Slave?
2. Which pin on the Master connects to the `MISO` pin on the Slave?
3. Contrast this with how you wire a UART TX/RX connection.
