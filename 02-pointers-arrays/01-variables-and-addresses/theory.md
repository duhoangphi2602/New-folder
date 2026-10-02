# Variables and Addresses

## 1. Concept
Every variable you declare in a C/C++ program is ultimately stored in the computer's memory (RAM). This memory is essentially a massive array of 1-byte slots. Each slot is identified by a unique, sequential number called a **memory address**.

## 2. Why
To interact with hardware peripherals (like turning on an LED or reading a sensor), you must write data to specific, hardcoded memory addresses defined by the silicon manufacturer. If you don't understand how variables map to addresses, you cannot write hardware drivers.

## 3. Syntax (The Address-of Operator)
You can find where any variable lives in memory using the address-of operator (`&`).

```cpp
#include <iostream>
#include <cstdint>

int main() {
    uint32_t my_var = 42;
    
    // Print the value
    std::cout << "Value: " << my_var << '\n';
    
    // Print the address (usually prints in Hexadecimal)
    std::cout << "Address: " << &my_var << '\n';
}
```

## 4. Example (The Mental Model)
*(See `examples/` for runnable code demonstrating address inspection).*

Think of memory as a massive row of mailboxes. Each mailbox holds exactly 1 byte (8 bits) of data, and each mailbox has a sequential hexadecimal number on the front (the address).

```text
Address:   0x20000000   0x20000001   0x20000002   0x20000003
Data:     [   0x12   ] [   0x34   ] [   0x56   ] [   0x78   ]
```
A `uint8_t` occupies 1 byte, so it takes 1 address.
A `uint32_t` occupies 4 bytes, so it takes 4 consecutive addresses. When you print `&my_var` for a 32-bit integer, C++ gives you the address of the **very first byte** (the lowest address), in this case, `0x20000000`.

## 5. Embedded usage
On a desktop PC, the OS gives your program "virtual" addresses. They change every single time you run the program for security reasons. 
On a bare-metal microcontroller, addresses are **physical and fixed**. If the datasheet says the GPIO Port A Output Register is at `0x40020014`, it is *exactly* there, every single time the chip boots. You will regularly cast raw hexadecimal numbers into pointers to access these registers.

## 6. Trade-offs

| Paradigm | Pros | Cons |
|----------|------|------|
| **Manual Memory/Addresses (C/C++)** | Absolute control over hardware. Maximum performance. | Easy to accidentally read/write the wrong address (segmentation fault). |
| **Managed Memory (Java, Python)** | 100% memory safe. | Impossible to write bare-metal hardware drivers directly. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice finding addresses.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
