# Interview Questions: Arrays

## 1. How are elements of a C-style array stored in memory?
**Answer:** They are stored in contiguous (strictly adjacent) memory locations. There is absolutely no padding between elements of an array.

## 2. How do you find the number of elements in a C-style array?
**Answer:** By dividing the total byte size of the array by the byte size of one element: `sizeof(array) / sizeof(array[0])`. (Or using `std::size(array)` in modern C++).

## 3. What is the difference between `uint8_t buffer[10];` and `uint8_t buffer[10] = {0};`?
**Answer:** The first declaration is uninitialized; the memory will contain whatever garbage data was previously left on the stack or in RAM. The second declaration explicitly zero-initializes the entire array, ensuring all 10 bytes are `0`. In embedded systems, failing to initialize buffers often leads to parsing garbage data.
