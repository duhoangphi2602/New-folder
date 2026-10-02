# Exercises: RAII

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Bug
Here is a classic piece of C code written by a junior developer for a bare-metal microcontroller:
```c
void flash_firmware(uint8_t* data) {
    disable_interrupts(); // Stop all background tasks while flashing
    
    if (data == NULL) {
        return; 
    }
    
    if (check_checksum(data) == false) {
        return;
    }
    
    write_to_flash(data);
    enable_interrupts();
}
```
**Task:** Identify the two catastrophic bugs in this code.

## Exercise 2: Implementing RAII
**Task:** Write a simple C++ RAII class named `InterruptGuard`. Its constructor should call `disable_interrupts()` and its destructor should call `enable_interrupts()`. Then, rewrite the `flash_firmware` function from Exercise 1 using your new `InterruptGuard` to make it perfectly safe.
