# Exercises: ADC and DAC

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Resolution Limits
You have an 8-bit ADC and a 12-bit ADC. Both are connected to a `3.3V` reference. 
**Task:** Calculate the "Step Size" (the smallest physical change in voltage that the ADC is capable of detecting) for both the 8-bit and the 12-bit ADC. If a sensor's voltage changes by `2 millivolts` (0.002V), will the 8-bit ADC be able to detect the change? Will the 12-bit ADC?

## Exercise 2: Integer Math (No Floats allowed!)
In the `adc_math_sim.txt` example, we used `float` math to calculate the temperature. In many embedded systems, Floating Point Units (FPUs) do not exist, and using software floats takes thousands of CPU cycles.
```cpp
float voltage = ((float)raw_adc / 4095.0f) * 3.3f;
float temp = voltage * 100.0f;
```
**Task:** Rewrite this mathematical calculation using ONLY integers. You must output the temperature scaled by 10 (e.g., if the temp is 25.4°C, your integer function should return `254`). 
*Warning:* Watch out for integer truncation! `3 / 4` in integer math equals `0`. You must multiply before you divide!
