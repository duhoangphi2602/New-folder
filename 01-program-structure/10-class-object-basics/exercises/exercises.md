# Exercises: Class & Object Basics

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Struct vs Class
You are given the following C++ code:
```cpp
struct DataPacket {
    int id;
    void print_id();
};

class DataHandler {
    int id;
    void print_id();
};
```
**Task:** If you try to access `id` and call `print_id()` from `main()`, what will happen for the `DataPacket` object? What will happen for the `DataHandler` object? Why?

## Exercise 2: The `const` Correctness Bug
A developer writes a class to manage a buffer.
```cpp
class Buffer {
public:
    Buffer() : size_(10) {}
    int get_size() { return size_; }
private:
    int size_;
};

void print_buffer_info(const Buffer& buf) {
    std::cout << "Size: " << buf.get_size() << "\n";
}
```
**Task:** This code will fail to compile at the `buf.get_size()` line. Why? How do you fix the `Buffer` class so this compiles?

## Exercise 3: Memory Footprint
You are tasked with porting a C struct to a C++ class for an MCU with severe RAM constraints.
**C Code:**
```c
struct UartC {
    uint32_t baud_rate;
    uint8_t port_id;
};
```
**C++ Code:**
```cpp
class UartCpp {
public:
    UartCpp(uint32_t b, uint8_t p) : baud_rate_(b), port_id_(p) {}
    void init();
    void send(uint8_t data);
private:
    uint32_t baud_rate_;
    uint8_t port_id_;
};
```
**Task:** What is the RAM footprint (size in bytes) of a `UartC` variable? What is the RAM footprint of a `UartCpp` object? Do the constructor and member functions increase the RAM size of the object?
