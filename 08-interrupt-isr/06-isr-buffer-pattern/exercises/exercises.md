# Exercises: The ISR Buffer Pattern

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Queue Overload
A developer connects an audio ADC (Analog to Digital Converter) to their microcontroller. The ADC samples audio at 44,100 Hz (44,100 hardware interrupts per second). 
The developer writes:
```c
void ADC_ISR() {
    uint16_t audio_sample = ADC_DATA;
    xQueueSendFromISR(audio_queue, &audio_sample, NULL);
}
```
**Task:** Describe mechanically what will happen to the RTOS Scheduler when this code runs. How much CPU time is left for the UI Task?

## Exercise 2: DMA (Direct Memory Access)
**Task:** Even the Ring Buffer pattern takes ~10 CPU cycles per byte. For extremely high-speed data (like video or 44kHz audio), 10 CPU cycles per byte is still too much overhead. What hardware peripheral exists on modern microcontrollers to completely bypass the CPU and move data directly from the ADC into RAM without triggering an ISR for every byte?
