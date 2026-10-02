# Solutions: Fixed-Width Integers

## Solution 1: Finding the Overflow Bug
**Answer:** On the 8-bit processor, `int` is a 16-bit signed integer. Its maximum value is `32,767`. When you pass `60000` into `delay_ms`, the number undergoes a signed integer overflow. `60000` is interpreted as `-5536`. The `delay_ms` function receives a negative number, likely bypassing the delay loop entirely, causing the system timing to fail instantly. It should have been written as `void delay_ms(uint32_t milliseconds)`.

## Solution 2: Selecting Types
**Answer:**
1. `int32_t` (Signed, because latitude can be negative. 32-bit because 90 million requires at least 27 bits to store).
2. `uint8_t` (Unsigned, because satellite count cannot be negative. 8-bit because 24 easily fits inside the 255 maximum).
3. `uint64_t` (If you use `uint32_t`, milliseconds will overflow after exactly 49.7 days. To last 2 years, you absolutely must use 64-bit).
