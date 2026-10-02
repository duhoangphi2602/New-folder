# Solutions: Smart Pointers

## Solution 1: The Compilation Error
**Answer:** The signature of `calculate_checksum` asks for the pointer to be passed *by value* (a copy). If the compiler allowed you to copy `my_buf`, there would now be TWO `std::unique_ptr` objects pointing to the exact same 10KB of Heap memory. When `calculate_checksum` ends, its local copy would call `delete[]`. Later, when `main_task` ends, `my_buf` would call `delete[]` on the exact same memory! This is a "Double Free" vulnerability and will instantly corrupt the Heap and crash the microcontroller. To prevent this, the C++ standard explicitly deletes the copy constructor of `std::unique_ptr`.

## Solution 2: Passing to functions
**Answer:** You should pass the smart pointer by reference, or simply extract the raw pointer to pass down. (The raw pointer is safe here because `calculate_checksum` doesn't try to take ownership, it just observes the data).
```cpp
// Option 1: Pass a raw pointer
void calculate_checksum(uint8_t* raw_ptr) { ... }
calculate_checksum(my_buf.get()); 

// Option 2: Pass by reference
void calculate_checksum(const std::unique_ptr<uint8_t[]>& ref_buf) { ... }
calculate_checksum(my_buf);
```
*(Option 1 is generally preferred in modern C++ because `calculate_checksum` shouldn't care whether the memory is managed by a unique_ptr, shared_ptr, or a static array).*
