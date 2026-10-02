# Bit-Field vs Bit-Mask

## 1. Concept
- **Bit-Field**: A language feature (`uint8_t flag : 1;`) where the compiler generates the bitwise logic for you.
- **Bit-Mask**: Manual bitwise math (`REG |= (1 << 3);`) where the developer explicitly defines the shifting and masking.

## 2. Why
Bit-Fields are completely at the mercy of the compiler's packing rules (MSB-first vs LSB-first). Bit-Masks are dictated purely by mathematics. `(1 << 3)` is guaranteed by the C++ Standard to shift the bit left mathematically, regardless of how the CPU physically stores the byte in hardware. Bit-Masks are **100% portable**.

## 3. Syntax (The Four Fundamental Operations)

Assume `REG` is an 8-bit hardware register.

### 1. Set a Bit (Use OR `|`)
To turn bit 5 ON (leave others unchanged):
```cpp
REG |= (1 << 5); 
```

### 2. Clear a Bit (Use AND `&` with NOT `~`)
To turn bit 5 OFF (leave others unchanged):
```cpp
REG &= ~(1 << 5); 
```

### 3. Toggle a Bit (Use XOR `^`)
To flip bit 5 (0 becomes 1, 1 becomes 0):
```cpp
REG ^= (1 << 5); 
```

### 4. Read a Bit (Use AND `&`)
To check if bit 5 is 1:
```cpp
if (REG & (1 << 5)) { ... }
```

## 4. Example
*(See `examples/` for runnable code demonstrating multi-bit masking).*

## 5. Embedded usage (Multi-Bit Masks)
What if you need to configure a 3-bit "Mode" spanning bits 4, 5, and 6?

```cpp
// A register where bits 4,5,6 control the prescaler (values 0-7)
uint32_t CONTROL_REG = 0; 

// Step 1: Define the mask (3 bits of 1s shifted to position 4)
// Binary 111 is Hex 0x7
const uint32_t PRESCALER_MASK = (0x7 << 4); 

// Step 2: Clear the old value using the inverted mask
CONTROL_REG &= ~PRESCALER_MASK; 

// Step 3: Insert the new value (e.g., Mode 5)
uint32_t new_mode = 5; // Binary 101
CONTROL_REG |= (new_mode << 4); 
```

## 6. Trade-offs

| Feature | Bit-Field (`struct`) | Bit-Mask (`&`, `|`) |
|---------|----------------------|---------------------|
| **Readability** | Excellent (`reg.mode = 5`) | Poor / Verbose (`reg = (reg & ~M) \| (5 << 4)`) |
| **Portability** | Terrible (Compiler dependent) | **Perfect** (Math dependent) |
| **Atomicity** | Can cause hidden read-modify-write issues | Often maps directly to atomic hardware instructions (like ARM bit-banding) |

**Conclusion**: In standard application code that never leaves the current CPU, Bit-Fields are fine. For memory-mapped registers, network protocols, or cross-platform libraries, you **must** use Bit-Masks.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
