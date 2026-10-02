# RTC (Real-Time Clock)

## What is this topic?
This topic introduces the **RTC**, a specialized, ultra-low-power timer module designed to keep accurate human time (Years, Months, Days, Hours, Minutes, Seconds) even when the microcontroller is completely powered off.

## Why is it important?
Standard Hardware Timers (like SysTick) are powered by the main system clock. If you unplug the device or put the CPU into Deep Sleep, the main clock stops, and time is lost. An RTC runs on a separate, dedicated battery (the coin-cell battery on a PC motherboard) and uses a special 32.768 kHz crystal oscillator to track time continuously for years.

## Prerequisites
- [07-timers](../07-timers/README.md)

## Learning Outcomes
1. Understand the separate power domain (V_BAT) of the RTC.
2. Explain why the 32.768 kHz crystal is the universal standard for RTCs.
3. Use the RTC to trigger Wake-Up interrupts from Deep Sleep.
