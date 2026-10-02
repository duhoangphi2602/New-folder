# Exercises: Smart Pointers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Compilation Error
You are using a `std::unique_ptr` to manage a massive 10KB DMA buffer. You want to pass this buffer to a helper function so it can calculate a checksum.
```cpp
void calculate_checksum(std::unique_ptr<uint8_t[]> buf) {
    // calculate...
}

void main_task() {
    auto my_buf = std::make_unique<uint8_t[]>(10000);
    calculate_checksum(my_buf); // ERROR! Will not compile.
}
```
**Task:** Why does the C++ compiler completely refuse to compile the `calculate_checksum(my_buf);` line? What disaster is the compiler preventing?

## Exercise 2: Passing to functions
**Task:** Fix the code in Exercise 1. If `main_task` wants to keep ownership of the buffer, how should you modify the signature of `calculate_checksum` so it can access the data without triggering a compilation error?
