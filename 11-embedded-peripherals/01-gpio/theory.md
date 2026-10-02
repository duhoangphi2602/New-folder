# GPIO (General Purpose Input/Output)

## 1. What is a GPIO Pin?
A microcontroller is a black box of silicon. It communicates with the outside world through physical metal legs called **Pins**. 
A GPIO pin is a pin whose behavior is entirely controlled by your C++ software. By writing `1` or `0` to specific memory-mapped hardware registers, you can change the electrical state of the pin.

## 2. Direction: Input vs Output
- **Output:** The microcontroller acts as a power source (or ground). Writing a `1` to the Output Data Register (ODR) connects the pin to the VCC voltage (e.g., 3.3V), turning an LED *ON*. Writing a `0` connects it to GND (0V), turning the LED *OFF*.
- **Input:** The microcontroller acts as a voltmeter. It reads the electrical voltage currently present on the pin. If you press a button connected to 3.3V, the Input Data Register (IDR) will read as `1`.

## 3. Input Modes (Floating vs Pulled)
If a pin is configured as an Input, but *nothing* is physically connected to it, what voltage does it read? 
It reads **Garbage**. The pin acts like a tiny antenna, picking up ambient electromagnetic noise (WiFi, static electricity) and rapidly fluctuating between 1 and 0. This is called a **Floating** input.
To fix this, microcontrollers have internal resistors you can enable via software:
- **Pull-Up:** Internally connects the pin to 3.3V through a resistor. If nothing is connected, it safely reads `1`. (Common for buttons that connect to Ground when pressed).
- **Pull-Down:** Internally connects the pin to GND through a resistor. If nothing is connected, it safely reads `0`.

## 4. Output Modes (Push-Pull vs Open-Drain)
- **Push-Pull:** The default. Writing `1` actively pushes 3.3V out. Writing `0` actively pulls it to 0V. Good for driving LEDs.
- **Open-Drain:** Writing `0` actively pulls the pin to 0V. Writing `1` does *nothing*—it disconnects the pin, leaving it floating (High Impedance). This is mandatory for shared communication buses (like I2C) where multiple devices need to safely share the same wire without causing a short circuit if one outputs 3.3V while another outputs 0V.

## 5. Alternate Functions (AF)
GPIO pins are multiplexed. Pin `PA9` might be a standard Output, but it might also be the hardware UART1 Transmit pin (TX). To let the hardware UART peripheral take control of the pin's voltage (instead of your manual software commands), you must configure the pin into **Alternate Function Mode**.

## 6. Example
*(See `examples/` for bare-metal C++ code to configure an LED and Button).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
