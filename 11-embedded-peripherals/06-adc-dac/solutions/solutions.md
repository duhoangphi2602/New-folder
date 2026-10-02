# Solutions: ADC and DAC

## Solution 1: Resolution Limits
**Answer:** 
- **8-bit ADC:** Max value is $2^8 - 1 = 255$. 
  Step Size = `3.3V / 255 = 0.0129V` (or ~13 millivolts).
- **12-bit ADC:** Max value is $2^{12} - 1 = 4095$. 
  Step Size = `3.3V / 4095 = 0.0008V` (or ~0.8 millivolts).
If the sensor changes by exactly `2 millivolts`:
The 8-bit ADC **cannot** detect it. The change is smaller than its 13mV step size, so the raw integer value will not change.
The 12-bit ADC **can** detect it easily, as the 2mV change covers more than two of its 0.8mV steps. The raw integer will increment by 2.

## Solution 2: Integer Math
**Answer:** To avoid floating-point math, we must scale the numbers up (multiply) before doing any division.
We want to return Temperature * 10.
Original math: `Temp = (Raw / 4095) * 3.3 * 100`
So we want: `Return_Value = (Raw / 4095) * 3.3 * 100 * 10`
Simplify constants: `3.3 * 1000 = 3300`
Final integer formula:
```cpp
uint32_t get_temp_x10(uint32_t raw_adc) {
    // Multiply FIRST to prevent truncation to 0.
    // (raw_adc * 3300) can safely fit in a uint32_t without overflowing.
    uint32_t result = (raw_adc * 3300) / 4095;
    return result; 
}
```
If raw is 310: `(310 * 3300) / 4095 = 1023000 / 4095 = 249`. 
The result is `249` (which represents 24.9°C), calculated with zero floating-point overhead!
