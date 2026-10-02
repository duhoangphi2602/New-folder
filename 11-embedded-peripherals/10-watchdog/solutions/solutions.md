# Solutions: Watchdog

## Solution 1: The Bootloader Trap
**Answer:** Exactly 2 seconds after the Application starts, the hardware will physically reset the chip, returning execution back to the Bootloader. This will create an infinite 2-second boot-loop.
**Can the Application disable it?** NO. By design, once the Independent Watchdog (IWDG) is enabled in hardware, it is permanently locked on. No software command can turn it off. The only way to stop it is a physical loss of power or a hardware reset. The junior developer must update the Application code to kick the dog.

## Solution 2: RTOS Multi-Threaded Watchdog
**Answer:** If you only kick the dog in `Thread_Sensors`, and `Thread_WiFi` crashes, the RTOS task scheduler will likely still allow `Thread_Sensors` to run. The watchdog will be fed, and the system will *not* reboot, leaving the device permanently disconnected from WiFi.
**The Architecture (Event Group / Flag method):**
1. Create a dedicated `Thread_Watchdog`.
2. `Thread_Sensors` sets a flag (e.g., `flag_sensors_ok = true`) every time it successfully completes a loop.
3. `Thread_WiFi` sets `flag_wifi_ok = true`.
4. `Thread_UI` sets `flag_ui_ok = true`.
5. `Thread_Watchdog` wakes up every 1 second. It checks:
```cpp
if (flag_sensors_ok && flag_wifi_ok && flag_ui_ok) {
    kick_dog(); // Everyone is healthy! Feed it.
    // Reset flags to false for the next cycle
    flag_sensors_ok = false; flag_wifi_ok = false; flag_ui_ok = false;
} else {
    // Do nothing! Let the dog starve and reboot the system.
    // One of the threads failed to report in.
}
```
