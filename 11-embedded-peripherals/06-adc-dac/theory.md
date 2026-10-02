# ADC & DAC

## 1. Analog vs Digital
- **Digital:** A signal is either exactly 3.3V (Logic 1) or exactly 0.0V (Logic 0).
- **Analog:** A signal can be *any* voltage between 0.0V and 3.3V (e.g., 1.253V, 2.7V).

## 2. ADC (Analog-to-Digital Converter)
The ADC hardware reads an analog voltage on a specific pin and converts it into a digital integer that C++ can understand.
**Two critical parameters define an ADC:**
1. **Resolution (Bits):** Defines how precisely the ADC can measure. A 12-bit ADC outputs a number from `0` to `4095` (since $2^{12} - 1 = 4095$). 
2. **Voltage Reference (VREF):** The maximum voltage the ADC can measure. Usually tied to VCC (3.3V).
- If the pin is at 0.0V, the ADC outputs `0`.
- If the pin is at 3.3V, the ADC outputs `4095`.
- If the pin is at 1.65V (exactly half), the ADC outputs `2047`.

### The Conversion Formula
To convert the raw integer back to physical voltage in your C++ code:
`Voltage = (Raw_ADC_Value / Max_ADC_Value) * VREF`

## 3. Sampling Rate
The ADC cannot measure voltage continuously. It takes "snapshots" (samples) of the voltage at specific intervals. 
If you are recording audio containing frequencies up to 20,000 Hz, the **Nyquist Theorem** dictates that your ADC must take snapshots at least twice as fast (40,000 samples per second) to accurately recreate the wave.

## 4. DAC (Digital-to-Analog Converter)
The exact opposite of the ADC. 
You write a digital integer (e.g., `2047`) into the DAC Data Register. The hardware internally scales this and physically outputs exactly 1.65V on the physical pin. If you use DMA to stream an array of mathematical sine-wave values into the DAC register very quickly, the pin will physically output a smooth electrical sine wave, which can be amplified to play sound through a speaker.

## 5. Noise and Averaging
Analog signals are extremely susceptible to electromagnetic noise. An ADC reading might jump wildly (`2047`, `2060`, `2035`) even if the physical voltage is perfectly stable. 
*Software Fix:* Read the ADC 10 times in a row and calculate the mathematical average to smooth out the noise.
*Hardware Fix:* Add a capacitor to the pin.

## 6. Example
*(See `examples/` for C++ math converting raw ADC values).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
