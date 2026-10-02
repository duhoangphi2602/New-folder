# Exercises: Static Allocation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Wasted RAM Problem
You are designing a data logger for a drone. It has 4 sensors. Each sensor produces a 1KB chunk of data per second. You must transmit this data over a radio. Sometimes the radio loses connection for up to 10 seconds, during which time you must buffer the sensor data. 
**Task:** If you use strict Static Allocation for your buffers, exactly how many Kilobytes of RAM must you permanently reserve in the `.bss` section to guarantee no data is lost during a 10-second outage?

## Exercise 2: Static Local vs Global
```cpp
void process_packet() {
    static std::array<uint8_t, 2048> temp_buffer;
    // do work...
}
```
**Task:** The array above is statically allocated. Does it live on the Stack? If multiple RTOS tasks call `process_packet()` at the same time, what terrible thing will happen?
