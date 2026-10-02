# Solutions: Pointer to Struct

## Solution 1: The Dot Precedence Trap
**Answer:** In C/C++, the dot operator (`.`) has higher precedence than the dereference operator (`*`). The compiler evaluates `m_ptr.speed` first. Because `m_ptr` is a pointer (not a struct), it doesn't have a `.speed` member, causing a compile error. 
**The Fixes:**
1. Force precedence with parentheses: `(*m_ptr).speed = 100;`
2. Use the arrow operator (the correct, readable way): `m_ptr->speed = 100;`

## Solution 2: Hardware Modeling
**Answer:**
```cpp
// 1. Define the struct
struct I2C_RegDef {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
};

// 2. Map the pointer
auto* const I2C_1 = reinterpret_cast<I2C_RegDef*>(0x40005400);
// (Or C-style: #define I2C_1 ((I2C_RegDef*)0x40005400) )

void init_i2c() {
    // 3. Write via the arrow operator
    I2C_1->CR1 = 0x01;
}
```
