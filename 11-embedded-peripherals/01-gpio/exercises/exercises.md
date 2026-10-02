# Exercises: GPIO

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Magic Touch
You configure Pin `PB3` as an Input to read a physical push-button. You wire one side of the button to `PB3`, and the other side to Ground.
When you test the code, the button works perfectly sometimes. But other times, just moving your hand *near* the wires causes the microcontroller to think the button was pressed. 
**Task:** What critical hardware configuration step did you forget in your C++ code? Explain the physics of why your hand is causing the pin to trigger.

## Exercise 2: The Short Circuit
You have two microcontrollers connected by a single wire to exchange data. 
Microcontroller A configures the pin as Output (Push-Pull) and writes a `1` (outputs 3.3V).
Microcontroller B configures its pin as Output (Push-Pull) and writes a `0` (outputs 0V).
**Task:** What happens physically to the wire and the microcontrollers? How does configuring the pins as "Open-Drain" solve this exact problem?
