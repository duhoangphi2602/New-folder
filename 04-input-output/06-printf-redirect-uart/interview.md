# Interview Questions: Printf Redirection to UART

## 1. What is the role of the `_write` (or `fputc`) function in an embedded C project?
**Answer:** It acts as the bridge between the hardware-agnostic C standard library and the hardware-specific peripherals. Functions like `printf` only format data into a RAM buffer. To physically transmit that data, the standard library calls the low-level system hook `_write`. By implementing `_write` to push characters to a UART data register, the developer "redirects" all standard output to the serial port.

## 2. Why must you inject a `\r` (Carriage Return) before every `\n` (Line Feed) when redirecting `printf` to a UART terminal?
**Answer:** Standard PC serial terminal emulators (like PuTTY or TeraTerm) behave like ancient mechanical typewriters. A Line Feed (`\n`) only moves the cursor straight down; it does not return it to the left edge of the screen. This causes subsequent text to stair-step across the screen. A Carriage Return (`\r`) is required to explicitly pull the cursor back to column 0.

## 3. If your UART driver is "blocking" (uses a while-loop to wait for transmission), what is the danger of placing `printf` statements inside a high-speed control loop?
**Answer:** It will cause catastrophic timing failures. UART is extremely slow (e.g., 1ms per character at 9600 baud). If you print a 30-character string inside a motor control loop that must execute every 1 millisecond, the blocking UART driver will freeze the CPU for 30 milliseconds. The control loop will miss 30 deadlines, the PID controller will destabilize, and the physical system (like a drone or robot) will likely crash.
