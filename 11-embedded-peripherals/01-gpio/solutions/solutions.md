# Solutions: GPIO

## Solution 1: The Magic Touch
**Answer:** You forgot to enable the internal **Pull-Up Resistor** in the GPIO configuration registers.
Because the pin was configured as an Input but left "Floating", it has infinite impedance. It acts exactly like a radio antenna. The human body holds a static electric charge and acts as a capacitor. When your hand moves near the floating wire, you induce microscopic electrical noise onto the wire. Because the pin is floating, this tiny noise is enough to swing the voltage wildly between 0V and 3.3V, causing false reads. Enabling a Pull-Up resistor anchors the voltage firmly to 3.3V until the physical button forcibly shorts it to Ground.

## Solution 2: The Short Circuit
**Answer:** Because both pins are in Push-Pull mode, Microcontroller A is violently pushing 3.3V onto the wire, while Microcontroller B is aggressively trying to sink that wire to 0V. This creates a direct electrical short circuit from VCC to GND. Infinite current will try to flow between the two chips, quickly overheating and permanently destroying the GPIO pins (or the entire silicon die).
**The Open-Drain Fix:** If both pins are in Open-Drain mode, writing a `1` doesn't push 3.3V; it just disconnects the pin. To make the wire read `1`, you rely on a single external pull-up resistor. Now, if Chip A writes `1` (disconnects) and Chip B writes `0` (pulls to GND), the wire simply goes to GND safely. There is no short circuit because neither chip is actively pushing 3.3V.
