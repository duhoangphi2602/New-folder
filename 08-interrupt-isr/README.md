# 08 — Interrupts & ISR

Interrupts are the primary mechanism for responding to hardware events in real-time. Understanding ISR constraints is essential for writing correct, safe firmware.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Interrupt Concept](./01-interrupt-concept/) | Hardware event → CPU → ISR |
| 02 | [ISR](./02-isr/) | Rules: short, bounded, minimal |
| 03 | [ISR Restrictions](./03-isr-restrictions/) | No malloc, no printf, ISR-safe API |
| 04 | [Interrupt Latency](./04-interrupt-latency/) | Sources of delay |
| 05 | [Interrupt Nesting](./05-interrupt-nesting/) | Nested interrupts, priority |
| 06 | [ISR Buffer Pattern](./06-isr-buffer-pattern/) | ISR → Ring Buffer → Task |
| 07 | [Shared Data (ISR & Main)](./07-shared-data-isr-main/) | volatile flag, atomic, critical section |
