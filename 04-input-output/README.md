# 04 — Input and Output

This chapter bridges the gap between **language-level I/O** (C `printf` / C++ `iostream`) and **hardware-level I/O** (UART, serial). Understanding this connection is critical: on a desktop, `printf` writes to a terminal. On an MCU, `printf` may go nowhere — unless you explicitly redirect it to a hardware interface.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [C Standard I/O](./01-c-standard-io/) | `printf`, `scanf`, `FILE`, formatted I/O |
| 02 | [C++ I/O](./02-cpp-io/) | `iostream`, `cin`, `cout`, `fstream` |
| 03 | [Buffering](./03-buffering/) | Line vs full buffering, `fflush` |
| 04 | [Embedded I/O Overview](./04-embedded-io-overview/) | Desktop I/O vs Embedded I/O |
| 05 | [UART Serial](./05-uart-serial/) | TX/RX concept, baud rate |
| 06 | [printf Redirect to UART](./06-printf-redirect-uart/) | `_write()` retargeting |
| 07 | [Semihosting](./07-semihosting/) | Debug I/O through debugger |
| 08 | [Logging](./08-logging/) | Logging overhead, real-time impact |
| 09 | [Blocking vs Non-blocking](./09-blocking-vs-nonblocking/) | Polling vs interrupt-driven I/O |

## Key Insight

```text
printf()
   ↓
C runtime (_write / low-level output)
   ↓
UART hardware (or USB CDC / debugger)
   ↓
Serial terminal on PC
```

`printf ≠ UART`. Rather: `printf → output abstraction → implementation redirects to UART`.
