# UART Serial Communication

## 1. Concept
UART is a hardware peripheral that converts data between **Parallel** (a full 8-bit byte inside the CPU) and **Serial** (a single wire pulsing high and low 8 times). 
It requires only 2 data wires:
- **TX (Transmit):** Sends data out. (Connects to the RX of the other device).
- **RX (Receive):** Reads data in. (Connects to the TX of the other device).

## 2. Why
It is simple, universal, and requires no clock wire. Because it is *Asynchronous*, there is no clock signal shared between the two devices. To understand each other, both devices must agree beforehand on the exact speed they will talk. This speed is called the **Baud Rate** (e.g., 115200 bits per second).

## 3. The UART Frame (How data looks on the wire)

When the UART line is idle, the voltage is held HIGH (1).
To send the character `'A'` (Binary: `01000001`), the UART hardware automatically constructs a **Frame**:

1. **Start Bit:** The TX line is pulled LOW (0) for exactly 1 clock cycle to wake up the receiver.
2. **Data Bits:** The 8 bits of data are sent, usually LSB (Least Significant Bit) first.
3. **Parity Bit (Optional):** An extra bit used to detect errors. (Usually disabled).
4. **Stop Bit:** The TX line is pulled HIGH (1) for 1 (or 2) clock cycles to signal the end of the frame.

## 4. Example
*(See `examples/` for a mock implementation of a bare-metal UART driver).*

## 5. Embedded usage (The Bare-Metal Driver)

To send data via UART, you don't toggle the pins yourself. You just write a byte to the hardware Data Register. 
However, if you write bytes too fast, the hardware won't have time to shift them out of the pin, and data will be overwritten. You must check the Status Register!

```cpp
struct UART_RegDef {
    volatile uint32_t SR;  // Status Register
    volatile uint32_t DR;  // Data Register
};
auto* const UART1 = reinterpret_cast<UART_RegDef*>(0x40011000);

// Bit 7 in the Status Register means "Transmit Data Register Empty" (TXE)
constexpr uint32_t TXE_FLAG = (1 << 7);

void uart_send_char(char c) {
    // 1. Wait (Block) until the hardware says it is empty and ready
    while ((UART1->SR & TXE_FLAG) == 0) {
        // Spin in a tight loop doing nothing (Polling/Blocking)
    }
    
    // 2. The register is empty. Write the character!
    // The hardware will now automatically shift it out of the TX pin.
    UART1->DR = c; 
}
```
This is called **Polling** or **Blocking I/O**. It is incredibly simple, but heavily wastes CPU time because the CPU is stuck in the `while` loop waiting for the slow UART hardware.

## 6. Trade-offs (Blocking vs Interrupts)

| Architecture | Description | Pros | Cons |
|--------------|-------------|------|------|
| **Polling (Blocking)** | The CPU sits in a `while` loop waiting for the UART. | Extremely simple to write. No concurrency bugs. | Wastes 99% of CPU time. Other tasks freeze. |
| **Interrupts (Non-Blocking)** | The CPU does other work. The UART hardware fires a hardware interrupt signal when it finishes. | Highly efficient. | Complex. Requires Ring Buffers and dealing with Race Conditions. |
| **DMA (Direct Memory Access)** | Hardware independently streams a massive RAM buffer to the UART without the CPU. | Zero CPU overhead. | Hardest to configure. Overkill for short logs. |

*(For simple `printf` logging, Polling is the standard approach).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
