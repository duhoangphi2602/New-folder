# Interview Questions: Union

## 1. What is the difference between a `struct` and a `union` regarding memory allocation?
**Answer:** In a `struct`, every member has its own distinct, non-overlapping memory location, and the total size is the sum of all members (plus padding). In a `union`, all members share the exact same starting memory address. The total size of the union is dictated solely by its largest member.

## 2. What happens if you write to one member of a union and read from another?
**Answer:** Because all members share the same memory, writing to one member overwrites the data of the others. Reading from a different member than the one you just wrote to is called "Type Punning". It reinterprets the raw binary bits as the new type. While this is legal in C, it is explicitly Undefined Behavior in the C++ standard.

## 3. If Type Punning via a union is Undefined Behavior in C++, how should you convert a byte array into a float?
**Answer:** The strictly standard C++ way to reinterpret memory bits is to use `std::memcpy` (or `std::bit_cast` in C++20). The compiler recognizes `std::memcpy` as a built-in intrinsic and optimizes it completely, generating safe, zero-overhead assembly code without invoking Undefined Behavior.
