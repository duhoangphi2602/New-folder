# Exercises: I2C

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing Resistors
You wire up an I2C OLED screen to your microcontroller. You connect VCC, GND, SCL, and SDA perfectly. 
You write the C++ code, configure the pins as Open-Drain, and attempt to send the Start Condition.
The code instantly hangs in an infinite loop waiting for the bus to be ready. 
You hook up an oscilloscope to the SDA and SCL wires and see that the voltage is permanently stuck at `0.0V`. 
**Task:** Why are the lines stuck at 0V? What physical component did you forget to add to your breadboard circuit?

## Exercise 2: Comparing SPI and I2C
You are designing a data-logging system. You need to connect **five** identical temperature sensors to your microcontroller.
The sensor model you chose is available in both SPI and I2C versions.
**Task:** 
1. If you choose the SPI version, how many total GPIO pins will you need on your microcontroller to connect all 5 sensors?
2. If you choose the I2C version, how many total GPIO pins will you need? What is a potential issue with connecting 5 identical I2C sensors to the same bus?
