# RTC (Real-Time Clock)

## 1. The Power Domain Problem
When you unplug an embedded device, RAM is erased and the CPU halts. When you plug it back in, standard timers reset to 0. 
How does your laptop know the exact date and time even if the battery died for a month?
Microcontrollers solve this by isolating the RTC peripheral into a separate physical "Power Domain".
- The main CPU runs on the `VDD` power pin (e.g., USB power).
- The RTC runs on the `VBAT` power pin (e.g., a tiny 3V coin cell battery).
When `VDD` is disconnected, the RTC seamlessly switches to `VBAT` and continues ticking.

## 2. The 32.768 kHz Crystal
Standard timers use the main CPU clock (e.g., 84 MHz), which consumes massive amounts of power.
The RTC uses a completely separate, external quartz crystal (LSE - Low Speed External). 
Almost every RTC in the world uses a crystal that vibrates exactly **32,768 times per second**.
Why this exact number? Because $2^{15} = 32768$. 
Inside the RTC hardware, a simple 15-stage binary divider perfectly scales 32,768 Hz down to exactly 1.000000 Hz. This guarantees a mathematically perfect 1-second tick, consuming almost zero electricity (micro-amps).

## 3. Human Time Registers
Unlike standard timers that just hold a massive 32-bit integer representing "ticks", the RTC hardware actually understands human calendars. 
It has dedicated hardware registers for:
- `RTC_TR` (Time Register): Holds Hours, Minutes, Seconds.
- `RTC_DR` (Date Register): Holds Year, Month, Day, Weekday.
It automatically handles Leap Years and 28-day/30-day months in hardware!

## 4. Alarms and Wake-Up
The most powerful feature of the RTC is its ability to wake up the main CPU.
If you are designing a battery-powered IoT weather station:
1. You set the RTC Alarm to fire in 1 hour.
2. You turn off all peripherals, turn off the main 84 MHz clock, and put the CPU into "Deep Sleep" (consuming nano-amps).
3. 1 hour later, the RTC (running on its tiny 32kHz crystal) triggers a hardware interrupt.
4. The interrupt violently wakes up the main CPU. The CPU reads the sensor, transmits the data via WiFi, sets the next alarm, and goes back to sleep.

## 5. Example
*(See `examples/` for binary-coded decimal (BCD) parsing).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
