# Solutions: Bit-Field vs Bit-Mask

## Solution 1: Single Bit Operations
**Answers:**
1. Clear bit 3: `STATUS &= ~(1 << 3);`
2. Set bit 0: `STATUS |= (1 << 0);`
3. Toggle bit 7: `STATUS ^= (1 << 7);`

## Solution 2: The Macro Way
**Answer:** The value of `REG` will be **16** (or **0x10** in Hex).
**Why:** `(1 << 4)` means shifting the binary number `1` to the left by 4 positions.
- Starting: `0000 0001` (1)
- Shift 4: `0001 0000` (16 in decimal, 0x10 in hex).
Executing `REG |= 16` on an empty register sets it to `16`.
