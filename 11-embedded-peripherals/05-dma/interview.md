# Interview Questions: DMA

## 1. What is the primary benefit of using DMA over Interrupt-driven (ISR) data transfer?
**Answer:** DMA eliminates "Context Switching Overhead". In an ISR-driven transfer, for every single byte received over UART/SPI, the CPU must stop its current task, save its registers to the Stack, jump to the ISR, copy the byte, restore its registers, and resume its task. Doing this 100,000 times a second paralyzes the CPU. DMA is a dedicated hardware controller that moves the data silently in the background directly from the peripheral to RAM, without interrupting the CPU at all. The CPU is only interrupted once, when the entire block of 100,000 bytes is completely finished.

## 2. In a DMA Memory-to-Peripheral transfer (like sending data to SPI), do you increment the Memory Address, the Peripheral Address, or both?
**Answer:** You must increment the Memory Address, but you strictly disable incrementing the Peripheral Address. The memory data is a sequential array (e.g., bytes `0`, `1`, `2` are at addresses `0x2000`, `0x2001`, `0x2002`). The DMA must march forward through this array. However, the SPI Data Register is a single, fixed hardware address (e.g., `0x4001300C`). Every single byte from the array must be written to that exact same physical SPI register address.

## 3. What is "Cycle Stealing" in the context of DMA?
**Answer:** The CPU and the DMA controller share the same physical Memory Bus (the wires connecting them to the RAM). If the CPU tries to fetch a variable from RAM at the exact same microsecond that the DMA is trying to write a UART byte to RAM, they cannot both use the bus simultaneously. The internal Arbiter will usually pause the CPU for one clock cycle to let the DMA finish its transfer. This is called "Cycle Stealing". It means heavy DMA traffic can slightly reduce the CPU's overall execution speed, but it is vastly more efficient than forcing the CPU to handle the transfer manually.
