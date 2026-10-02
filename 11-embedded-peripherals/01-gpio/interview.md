# Interview Questions: GPIO

## 1. Explain the difference between Push-Pull and Open-Drain output modes.
**Answer:** 
- **Push-Pull** uses two internal transistors. It actively drives the pin to VCC when outputting a `1`, and actively drives it to GND when outputting a `0`. It is used for driving loads like LEDs.
- **Open-Drain** only has one transistor connected to GND. When outputting a `0`, it actively drives the pin to GND. When outputting a `1`, it completely disconnects the pin (High Impedance), allowing the voltage to float. To achieve a logical `1`, an Open-Drain pin strictly requires an external (or internal) pull-up resistor to pull the voltage up to VCC. It is primarily used for shared communication buses like I2C to prevent short circuits if multiple devices transmit simultaneously.

## 2. If you want to use a GPIO pin for a hardware UART peripheral (TX/RX), how do you configure it?
**Answer:** You must configure the pin mode in the GPIO registers to **Alternate Function (AF)**. By default, pins are connected to the standard GPIO Output/Input Data Registers, meaning the CPU controls them via software. Switching the pin to Alternate Function physically disconnects the pin from the CPU's direct control and digitally routes it directly into the hardware UART peripheral on the silicon die, allowing the UART hardware to toggle the pin automatically.

## 3. What is "Switch Bouncing", and how is it mitigated?
**Answer:** When a physical mechanical button is pressed, the metal contacts do not immediately make a perfect connection. Microscopically, they bounce against each other for a few milliseconds, causing the electrical signal to rapidly spike between 1 and 0 dozens of times. If a microcontroller reads this raw GPIO input, it will think the user pressed the button 30 times in 5 milliseconds. This is mitigated through "Debouncing". 
- **Hardware Debouncing:** Adding a capacitor across the button to smooth out the voltage spikes (RC filter).
- **Software Debouncing:** Writing logic that detects a state change, starts a timer, waits ~20ms, and then checks the pin again to ensure the voltage has settled before accepting the input.
