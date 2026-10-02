# Interview Questions: RTC

## 1. Why do almost all Real-Time Clocks use a 32.768 kHz crystal oscillator instead of deriving time from the main 8 MHz or 16 MHz system clock?
**Answer:** There are two main reasons. 
First, mathematical perfection: $32,768$ is exactly $2^{15}$. A simple 15-stage hardware flip-flop divider can divide this frequency perfectly down to exactly 1.000 Hz, providing a microsecond-accurate 1-second pulse. Dividing an 84 MHz clock down to exactly 1 Hz often yields floating-point remainders, causing the clock to drift by several minutes over a year.
Second, power consumption. Oscillating a crystal at 84,000,000 times a second draws milliamps of current, which would drain a coin-cell battery in days. Oscillating at a slow 32 kHz draws only micro-amps (or nano-amps), allowing a standard CR2032 battery to run the RTC continuously for 5 to 10 years.

## 2. Explain the purpose of the `VBAT` pin on a microcontroller.
**Answer:** The `VBAT` (Battery Voltage) pin is a dedicated power input specifically for the RTC module and a small block of Backup SRAM. It is physically isolated from the main `VDD` power supply. When the main power is disconnected, an internal hardware switch instantly connects the RTC to the `VBAT` pin (usually connected to a coin-cell battery). This ensures the RTC continues ticking and keeping accurate time even when the rest of the microcontroller is completely dead.

## 3. What is BCD (Binary-Coded Decimal), and why is it historically used in RTC hardware registers?
**Answer:** BCD is a data format where each individual decimal digit of a number is encoded by a separate 4-bit binary block (a nibble). For example, the decimal number 59 is represented in BCD as `0101 1001` (where 0101 is 5, and 1001 is 9). Historically, RTCs used BCD because early embedded systems and digital clocks used 7-segment LED displays. BCD allowed the hardware to map the exact 4-bit nibble directly to the display driver for the "Tens" digit and the "Units" digit without requiring the CPU to perform complex division or modulo arithmetic to separate the digits.
