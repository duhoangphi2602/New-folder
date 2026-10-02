# ADC & DAC (Analog-to-Digital / Digital-to-Analog Converters)

## What is this topic?
This topic bridges the gap between the continuous physical world (voltage, temperature, sound waves) and the discrete digital world of C++ (`0`s and `1`s) using ADCs and DACs.

## Why is it important?
Sensors like microphones, potentiometers, and older temperature probes output a continuous analog voltage (e.g., 1.45V). A digital GPIO pin only sees this as a `1` or a `0`. To actually read the exact voltage, you must use an ADC. To output a smooth sine wave (like audio), you must use a DAC.

## Prerequisites
- [01-gpio](../01-gpio/README.md)
- [05-dma](../05-dma/README.md)

## Learning Outcomes
1. Understand Resolution (e.g., 12-bit ADC) and Voltage Reference (VREF).
2. Calculate the exact analog voltage from a raw digital ADC reading.
3. Understand the concept of the Sampling Rate.
