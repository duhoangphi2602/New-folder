# Static Storage Duration

## 1. Concept
"Storage Duration" defines how long a variable lives in RAM.
- **Automatic (Stack):** Lives only while the function is running.
- **Dynamic (Heap):** Lives until you explicitly `delete` it.
- **Static:** Lives for the *entire lifetime of the program*. It is allocated when the system boots, and it is never destroyed until the power is turned off.

## 2. Why
Static Storage is 100% deterministic. The compiler calculates exactly how much static memory is required before the code is even flashed to the chip. If you use too much RAM, the compiler will refuse to build the code. This completely eliminates runtime Out-Of-Memory crashes and Heap Fragmentation.

## 3. The `static` Keyword (Two Different Meanings)

The `static` keyword is notoriously confusing because it does two completely different things depending on where you put it.

### Meaning 1: Memory Lifetime (Inside a function)
If you place `static` inside a function, the variable is moved off the Stack and into Static Storage. It retains its value between function calls.
```cpp
void count_calls() {
    static int count = 0; // Initialized ONLY ONCE at boot!
    count++;
    printf("Called %d times\n", count);
}
```

### Meaning 2: Linker Visibility (Outside a function / Global)
By default, global variables are visible to every single `.cpp` file in your project (using the `extern` keyword). If you place `static` on a global variable, you **hide** it. It becomes "Private" to that specific `.cpp` file.
```cpp
// main.cpp
static int secret_key = 1234; // Other files CANNOT see this variable!
```

## 4. Example
*(See `examples/` for runnable code demonstrating function state retention).*

## 5. Embedded usage (The Memory Pool)
To avoid the Heap, embedded systems often pre-allocate a massive static array (a Memory Pool) and manually divide it up during runtime.

```cpp
// A 10KB Static Array. 
// The compiler guarantees this RAM is reserved for the entire life of the firmware.
static uint8_t global_network_buffer[10240];

void process_network() {
    // We use the global buffer instead of calling malloc() or using a massive Stack array!
    receive_data(global_network_buffer);
}
```

## 6. Trade-offs (RAM Bloat vs Safety)
- **Safety:** Static memory is perfectly safe. You can't leak it, and it can't fragment.
- **RAM Bloat:** If you allocate a 10KB static buffer for an SD card driver, but the user never inserts an SD card, that 10KB of RAM is permanently wasted. You cannot reclaim it to use for the network driver. (This is why the Heap was invented in the first place, but we sacrifice that flexibility for embedded safety).

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
