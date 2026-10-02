# ELF (Executable and Linkable Format)

## 1. What is an ELF file?
When the Linker finishes merging all `.o` files, it packages the final output into a standard format called ELF (on Linux/ARM) or PE (Portable Executable, on Windows `.exe`).
The ELF file contains the absolute, finalized physical memory addresses for every single function and variable.

## 2. The Internal Structure
An ELF file is divided into distinct segments:
1. **ELF Header:** The "Table of Contents". It states the target architecture (e.g., ARM), the Entry Point (the physical memory address of the `Reset_Handler`), and where to find the other sections inside the file.
2. **Program/Section Headers:** Tells the flasher tool: *"Take the next 1024 bytes and put them in Flash at `0x08000000` (`.text`). Take the 50 bytes after that and put them in Flash at `0x08000400` (`.data`)."*
3. **The Raw Machine Code:** The actual `1`s and `0`s for your `.text` and `.data` sections.
4. **Symbol Table & Debug Metadata (DWARF):** This is the magic part. If compiled with the `-g` flag, the ELF file contains a massive dictionary that maps physical machine code addresses back to human-readable C++ line numbers. (e.g., "Address `0x08000104` corresponds to `main.cpp`, line 42, variable `sensor_value`").

## 3. The Size Illusion
Beginners often panic when they see their `.elf` file is 5 MB, while their microcontroller only has 128 KB of Flash memory.
**Do not panic.**
The microcontroller will *never* see the Symbol Table or Debug Metadata. Those sections are strictly for your PC's debugger (like GDB or an IDE). Only the pure `.text` and `.data` sections (which might only be 20 KB) are actually extracted and flashed into the silicon.

## 4. The `readelf` tool
You can inspect the internals of an ELF file using the toolchain command `readelf`.
- `readelf -h firmware.elf`: Shows the ELF header (Target architecture, Entry point).
- `readelf -S firmware.elf`: Shows the Section sizes (`.text`, `.data`, `.bss`).

## 5. Example
*(See `examples/` for a simulated `readelf` output).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
