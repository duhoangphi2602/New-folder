# Solutions: Variables and Addresses

## Solution 1: The Stack Addresses
**Answer:** The mathematical difference between the addresses will be exactly **4 bytes**. 
Because each variable is a `uint32_t`, it consumes 4 bytes of memory. The compiler places them adjacently in the stack memory frame.
Whether the addresses are increasing or decreasing depends on the architecture and compiler, but on most modern systems (like x86 and ARM Cortex-M), the **stack grows downwards**, meaning `b` will have an address 4 bytes *lower* than `a`, and `c` will have an address 4 bytes *lower* than `b`.

## Solution 2: `cout` and `uint8_t`
**Answer:** `uint8_t` is typically a `typedef` for `unsigned char`. When you use the address-of operator `&`, it creates a pointer of type `unsigned char*`. 
In C++, `std::cout` has a special overload for `char*` and `unsigned char*` that assumes they are null-terminated C-strings! It tries to print the characters stored at that memory address until it hits a `\0` null byte, instead of printing the numeric address.
**The Fix:** You must cast the pointer to `void*` to force `cout` to treat it as a generic memory address and print it in hexadecimal format:
```cpp
std::cout << "Address: " << (void*)&status << "\n";
```
