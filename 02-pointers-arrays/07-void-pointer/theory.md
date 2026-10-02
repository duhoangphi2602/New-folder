# void Pointer

## 1. Concept
A `void*` (void pointer) holds a memory address just like any other pointer, but it lacks **type information**. The compiler knows *where* the data is, but it does not know *what* the data is or how large it is.

## 2. Why
Without `void*`, writing a generic function like `memcpy` (which copies raw bytes from source to destination) would be impossible in C. You would need to write `memcpy_int`, `memcpy_float`, `memcpy_struct`, etc. `void*` allows one function to accept any pointer type.

## 3. Syntax (Restrictions and Casting)
Because a `void*` has no type information, there are two strict rules:
1. **You cannot dereference it.** (The compiler doesn't know how many bytes to read).
2. **You cannot perform pointer arithmetic on it.** (The compiler doesn't know the `sizeof` the type to scale the addition).

To use the data, you **must cast it** back to a specific pointer type.
```cpp
int value = 42;
void* v_ptr = &value;  // Any pointer implicitly converts to void*

// *v_ptr = 100;       // COMPILE ERROR: Cannot dereference void*
// v_ptr++;            // COMPILE ERROR: Cannot do arithmetic on void*

// Cast back to int* before dereferencing
int* i_ptr = static_cast<int*>(v_ptr); // C++ style cast
*i_ptr = 100;                          // OK
```

## 4. Example
*(See `examples/` for runnable code demonstrating a custom memory print function using `void*`).*

## 5. Embedded usage (RTOS Task Parameters)
The most common and critical use of `void*` in embedded systems is passing arguments to threads or RTOS tasks. The RTOS kernel is pre-compiled and doesn't know what custom data struct you want to pass to your task, so the API demands a `void*`.

```c
// Example: FreeRTOS task signature
void SensorTask(void* pvParameters) {
    // 1. Cast the generic pointer back to the expected type
    ConfigStruct* config = static_cast<ConfigStruct*>(pvParameters);
    
    while(1) {
        read_sensor(config->sensor_id);
    }
}

int main() {
    static ConfigStruct my_config = { .sensor_id = 1 };
    
    // 2. Pass the address of the struct as a void*
    xTaskCreate(SensorTask, "Sensor", 128, &my_config, 1, NULL);
}
```

## 6. Trade-offs (C vs C++)
In **C**, `void*` is implicitly converted to any other pointer type. This makes `malloc()` easy to use, but destroys type safety.
```c
// OK in C
int* p = malloc(sizeof(int)); 
```
In **C++**, implicit conversion *from* `void*` is illegal. You MUST explicitly cast it. This catches many accidental pointer assignment bugs.
```cpp
// Required in C++ (though you should be using 'new' anyway)
int* p = static_cast<int*>(malloc(sizeof(int))); 
```

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
