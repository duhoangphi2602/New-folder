# Solutions: Struct Padding and Alignment

## Solution 1: Calculate the Size
**Answer:** The size is **12 bytes**.
**Memory Map:**
- `[0-1]`: `port` (2 bytes)
- `[2-3]`: **PADDING** (2 bytes) -> Injected so `ip_address` starts at an address divisible by 4.
- `[4-7]`: `ip_address` (4 bytes)
- `[8]`: `protocol` (1 byte)
- `[9-11]`: **PADDING** (3 bytes) -> Injected at the end so the total struct size is a multiple of its largest alignment requirement (4).

## Solution 2: End Padding
**Answer:** The size is **8 bytes**. 
It consists of 4 bytes for `timestamp`, 2 bytes for `value`, and 2 bytes of **end-padding**.
**Why:** The compiler must ensure that if this struct is placed in an array, *every single element* maintains correct alignment. If the size was 6 bytes, `buffer[0].timestamp` would be at offset `0` (Safe), but `buffer[1].timestamp` would be at offset `6`. `6` is not divisible by 4, so reading `buffer[1].timestamp` would cause an unaligned access fault. By padding the struct to 8 bytes, `buffer[1]` starts at offset `8`, which is safely divisible by 4.
