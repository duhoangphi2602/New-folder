# Solutions: Array vs Pointer (Decay)

## Solution 1: The Clear Buffer Bug
**Answer:** The bug is Array Decay. Inside `clear_buffer`, `buf` has decayed into a pointer (`int*`). 
- On a 32-bit MCU, `sizeof(buf)` (a pointer) is 4 bytes. 
- `sizeof(buf[0])` (an int) is 4 bytes. 
- `4 / 4 = 1`. 
The loop will only execute 1 time. It will only clear `my_data[0]`. The other 99 elements will remain unchanged!
**The Fix:** You must pass the length as a separate argument.
```cpp
void clear_buffer(int buf[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        buf[i] = 0;
    }
}
// Called via: clear_buffer(my_data, 100);
```

## Solution 2: `extern` Declarations
**Answer:** Arrays and pointers are fundamentally different types. 
- In `sensors.cpp`, the compiler allocates 200 contiguous bytes (50 ints) and associates the symbol `temperature_readings` with the address of the *first byte of that memory block*.
- In `main.cpp`, by declaring `extern int*`, you told the compiler that `temperature_readings` is a *pointer variable*. 
When `main.cpp` tries to access it, it looks at the first 4 bytes of the array data, interprets those raw data bytes as a memory address, and tries to jump there to read memory! This results in an immediate Hard Fault.
**The Fix:** Declare it correctly as an array in `main.cpp`:
```cpp
extern int temperature_readings[];
```
