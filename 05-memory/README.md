# 05 — Memory

This is the most important chapter for embedded engineers. Understanding memory — where data lives, how it's organized, and what happens before `main()` — is what separates embedded software from desktop software.

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Memory Concepts](./01-memory-concepts/) | Address space, RAM vs Flash |
| 02 | [Stack](./02-stack/) | Automatic storage, stack frames |
| 03 | [Heap](./03-heap/) | Dynamic allocation, `malloc`/`new` |
| 04 | [Static Storage](./04-static-storage/) | `static`, global, file-scope |
| 05 | [.text, .rodata, .data, .bss](./05-text-rodata-data-bss/) | Memory sections explained |
| 06 | [Memory Map](./06-memory-map/) | PC vs Embedded memory layout |
| 07 | [Alignment](./07-alignment/) | `alignof`, natural alignment |
| 08 | [Padding](./08-padding/) | Struct padding in memory |
| 09 | [Stack Overflow](./09-stack-overflow/) | Causes, detection, prevention |
| 10 | [Heap Fragmentation](./10-heap-fragmentation/) | Why dynamic allocation is dangerous |
| 11 | [Startup](./11-startup/) | Reset → .data copy → .bss zero → main() |
| 12 | [Vector Table](./12-vector-table/) | Reset vector, interrupt vectors |
| 13 | [Linker Script](./13-linker-script/) | MEMORY, SECTIONS, symbol placement |
| 14 | [Firmware Memory Lifecycle](./14-firmware-memory-lifecycle/) | Compile → Link → Flash → Boot → Run |

## Key Diagrams

### PC Memory Model (Conceptual)
```text
High Address
┌────────────────────┐
│      Stack    ↓    │
├────────────────────┤
│                    │
│      Heap     ↑    │
├────────────────────┤
│      BSS           │
├────────────────────┤
│      Data          │
├────────────────────┤
│      RoData        │
├────────────────────┤
│      Text          │
└────────────────────┘
Low Address
```

### Embedded MCU Memory Model (Conceptual)
```text
FLASH (Read-only at runtime)
┌─────────────────────────┐
│ Vector Table            │
├─────────────────────────┤
│ .text (machine code)    │
├─────────────────────────┤
│ .rodata (constants)     │
├─────────────────────────┤
│ .data initial values    │
└─────────────────────────┘

RAM (Read-write)
┌─────────────────────────┐
│ .data (copied from Flash)│
├─────────────────────────┤
│ .bss  (zero-filled)     │
├─────────────────────────┤
│ heap          ↑         │
│               │         │
│               ↓         │
│ stack                   │
└─────────────────────────┘
```
