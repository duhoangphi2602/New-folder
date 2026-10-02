# Solutions: std::array

## Solution 1: Legacy Interoperability
**Answer:** Use the `.data()` method to get the underlying raw pointer, and the `.size()` method to get the length.
```cpp
HAL_SPI_Transmit(tx_buffer.data(), tx_buffer.size());
```

## Solution 2: Copying Arrays
**Answer:** Because `std::array` is just a standard struct, you can use the standard assignment operator (`=`). It performs a deep copy of all elements.
```cpp
buffer_B = buffer_A;
```
*(This is significantly cleaner than C-style arrays, where `buffer_B = buffer_A;` is a compile error).*
