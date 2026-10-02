# Exercises: DMA

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Address Increment
When configuring the DMA to copy a 100-byte array from RAM out to a UART peripheral (Memory-to-Peripheral), you must configure two specific settings:
- `Memory_Increment_Mode` (Enable or Disable)
- `Peripheral_Increment_Mode` (Enable or Disable)
**Task:** For this UART transmission, which of these two settings should be Enabled, and which should be Disabled? Explain exactly why based on physical memory addresses.

## Exercise 2: The Half-Transfer Interrupt
You are using an ADC to continuously sample a microphone at 44.1 kHz. You use DMA in **Circular Mode** to pump the audio data into a 1000-byte array in RAM.
When the array is full, the DMA wraps around to index 0 and starts overwriting the old data.
The DMA has a "Transfer Complete (TC)" interrupt (fires at byte 1000) and a "Half-Transfer (HT)" interrupt (fires at byte 500).
**Task:** Why is the Half-Transfer interrupt absolutely critical for processing continuous streaming data like audio? How do you use the TC and HT interrupts together to ensure you never lose data?
