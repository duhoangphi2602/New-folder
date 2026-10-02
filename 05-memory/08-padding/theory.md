# Memory Padding

## 1. Concept
Padding is the insertion of unused bytes by the compiler into data structures. The compiler does this silently and automatically to ensure that every individual member of the struct satisfies its Natural Alignment requirements.

## 2. Why
If the compiler didn't inject padding, variables would be unaligned. When the CPU tried to read them, it would trigger a hardware Hard Fault and crash. Padding trades a small amount of wasted RAM for guaranteed execution safety and maximum memory read speed.

## 3. Syntax (How the compiler calculates it)

```cpp
struct BadLayout {
    char a;      // 1 byte. (Address 0)
    // Compiler injects 3 bytes of padding here! (Addresses 1, 2, 3)
    int b;       // 4 bytes. Must start at Address 4.
    char c;      // 1 byte. (Address 8)
    // Compiler injects 3 bytes of trailing padding here!
};
// Total size: 12 bytes! (Even though the variables only sum to 6 bytes).
```

### Trailing Padding
Why did the compiler add padding at the *end* of the struct? 
Because of Arrays. If you make an array `BadLayout arr[2];`, `arr[1]` will be placed immediately after `arr[0]`. If `arr[0]` was only 9 bytes long, `arr[1].a` would start at address 9, and `arr[1].b` would start at address 10 (which is NOT divisible by 4, causing a crash). 
To prevent this, the compiler pads the *total size of the struct* so that it is a perfect multiple of the struct's largest member. (In this case, a multiple of 4. So 9 bytes is padded up to 12 bytes).

## 4. Example
*(See `examples/` for a runnable demonstration of `sizeof` proving the existence of padding).*

## 5. Embedded usage (Optimizing Layouts)
In embedded systems, wasting RAM is a sin. You can completely eliminate internal padding by simply ordering your struct members from **Largest to Smallest**.

```cpp
struct GoodLayout {
    int b;       // 4 bytes. (Address 0)
    char a;      // 1 byte. (Address 4)
    char c;      // 1 byte. (Address 5)
    // Compiler injects 2 bytes of trailing padding.
};
// Total size: 8 bytes! (We saved 4 bytes of RAM just by reordering).
```
If you have an array of 1,000 of these structs, you just saved 4,000 bytes (4 Kilobytes) of precious SRAM, which is often 10% of a microcontroller's entire memory!

## 6. Trade-offs (Packed Structs)
You can force the compiler to remove ALL padding using `__attribute__((packed))` in GCC.
```cpp
struct __attribute__((packed)) PackedLayout {
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
}; // Total size: 6 bytes!
```
**The Trade-off:** While this saves maximum RAM and is required for mapping network packets, it forces `b` to sit at an unaligned address (Address 1). When the CPU tries to read `b`, the compiler must generate 4 separate 1-byte read instructions and shift them together in software, which is massively slower and bloats your `.text` (Flash) segment with extra assembly instructions. Use packed structs only when absolutely necessary for serialization.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
