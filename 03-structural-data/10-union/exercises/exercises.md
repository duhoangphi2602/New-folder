# Exercises: Union

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Memory Footprint
Calculate the `sizeof` the following `union`.
```cpp
union BigData {
    uint8_t  small_flag;
    double   precise_value;
    uint32_t id_array[4];
};
```

## Exercise 2: The Modern C++ Way
You want to convert a `uint32_t` raw binary value into a `float`.
A C programmer writes this:
```c
union { uint32_t i; float f; } converter;
converter.i = 0x41C80000;
float result = converter.f;
```
**Task:** Since reading from a different union member is technically Undefined Behavior in C++, rewrite this logic using the standard, completely safe C++ `<cstring>` function `std::memcpy`. 
*(Assume `uint32_t` and `float` are both 4 bytes).*
