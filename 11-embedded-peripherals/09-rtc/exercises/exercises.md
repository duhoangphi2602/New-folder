# Exercises: RTC

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The BCD Trap
You write a function to set the alarm time to exactly 30 seconds.
```cpp
void set_alarm_seconds() {
    uint8_t seconds = 30; // I want 30 seconds
    RTC->ALARM_R = seconds; // Write directly to the BCD register
}
```
**Task:** When the RTC starts running, at exactly what physical second (e.g., 10s, 20s, 48s?) will this alarm actually fire? Explain why writing the integer `30` directly into a BCD register causes this catastrophic timing bug.

## Exercise 2: UNIX Time vs RTC Registers
A senior engineer tells you: *"Don't use the hardware BCD Calendar registers. Just configure the RTC as a massive 32-bit counter that ticks once a second. Store UNIX Epoch Time (seconds since Jan 1, 1970) in it, and convert it to human time via software."*
**Task:** What is the primary advantage of using a flat UNIX timestamp in an IoT device that syncs with cloud servers, compared to relying on the microcontroller's internal BCD calendar logic?
