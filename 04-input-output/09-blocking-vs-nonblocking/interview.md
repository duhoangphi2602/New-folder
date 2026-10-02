# Interview Questions: Blocking vs Non-Blocking I/O

## 1. What is Polling, and why is it generally considered bad practice in complex embedded applications?
**Answer:** Polling is a Blocking I/O technique where the CPU continuously checks a hardware status register in a tight `while` loop, waiting for a condition to be met (like data arriving). It is bad practice because it burns 100% of the CPU's processing power doing nothing, completely preventing the execution of other tasks. In a system with multiple sensors and real-time control loops, polling a slow peripheral will cause the entire system to miss critical timing deadlines.

## 2. How does an Interrupt-Driven (Non-Blocking) UART receiver work?
**Answer:** In an interrupt-driven architecture, the CPU does not wait for data. It configures the UART hardware and then continues executing the main program. When a full byte of data arrives at the RX pin, the UART hardware generates an electrical Interrupt signal. This forces the CPU to pause its current task, jump to a specific function called an Interrupt Service Routine (ISR), read the byte into a RAM buffer (like a Ring Buffer), and then instantly resume its previous task.

## 3. What is DMA, and how does it differ from Interrupt-Driven I/O?
**Answer:** Direct Memory Access (DMA) is a dedicated hardware controller that moves data directly between memory (RAM) and a peripheral (like UART or SPI) without the CPU's involvement. While Interrupts are non-blocking, they still require the CPU to execute software (the ISR) for *every single byte* transferred. DMA completely offloads this; the CPU configures the DMA once (e.g., "Move this 10KB array to UART"), and the DMA handles all 10,000 bytes autonomously, firing a single interrupt only when the entire transaction is complete. This achieves absolute maximum CPU efficiency.
