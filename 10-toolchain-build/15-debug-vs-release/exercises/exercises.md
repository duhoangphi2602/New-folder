# Exercises: Debug vs Release

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Disappearing Function Call
A junior developer writes this code to initialize an I2C sensor:
```cpp
bool init_i2c() {
    // Hardware initialization logic here
    return true;
}

int main() {
    assert(init_i2c() == true);
    while(1) { 
        read_sensor();
    }
}
```
The code works flawlessly for 3 months during testing. The developer changes the IDE dropdown from "Debug" to "Release", builds the firmware, and flashes 10,000 devices.
Every single device instantly crashes on boot. 
**Task:** Explain exactly what happened. What specific Compiler Flag caused the crash, and how did it alter the C++ logic?

## Exercise 2: Stepping Through Chaos
You are hunting a bug. The code is currently compiled with the Release profile (`-Os`). You connect your J-Link debugger and set a breakpoint. 
When the breakpoint hits, the yellow line highlights line 50. You click "Step Over". The highlight jumps to line 22, then to line 85, then says "Variable optimized out" when you hover over a counter.
**Task:** Why is the debugger behaving so erratically? How do you fix the build configuration to make debugging possible?
