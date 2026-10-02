# Interview Questions: void Pointer

## 1. Why can't you dereference a `void*`?
**Answer:** Because a `void*` only holds a memory address, but it contains no type information. The compiler does not know how many bytes to read from that address, nor does it know how to interpret those bytes (e.g., as an integer, a float, or a struct). You must cast it to a concrete pointer type first.

## 2. Why do RTOS APIs like FreeRTOS `xTaskCreate` take a `void*` parameter for the task argument?
**Answer:** An RTOS kernel is pre-compiled and generic; it cannot know in advance what specific data structures the user application will need to pass to its tasks. By accepting a `void*`, the API allows the user to pass the address of absolutely anything (an integer, a configuration struct, etc.). The task function is then responsible for casting the `void*` back to the known type.

## 3. What is the difference between C and C++ regarding `void*` assignment?
**Answer:** In C, a `void*` can be implicitly assigned to any other pointer type (which is why `int* p = malloc(4);` works in C). In C++, implicit conversion *from* `void*` is forbidden to ensure type safety. You must explicitly cast the `void*` (using `static_cast`) before assigning it to a typed pointer.
