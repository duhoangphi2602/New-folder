# Interview Questions: Nested Structs

## 1. When a struct is nested inside another struct, is it stored as a pointer/reference or is the data physically embedded?
**Answer:** In C/C++, it is physically embedded in-line. The entire memory block of the inner struct is placed contiguously directly inside the memory block of the outer struct. (This is different from languages like Java or Python, where an inner object would just be a reference/pointer to heap memory).

## 2. What determines the alignment requirement of a nested struct?
**Answer:** The alignment requirement of any struct (including a nested one) is strictly determined by the alignment requirement of its largest scalar member. For example, if an inner struct contains three `uint8_t` variables and one `double` (8 bytes), the entire inner struct has an alignment requirement of 8 bytes. The outer struct must inject padding before the inner struct to ensure it lands on an 8-byte boundary.

## 3. Why is composition (nesting structs) preferred over creating a single massive struct?
**Answer:** Composition allows for modularity and code reuse. If you define a `Vector3D` struct, you can write generic mathematical functions that operate on `Vector3D` objects. You can then embed `Vector3D` inside an `Accelerometer` struct, a `Gyroscope` struct, and a `Gps` struct, and reuse those exact same mathematical functions without rewriting code.
