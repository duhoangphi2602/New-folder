# Interview Questions: Bit-Fields

## 1. What is a bit-field in C/C++?
**Answer:** A bit-field is a struct member that allows the developer to specify the exact number of bits the variable will occupy in memory. It is used to pack multiple boolean flags or small integers into a single byte or word to save RAM.

## 2. Are bit-fields safe for mapping hardware registers? Why or why not?
**Answer:** No, they are not safe. The C and C++ standards state that the ordering of bit-fields within a storage unit is implementation-defined. The compiler is free to pack the bits from LSB to MSB, or from MSB to LSB. Mapping hardware requires 100% deterministic bit placement, which bit-fields cannot guarantee across different compilers.

## 3. What happens if you define a signed bit-field, like `int flag : 1;`, and assign `1` to it?
**Answer:** This causes a dangerous sign-extension bug. A 1-bit signed integer has only one bit for the value *and* the sign. 
If you assign `1` (binary `1`), that bit is treated as the sign bit. In two's complement, a sign bit of `1` means the number is negative. So reading `flag` will evaluate to `-1`, not `1`. Bit-fields should almost always be `unsigned`.
