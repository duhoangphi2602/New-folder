# Interview Questions: Pointer Arithmetic

## 1. What happens when you add `1` to a pointer?
**Answer:** The memory address stored in the pointer increases by the `sizeof` the type it points to. For example, adding `1` to a `uint32_t*` increases the physical address by 4 bytes. This ensures the pointer lands perfectly on the next sequential element in memory.

## 2. If you subtract two pointers of the same type, what does the result represent?
**Answer:** It represents the **number of elements** between the two pointers, not the physical number of bytes. The compiler automatically divides the byte difference by the `sizeof(type)`. (The resulting type is `ptrdiff_t`).

## 3. Can you perform pointer arithmetic on a `void*`?
**Answer:** No, not in strict standard C++. Pointer arithmetic requires knowing the size of the underlying type to scale the addition/subtraction. Since `void` represents an incomplete type with no size, the compiler cannot perform the math. You must cast the `void*` to a `uint8_t*` or `char*` first.

## 4. Under the hood, how does the compiler interpret the array syntax `arr[3]`?
**Answer:** The compiler translates it exactly into pointer arithmetic: `*(arr + 3)`. It takes the base address of the array, adds 3 (scaled by the size of the array's type), and dereferences the resulting address.
