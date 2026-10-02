# Watchdog Timer (WDT)

## 1. The Core Concept
The Watchdog is a very simple hardware timer that counts down from a specific value (e.g., 1000 down to 0).
If the counter ever reaches exactly `0`, the Watchdog hardware assumes the software has crashed, and it instantly fires a **Hardware Reset**, forcefully rebooting the entire microcontroller.

To prevent the system from resetting, the C++ software must periodically reset the counter back to 1000 before it reaches 0. This action is universally referred to as **"Kicking the Dog"** or **"Petting the Dog"**.

## 2. Independent Watchdog (IWDG)
The most robust type of watchdog.
- It runs on its own dedicated, internal low-speed clock (LSI - Low Speed Internal, usually ~32 kHz). 
- Even if the main 84 MHz crystal oscillator physically breaks and the CPU completely stops, the IWDG will continue ticking and successfully reboot the chip.
- Once you enable the IWDG in software, it *cannot* be disabled. It will run forever until the chip loses power or resets.

## 3. Window Watchdog (WWDG)
A more advanced watchdog used in safety-critical applications (like automotive).
- It runs on the main system clock.
- Not only must you kick it before it reaches 0, but you must **NOT** kick it too early. 
- It defines a "Window" (e.g., between 20ms and 30ms). If you kick it at 15ms (too fast), it triggers a reset. If you kick it at 35ms (too slow), it triggers a reset. This ensures the CPU is running at the exact correct speed, catching bugs where a task executes wildly out of order.

## 4. Architectural Best Practices
**Rule #1: NEVER kick the watchdog inside an Interrupt Service Routine (ISR).**
If the main `while(1)` loop gets stuck in an infinite `while(true)` bug, but the Hardware Timers are still firing interrupts, an ISR will happily continue kicking the dog. The watchdog will think everything is fine, the system will never reset, but the main code is completely dead. 
**Always kick the watchdog in the main Super Loop or via a centralized RTOS task manager.**

## 5. Example
*(See `examples/` for a conceptual implementation).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
