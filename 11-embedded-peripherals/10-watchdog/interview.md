# Interview Questions: Watchdog

## 1. Why should you NEVER kick a watchdog inside a hardware Interrupt Service Routine (ISR)?
**Answer:** The primary purpose of a watchdog is to reset the system if the main program loop freezes (e.g., gets stuck in a `while` loop waiting for an unresponsive I2C sensor). Hardware interrupts (like a Timer or UART interrupt) operate independently of the main loop. If the main loop freezes, the hardware will still fire the interrupts, and the CPU will happily execute the ISR. If the ISR contains the code to kick the watchdog, the watchdog will continuously be fed, and the system will never reset, completely defeating the purpose of the watchdog. The watchdog must only be kicked in the main Super Loop or via a centralized RTOS task manager.

## 2. What is the difference between an Independent Watchdog (IWDG) and a Window Watchdog (WWDG)?
**Answer:** 
- The **IWDG** acts purely as a maximum timeout. It runs on its own dedicated, ultra-low-speed internal oscillator (LSI) so it survives even if the main clock crystal breaks. You can kick it at any time, as long as it's before the counter reaches 0.
- The **WWDG** enforces both a maximum and a *minimum* timeout. It defines a time "Window". You cannot kick it too late (or it resets), and you cannot kick it too early (or it resets). This is used in safety-critical systems to ensure the CPU is executing code at the exact expected speed.

## 3. Once initialized, can you disable the Independent Watchdog via software if you want to enter a low-power Deep Sleep mode?
**Answer:** No. By strict hardware design, once the IWDG is enabled, it cannot be disabled by any software command. If you enter Deep Sleep, the IWDG will continue to tick, and it will eventually wake up and reset the chip. To survive Deep Sleep, you must either use specific hardware configuration bits (e.g., "Freeze IWDG on Standby") provided by the manufacturer, or you must periodically wake the CPU up from sleep just to kick the dog before going back to sleep.
