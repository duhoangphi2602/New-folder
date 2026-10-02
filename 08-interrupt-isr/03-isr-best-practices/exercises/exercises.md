# Exercises: ISR Best Practices

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The "While" Trap
A developer is writing an ISR for an I2C sensor. The hardware requires the CPU to wait until the `I2C_READY` bit becomes `1` before reading the data. The developer writes:
```c
void I2C_ISR() {
    while(I2C_READY == 0) {
        // Wait for hardware to be ready...
    }
    uint8_t data = I2C_DATA;
    I2C_FLAG = 0; // Clear interrupt
}
```
**Task:** Why is this a catastrophic violation of ISR best practices? What happens if the physical I2C wire gets disconnected from the circuit board?

## Exercise 2: RTOS API Selection
You need to send data from a UART ISR to a UI Task. You decide to use a FreeRTOS Queue. 
You write: `xQueueSend(my_queue, &data, portMAX_DELAY);` inside the ISR.
**Task:** Why will this code crash the microcontroller? What is the correct API function to use?
