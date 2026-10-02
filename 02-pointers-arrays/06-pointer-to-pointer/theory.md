# Pointer to Pointer

## 1. Concept
A pointer is just a variable that lives in memory. Therefore, it has its own memory address. A **pointer to a pointer** is a variable that stores the memory address of a standard pointer.

## 2. Why
When you pass a variable to a function in C/C++, it is passed by value (a copy is made).
- If you want a function to modify an `int`, you pass a pointer to the `int` (`int*`).
- If you want a function to modify a *pointer itself* (e.g., change what the pointer is pointing to), you must pass a pointer to the pointer (`int**`).

## 3. Syntax (Multiple Indirection)

```cpp
int value = 42;
int* ptr1 = &value;       // Pointer to int
int** ptr2 = &ptr1;       // Pointer to (pointer to int)

// Dereferencing
int copy1 = *ptr1;        // 42
int* copy2 = *ptr2;       // The address of 'value'
int copy3 = **ptr2;       // 42 (Double dereference)
```

## 4. Example
*(See `examples/` for runnable code demonstrating memory allocation via double pointers).*

## 5. Embedded usage (RTOS and HAL APIs)
While C++ provides a cleaner alternative (Pointer Reference), C does not. Therefore, embedded C libraries use double pointers constantly for object creation and buffer allocation.

**Example: FreeRTOS Task Creation**
```c
// FreeRTOS Task Handle is actually a pointer under the hood:
// typedef void* TaskHandle_t;

TaskHandle_t my_task; 

// The API needs to write a new memory address into 'my_task'.
// So, we must pass the address of our pointer (&my_task).
xTaskCreate(TaskFunc, "Name", 128, NULL, 1, &my_task); 
```

## 6. Trade-offs (Double Pointer vs Pointer Reference)

| Paradigm | `int** ptr_to_ptr` (C-style) | `int*& ptr_ref` (C++ style) |
|----------|------------------------------|-----------------------------|
| **Syntax overhead** | Requires `&` at call site, and `*` inside function. | Clean. No extra symbols required. |
| **Null Safety** | The double pointer itself can be `nullptr`. | References cannot be null (inherently safer). |
| **Compatibility** | Mandatory for C APIs and RTOS. | Modern C++ only. Cannot be used in C. |

## 7. Exercises
Please proceed to the `exercises/` folder to practice pointer modification.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
