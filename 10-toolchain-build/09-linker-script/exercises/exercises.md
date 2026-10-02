# Exercises: Linker Script

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: RAM Overflow
You declare a massive global array in your C++ code: `uint8_t massive_buffer[30000];`
Your microcontroller only has 20 KB (20,480 bytes) of RAM.
When you press the "Build" button in your IDE, at exactly which toolchain stage will the build fail, and what file is responsible for detecting this error?

## Exercise 2: `_sdata` vs C++ Variables
In the `simple_linker.ld` example, you see the line `_sdata = .;`.
In your C++ code, you write:
```cpp
extern uint32_t _sdata;
void print_address() {
    printf("The data section starts at: 0x%08X", (uint32_t)&_sdata);
}
```
**Task:** Notice that the C++ code takes the *address-of* the symbol (`&_sdata`), not the *value* of the symbol (`_sdata`). Why? How does a Linker Script symbol differ from a normal C++ variable?
