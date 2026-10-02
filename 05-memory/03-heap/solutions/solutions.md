# Solutions: The Heap

## Solution 1: `malloc` vs `new`
**Answer:** `new` automatically calls the object's **Constructor**, and `delete` automatically calls the object's **Destructor**. `malloc` is just a dumb memory allocator; it gives you raw, uninitialized RAM. If you use `malloc` to allocate a C++ class, its constructor will never fire, and the object will be fundamentally broken. (You must never mix `malloc` with `delete`, or `new` with `free`).

## Solution 2: Fragmentation Visualization
**Answer:** You have **4 total bytes** of free RAM. 
If you call `malloc(5)`, it will **fail** (return `NULL` or throw `std::bad_alloc`).
**Why:** Even though there are 4 bytes free, they are sandwiched tightly between Pointer A (at the bottom) and Pointer C (at the top). `malloc` requires a *contiguous* (unbroken) block of memory. Because the largest contiguous free hole is only 4 bytes, asking for 5 bytes causes the allocator to fail, despite the Heap not being totally full. This is the definition of Heap Fragmentation.
