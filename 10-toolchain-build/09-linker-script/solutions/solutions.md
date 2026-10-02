# Solutions: Linker Script

## Solution 1: RAM Overflow
**Answer:** The build will fail at **Stage 4 (The Linker)**. 
- Stage 2 (The Compiler) does not know how much RAM the chip has. It successfully generates the `.o` file with a massive `.bss` section requirement.
- The Linker is the only tool that reads the `.ld` Linker Script. It sees `RAM: LENGTH = 20K`. When it tries to map the 30 KB `.bss` section into the RAM region, it realizes it won't fit. The Linker halts and throws an error like: `region 'RAM' overflowed by 9520 bytes`.

## Solution 2: `_sdata` vs C++ Variables
**Answer:** A normal C++ variable occupies physical memory space to hold a value. For example, `int x = 5` means there is an address (e.g., `0x20000000`) that holds the value `5`.
A Linker Script symbol does **not** occupy memory space. It is *literally just an address*. When the Linker Script says `_sdata = 0x20000000`, it is just adding an entry to the Symbol Table mapping the name `_sdata` to the address `0x20000000`. 
If you write `uint32_t val = _sdata;`, C++ will go to the address `0x20000000` and read the random first 4 bytes of your `.data` section. To get the actual address number (`0x20000000`), you must ask C++ for the *address* of the symbol (`&_sdata`).
