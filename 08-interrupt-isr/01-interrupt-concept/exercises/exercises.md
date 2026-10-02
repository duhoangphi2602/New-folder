# Exercises: Interrupt Concept

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Vector Table
If an embedded system has 50 different hardware peripherals (UART1, UART2, I2C, SPI, Timer1, Timer2, GPIO_PortA, etc.), how does the CPU hardware know *exactly* which ISR function to run when a specific peripheral fires an interrupt?

## Exercise 2: Power Saving
A battery-powered IoT thermometer reads the temperature every 60 seconds and then goes to sleep.
**Task:** Explain how the CPU's Sleep mode (`WFI` - Wait For Interrupt instruction on ARM) relies entirely on the Interrupt architecture to save battery life. Could you achieve this with Polling?
