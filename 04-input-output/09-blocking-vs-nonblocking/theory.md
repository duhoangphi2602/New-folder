# Blocking vs Non-Blocking I/O

## 1. Concept

**Blocking I/O (Polling):**
The CPU asks the hardware, *"Are you done yet?"* 
Hardware: *"No."*
CPU: *"Are you done yet?"*
Hardware: *"No."*
The CPU spins in a `while` loop, burning 100% of its power, unable to do anything else until the hardware finishes.

**Non-Blocking I/O (Interrupts):**
The CPU tells the hardware: *"Send this byte. Tap me on the shoulder when you're done."*
The CPU immediately goes to do other work (like math, or sleeping to save battery). 
When the hardware finishes, it sends a physical electrical signal (an Interrupt) to the CPU. The CPU briefly pauses, sends the next byte, and goes back to its work.

## 2. Why
A UART sending at 9600 baud takes ~1,000 microseconds (1 millisecond) to send a single character. 
A modern Cortex-M4 CPU running at 100MHz can execute **100,000 instructions** in that same millisecond. 
If you use Blocking I/O, you throw away 100,000 instructions of computing power just to send one character.

## 3. The Three Architectures

### Level 1: Blocking (Polling)
- **How it works:** `while ((UART->SR & TXE) == 0); UART->DR = c;`
- **Pros:** Extremely simple. No concurrency bugs.
- **Cons:** CPU usage is 100%. Destroys real-time timing for other tasks.
- **Use Case:** Very simple projects, bootloaders, or fatal error handlers where the system is already dead.

### Level 2: Interrupt-Driven (Non-Blocking)
- **How it works:** The CPU fills a "Ring Buffer" (a circular array in RAM) with the string to print, enables the UART interrupt, and leaves. The hardware automatically triggers an Interrupt Service Routine (ISR) every time it finishes a byte. The ISR pulls the next byte from the Ring Buffer and gives it to the hardware.
- **Pros:** CPU is completely free to run the main program.
- **Cons:** Complex to write. Requires atomic locks or volatile variables to prevent Race Conditions.
- **Use Case:** The industry standard for most I/O (Sensors, standard UART, UI buttons).

### Level 3: Direct Memory Access (DMA)
- **How it works:** DMA is a secondary mini-CPU inside the microcontroller dedicated purely to moving memory. The CPU tells the DMA: *"Here is a 10KB array in RAM. Send it to the UART."* The CPU leaves. The DMA controller autonomously streams all 10KB to the UART without interrupting the main CPU a single time.
- **Pros:** Absolute maximum performance. Zero CPU overhead.
- **Cons:** Very complex to configure.
- **Use Case:** High-speed data (Audio, Video, massive SD card writes).

## 4. Example
*(See `examples/` for a theoretical comparison of CPU time usage).*

## 5. Embedded usage (The Receiver Problem)
Blocking is especially catastrophic for **Receiving** data.
If you write `char c = uart_read_blocking();`, the CPU will halt forever until the user presses a key on the keyboard. If the user goes to lunch, your drone falls out of the sky. 
**Rule:** You must *never* use Blocking I/O to wait for external input on a bare-metal system.

## 6. Trade-offs (Complexity vs Performance)
Migrating from Blocking to Interrupts requires a massive leap in architectural complexity. You must learn about Ring Buffers, Volatile variables, Interrupt Priorities, and Race Conditions. *(These topics will be covered deeply in Chapter 08: Interrupts & ISRs).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
