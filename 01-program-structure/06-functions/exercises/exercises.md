# Exercises: Functions

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Swapper
Write three different C++ functions that swap the values of two integers `a` and `b`.
1. `void swap_val(int a, int b);`
2. `void swap_ptr(int* a, int* b);`
3. `void swap_ref(int& a, int& b);`

**Task:** Which of these functions will successfully swap the values in the calling function (`main`)? Why does the other one fail?

## Exercise 2: Stack Memory Calculation
Consider the following struct and function:
```cpp
struct Matrix {
    float data[16][16]; // 16x16 matrix of 32-bit floats
};

void math_operation(Matrix m1, Matrix m2) {
    // perform math
}
```
**Task:** In bytes, exactly how much stack memory is consumed just by passing the arguments to `math_operation`? If you were running this on an STM32 with a 2KB stack limit, what would happen? How do you fix it?

## Exercise 3: Dangling Reference
A junior developer writes a function to create a hardware configuration:
```cpp
const std::string& get_default_device_name() {
    std::string name = "Sensor_A";
    return name;
}
```
**Task:** What is fundamentally wrong with this function? What will happen when the caller tries to use the returned reference?
