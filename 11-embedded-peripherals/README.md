# 11 — Embedded Peripherals (Hardware Bridge)

This chapter connects software concepts (pointers, bit manipulation, volatile) to physical hardware. It represents the **bridge** from C/C++ knowledge to actual embedded firmware development.

```text
C/C++ Knowledge → Pointer → volatile → Bit Manipulation → Register → Peripheral → Hardware
```

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Memory-Mapped I/O](./01-memory-mapped-io/) | Address space, bus |
| 02 | [Registers](./02-registers/) | Control/status/data registers |
| 03 | [Bit Manipulation](./03-bit-manipulation/) | Set, clear, toggle, mask |
| 04 | [GPIO](./04-gpio/) | Digital I/O, LED, button |
| 05 | [UART](./05-uart/) | Serial communication |
| 06 | [SPI](./06-spi/) | Synchronous serial |
| 07 | [I2C](./07-i2c/) | Two-wire interface |
| 08 | [ADC](./08-adc/) | Analog-to-digital conversion |
| 09 | [PWM](./09-pwm/) | Pulse-width modulation |
| 10 | [Timer](./10-timer/) | Hardware timers |
| 11 | [DMA](./11-dma/) | Direct memory access |
| 12 | [Watchdog](./12-watchdog/) | System reset on hang |
| 13 | [Bootloader](./13-bootloader/) | Firmware update |
| 14 | [HAL](./14-hal/) | Hardware abstraction layer |
| 15 | [Driver](./15-driver/) | Driver architecture |
| 16 | [BSP](./16-bsp/) | Board support package |

## Hardware Abstraction Layers

```text
Application
    │
    ▼
Service / Logic
    │
    ▼
Driver
    │
    ▼
HAL
    │
    ▼
MCU Peripheral Register
    │
    ▼
Hardware
```
