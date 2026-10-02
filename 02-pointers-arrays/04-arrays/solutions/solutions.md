# Solutions: Arrays

## Solution 1: Finding Array Length
**Answer:** The standard way to find the length of a C-style array is to divide the total size of the array in bytes by the size of a single element in bytes:
```cpp
size_t length = sizeof(my_array) / sizeof(my_array[0]);
// 68 bytes / 4 bytes = 17 elements.
```
*(Note: In C++17, you should prefer using `std::size(my_array)` from the `<iterator>` header, which safely does this for you).*

## Solution 2: Out of Bounds
**Answer:** The compiler will usually **not stop you** (though modern compilers with `-Wall` might issue a warning). The program will compile successfully. At runtime, the CPU will calculate the memory address of where the 6th element *would* be, and overwrite whatever happens to be in memory at that location with `99`. This is **Undefined Behavior** and is the root cause of countless security vulnerabilities and firmware crashes.

## Solution 3: Zero Initialization
**Answer:** 
- `buffer[0]` = `5`
- `buffer[1]` = `0`
- `buffer[99]` = `0`
**Why:** The syntax `{5}` initializes the *first* element to 5. The C/C++ standard dictates that if you provide an initializer list that is smaller than the array size, **all remaining elements are automatically initialized to zero**. You cannot initialize an entire C-style array to a non-zero value without a loop or `memset`.
