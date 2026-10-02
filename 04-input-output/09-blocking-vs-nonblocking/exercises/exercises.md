# Exercises: Blocking vs Non-Blocking I/O

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The "Delay" Trap
Many Arduino beginners use `delay(1000);` to make an LED blink every 1 second.
```cpp
void loop() {
    toggle_led();
    delay(1000);
    read_emergency_stop_button();
}
```
**Task:** `delay()` is essentially a blocking I/O function (polling a hardware timer). What is the catastrophic real-world consequence of the code above?

## Exercise 2: Selecting an Architecture
You are designing the architecture for three different systems. Choose whether you would use **Polling**, **Interrupts**, or **DMA** for the UART driver in each system, and explain why.
1. The Bootloader: A tiny piece of code that runs for 1 second at startup to print "Booting...".
2. The User Interface: Receiving command characters typed by a human on a keyboard.
3. The Camera: Streaming a 2-Megabyte JPEG image over a high-speed SPI port to an SD Card.
