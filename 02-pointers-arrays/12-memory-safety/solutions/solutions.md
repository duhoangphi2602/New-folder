# Solutions: Memory Safety

## Solution 1: The Off-By-One Error
**Answer:** The bug is the `<=` operator in the loop condition. An array of size 10 has valid indices from `0` to `9`. The loop will execute for `i = 10`, writing a `0` to the memory address immediately *after* the array ends. This is a **Buffer Overflow** (specifically, an Off-By-One error).
**The Fix:** Use `< 10` or, much better, use C++17 `std::array` with a range-based for loop:
```cpp
std::array<uint32_t, 10> buffer;
for (auto& element : buffer) {
    element = 0;
}
```

## Solution 2: Uninitialized Variables
**Answer:** If `hardware_ready()` is false, `sensor_val` is never assigned a value. Because it is a local variable, it contains whatever garbage data was previously left on the stack. `process_data()` will execute using this random garbage data, leading to unpredictable system behavior.
**The Fix:** Use C++ Universal (Brace) Initialization to ensure it starts in a known, safe state (zero).
```cpp
void read_sensor() {
    int sensor_val{}; // Initializes to 0
    if (hardware_ready()) {
        sensor_val = read_adc();
    }
    process_data(sensor_val);
}
```
