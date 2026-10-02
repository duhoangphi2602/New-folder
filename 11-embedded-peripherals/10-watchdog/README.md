# Watchdog Timer (WDT)

## What is this topic?
This topic covers the **Watchdog Timer (WDT)**, a specialized safety peripheral designed to automatically restart the microcontroller if the software crashes or hangs.

## Why is it important?
Code is never perfect. Cosmic rays can flip a bit in RAM, an I2C sensor can lock up the bus, or a rare edge-case can trap the CPU in an infinite `while` loop. If a satellite or a car engine controller hangs, you cannot ask the user to walk over and press the Reset button. The Watchdog Timer is the ultimate fail-safe that presses the Reset button for you.

## Prerequisites
- [07-timers](../07-timers/README.md)
- [09-rtc](../09-rtc/README.md) (LSI Clock)

## Learning Outcomes
1. Understand the concept of "Kicking the Dog".
2. Differentiate between the Independent Watchdog (IWDG) and Window Watchdog (WWDG).
3. Architect the main loop to safely pet the watchdog without hiding bugs.
