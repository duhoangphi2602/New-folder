# Solutions: The Linker Script

## Solution 1: Bootloader Partitioning
**Answer:**
1. **Bootloader Linker Script:**
```ld
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
  RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 128K
}
```
2. **Main Application Linker Script:**
```ld
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08010000, LENGTH = 448K  /* 512K - 64K = 448K */
  RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 128K
}
```
*(By modifying the `ORIGIN` of the Main Application, the linker will build the `.bin` file perfectly formatted to sit at `0x08010000`, guaranteeing it won't overwrite the Bootloader).*

## Solution 2: `>RAM AT> FLASH`
**Answer:** The `.data` segment contains global variables that have a specific initial value. Because it contains variables, its execution address (Virtual Memory Address / VMA) must be in **RAM**. However, because RAM loses its contents when power is lost, the initial values must be physically stored (Load Memory Address / LMA) in **FLASH**. 
The `>RAM AT> FLASH` command tells the linker: "Assume these variables live in RAM when the program runs, but store their initial byte values inside the Flash firmware `.bin` file so the Startup Code can copy them over on boot."
