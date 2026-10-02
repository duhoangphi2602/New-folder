# Semihosting

## 1. Concept
"Semihosting" means the microcontroller relies on the "Host" (your PC) to perform I/O operations. When the microcontroller hits a `printf` statement, it triggers a special hardware breakpoint instruction (like `BKPT`). The hardware debugger (e.g., ST-Link) sees this breakpoint, pauses the CPU, reads the string out of the microcontroller's RAM, sends it over USB to your IDE, and then resumes the CPU.

## 2. Why
1. **Zero Hardware Required:** If you can flash code to the chip (via SWD), you can use Semihosting. No UART wires, no baud rate configurations, no USB-to-TTL adapters.
2. **File I/O:** Semihosting doesn't just do `printf`. It can also do `fopen` and `fwrite`, allowing your bare-metal microcontroller to save files *directly onto your laptop's hard drive*.

## 3. How to Enable (ARM GCC)
You do not write a `_write` function. Instead, you tell the linker to link against the semihosting library provided by Newlib.
In your linker flags (usually in a Makefile or CMake), you add:
`--specs=rdimon.specs -lrdimon`

Then, at the very beginning of `main()`, you must call:
`initialise_monitor_handles();`

## 4. Example
*(See `examples/` for pseudo-code showing a semihosting setup).*

## 5. Trade-offs (The Fatal Flaw)
Semihosting has a devastating performance penalty.
When you use a blocking UART driver, the CPU is slow, but it is still running and processing interrupts.
When you use Semihosting, the debugger literally **halts the entire CPU core** for a few milliseconds while it reads the RAM. 
If your drone is flying, and you hit a Semihosting `printf`, the drone's CPU stops executing code, the PID controllers freeze, the motors stop updating, and the drone crashes into the ground.

Furthermore, if you compile your code with Semihosting enabled, but you disconnect the ST-Link debugger and plug the board into a battery, **the board will instantly crash and freeze**. It will hit the `BKPT` instruction, wait for a debugger that isn't there, and hang forever.

## 6. UART vs SWO vs Semihosting

| Feature | UART | SWO (Serial Wire Output) | Semihosting |
|---------|------|--------------------------|-------------|
| **Wires Needed** | TX, RX, GND | 1 extra pin (SWO) | **None** (Uses existing debug pins) |
| **Performance** | Slow (Polling) or Fast (DMA) | Extremely Fast (Hardware Trace) | **Terrible** (Halts the CPU) |
| **Standalone Mode**| Works perfectly | Works perfectly | **Crashes if debugger unplugged** |

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
