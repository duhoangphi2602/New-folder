# Exercises: Optimization

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Flash Memory Limit
Your microcontroller has 32 KB of Flash memory.
You write a complex application. 
You compile with `-O0`. The `.bin` file is 40 KB. (Fails to flash).
You compile with `-O3`. The `.bin` file is 35 KB. (Fails to flash).
**Task:** What compiler flag should you use as a last resort to make the firmware fit into the chip? Why did `-O3` fail to shrink it enough?

## Exercise 2: The Useless Struct
```cpp
void calculate_sensor() {
    struct Vector3D { float x, y, z; } data;
    data.x = read_adc(1);
    data.y = read_adc(2);
    data.z = read_adc(3);
    
    float magnitude = sqrt((data.x * data.x) + (data.y * data.y));
}
```
Assume `read_adc()` is a function that accesses a `volatile` hardware register.
**Task:** If compiled with `-O3`, which lines of code in this function will the compiler delete, and which lines will it keep? Apply the "As-If" rule regarding observable behavior.
