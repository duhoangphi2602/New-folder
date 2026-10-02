# Exercises: Memory Safety

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Off-By-One Error
A developer writes a loop to initialize an array.
```cpp
uint32_t buffer[10];

for (int i = 0; i <= 10; i++) {
    buffer[i] = 0;
}
```
**Task:** Identify the bug. What is this specific class of memory bug called? What is the C++17 `std::array` equivalent that would have prevented this?

## Exercise 2: Uninitialized Variables
In embedded C, you will often see code like this in a main loop:
```c
void read_sensor() {
    int sensor_val;
    if (hardware_ready()) {
        sensor_val = read_adc();
    }
    process_data(sensor_val);
}
```
**Task:** What happens if `hardware_ready()` returns false? How do you fix this using modern C++ universal initialization?
