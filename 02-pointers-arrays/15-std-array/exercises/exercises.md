# Exercises: std::array

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Legacy Interoperability
You are writing C++ code, but you must call a vendor-supplied C function to transmit data over SPI:
```c
// Vendor HAL (Written in C)
void HAL_SPI_Transmit(uint8_t* pData, uint16_t Size);
```
You have your data stored safely in modern C++:
```cpp
std::array<uint8_t, 128> tx_buffer;
```
**Task:** Write the single line of C++ code to call `HAL_SPI_Transmit`, passing your `tx_buffer` safely.

## Exercise 2: Copying Arrays
In C, if you want to copy the contents of `array_A` to `array_B`, you must use a loop or `memcpy`. 
```cpp
std::array<int, 5> buffer_A = {1, 2, 3, 4, 5};
std::array<int, 5> buffer_B = {0, 0, 0, 0, 0};
```
**Task:** How do you copy the contents of `buffer_A` into `buffer_B` in C++11?
