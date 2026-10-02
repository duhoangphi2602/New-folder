# Exercises: Bit-Fields

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Size Prediction
Look at the following struct. Assume the compiler packs bits optimally and uses a 32-bit architecture.
```cpp
struct SensorFlags {
    uint32_t is_active     : 1;
    uint32_t error_code    : 4;
    uint32_t padding       : 27;
    uint32_t version       : 8;
};
```
**Task:** What will `sizeof(SensorFlags)` return? Why?

## Exercise 2: Truncation Bug
A junior developer wrote this code to store a day of the week (1 to 7).
```cpp
struct Calendar {
    uint8_t day_of_week : 3;
};

void set_day(Calendar* cal, uint8_t day) {
    cal->day_of_week = day;
}

// In main:
Calendar cal;
set_day(&cal, 7); // OK
set_day(&cal, 8); // What happens here?
```
**Task:** Explain what value is actually stored in `day_of_week` when the function is called with `8`, and why.

## Exercise 3: MISRA C Violation
You are reviewing code for a medical device. You see this:
```cpp
struct SpiConfigReg {
    uint32_t clock_phase : 1;
    uint32_t clock_polar : 1;
    uint32_t master_mode : 1;
    uint32_t baud_rate   : 3;
};

// hardware base address
#define SPI_CR (*(volatile struct SpiConfigReg*)0x40013000)
```
**Task:** According to standard embedded C practices (like MISRA C), this code is unacceptable. Explain the architectural risk of this implementation.
