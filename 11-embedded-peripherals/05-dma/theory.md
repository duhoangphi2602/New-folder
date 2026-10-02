# DMA (Direct Memory Access)

## 1. The Bottleneck
When you receive a 100-byte UART message using Interrupts (ISR):
1. The UART hardware receives 1 byte.
2. The CPU is interrupted. It pauses its current math calculation.
3. The CPU jumps to the ISR.
4. The CPU reads the byte from the UART Data Register and writes it to an array in RAM.
5. The CPU resumes its math calculation.
This happens **100 times**. The Context Switching overhead of jumping in and out of the ISR 100 times destroys CPU performance.

## 2. Enter the DMA Controller
The DMA is a secondary, dedicated mini-processor on the silicon die. It only knows how to do one thing: Copy data from Address A to Address B.
You configure it once: *"Hey DMA, when the UART peripheral says it has a byte ready, grab it from the UART Data Register and put it into this RAM Array. Do this 100 times. Don't bother the CPU until you are completely finished."*

## 3. DMA Modes
- **Peripheral-to-Memory:** (e.g., UART RX, ADC). Data flows from a hardware peripheral into a RAM array.
- **Memory-to-Peripheral:** (e.g., SPI TX, DAC). Data flows from a RAM array out to a hardware peripheral.
- **Memory-to-Memory:** Copying a massive array in RAM to another array in RAM. Much faster than a `memcpy()` or a `for` loop because the DMA accesses the memory bus directly.

## 4. Normal vs Circular Mode
- **Normal Mode:** You tell the DMA to transfer 100 bytes. It transfers 100 bytes, stops, and fires a "Transfer Complete (TC)" interrupt. If you want to transfer more, you must explicitly restart the DMA via software.
- **Circular Mode:** You tell the DMA to transfer 100 bytes. When it hits byte 100, it instantly wraps back to byte 0 and keeps going forever. This is heavily used for streaming continuous data, like an ADC sampling audio constantly, or a DAC playing a continuous waveform.

## 5. Bus Matrix Contention
The CPU and the DMA both need to access RAM. They share the same physical wires (The Bus Matrix). If the CPU tries to read RAM at the exact same nanosecond the DMA is trying to write to RAM, who wins? 
Usually, the DMA is given priority (or they take turns via an Arbiter). This means heavy DMA traffic can slightly slow down the CPU (Cycle Stealing), but it is still vastly faster than forcing the CPU to do the copying itself.

## 6. Example
*(See `examples/` for a comparison of CPU-driven vs DMA-driven transfers).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
