# Exercises: Array vs Pointer (Decay)

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Clear Buffer Bug
A developer writes a utility function to clear any integer buffer to zero.
```cpp
void clear_buffer(int buf[]) {
    // Fill the buffer with 0s
    for (size_t i = 0; i < (sizeof(buf) / sizeof(buf[0])); i++) {
        buf[i] = 0;
    }
}

int main() {
    int my_data[100] = {1, 2, 3, 4, 5 /* ... */};
    clear_buffer(my_data);
}
```
**Task:** What is the critical bug in this code? Assuming this is compiled for a 32-bit MCU, how many elements of the `100`-element array will actually be cleared to zero? How would you fix this function?

## Exercise 2: `extern` Declarations
You have a global array defined in `sensors.cpp`:
```cpp
// sensors.cpp
int temperature_readings[50];
```
In `main.cpp`, you want to access this array. You write:
```cpp
// main.cpp
extern int* temperature_readings;
```
**Task:** This code will compile and link successfully, but it will crash immediately at runtime when you try to access `temperature_readings[0]`. Why? (Hint: Are arrays and pointers the *exact* same thing to the linker?).
