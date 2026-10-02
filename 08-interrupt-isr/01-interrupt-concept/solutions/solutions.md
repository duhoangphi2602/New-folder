# Solutions: Interrupt Concept

## Solution 1: The Vector Table
**Answer:** The compiler generates a special array of function pointers called the **Interrupt Vector Table**, which is permanently burned into the very beginning of the Flash memory (usually starting at address `0x00000000`). Each hardware peripheral is hardcoded to a specific index in this table (e.g., UART1 might be index 16). When UART1 fires, the CPU hardware automatically jumps to Flash address `0x00000000 + (16 * 4 bytes)` and reads the memory address of the ISR function written there, then executes it.

## Solution 2: Power Saving
**Answer:** With Polling, the CPU must remain fully powered on at 100% clock speed to execute the `while` loop that checks the time. This drains the battery in days.
With Interrupts, the software configures a low-power Hardware RTC (Real Time Clock) timer for 60 seconds, and then executes the `WFI` (Wait For Interrupt) assembly instruction. The `WFI` instruction completely turns off the main CPU core, dropping power consumption to micro-amps. 60 seconds later, the RTC timer triggers a Hardware Interrupt. The interrupt signal physically powers the CPU back on, which immediately jumps to the Timer ISR to read the temperature. This extends battery life from days to years.
