# Pointer Arithmetic

## 1. Concept
Pointer arithmetic allows you to add integers to (or subtract integers from) a pointer to navigate through contiguous memory blocks, such as arrays.

## 2. Why
Array indexing (e.g., `buffer[i]`) is conceptually easy, but under the hood, the C/C++ compiler translates it directly into pointer arithmetic. Understanding pointer arithmetic allows you to write highly optimized loops for processing data streams in bare-metal systems, often bypassing the overhead of array index bounds checking.

## 3. Syntax (The Scaling Rule)
**CRITICAL RULE:** When you add `1` to a pointer, the physical memory address does NOT just increase by 1 byte. It increases by `1 * sizeof(pointer_type)`. The compiler automatically scales the math based on the data type.

```cpp
uint32_t buffer[4] = {10, 20, 30, 40}; // Assume buffer is at address 0x1000
uint32_t* ptr = buffer; // ptr holds 0x1000

ptr = ptr + 1; 
// 1 * sizeof(uint32_t) = 4 bytes.
// Address changes from 0x1000 to 0x1004. ptr now points to 20.

ptr++; 
// Increments pointer again. Now points to 0x1008 (30).
```

### Pointer Subtraction
You can subtract two pointers of the *same type*. The result is the **number of elements** between them, NOT the number of bytes!
```cpp
uint32_t* p1 = &buffer[0];
uint32_t* p3 = &buffer[3];

ptrdiff_t diff = p3 - p1; 
// diff is 3 (elements), not 12 (bytes).
```

## 4. Example
*(See `examples/` for runnable code demonstrating parsing a buffer using pointer arithmetic).*

## 5. Embedded usage (Buffer Parsing)
Pointer arithmetic is heavily used in ISRs (Interrupt Service Routines) to parse incoming byte streams (e.g., UART protocols or network packets).

```cpp
void parse_packet(const uint8_t* payload, size_t length) {
    const uint8_t* current = payload;
    const uint8_t* end = payload + length;
    
    // Efficiently walk through the memory block
    while (current < end) {
        process_byte(*current);
        current++; // advance 1 byte (since type is uint8_t)
    }
}
```

## 6. Trade-offs

| Method | Pros | Cons |
|--------|------|------|
| **Array Indexing `arr[i]`** | Very readable. Clear intent. | Can be slightly slower if the compiler has to re-calculate the base address + offset on every loop iteration. |
| **Pointer Arithmetic `*ptr++`** | The most optimized way to traverse contiguous memory. Translates directly to CPU instructions (e.g., ARM `LDR r0, [r1], #4`). | Extremely prone to Out-of-Bounds memory corruption bugs. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice scaling math.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
