# Bare-Metal Programming

## 1. Concept (The Super Loop)
In bare-metal programming, there is no Operating System scheduler. Your software is the OS. 
The architecture consists of two parts:
1. **Interrupt Service Routines (ISRs):** Hardware events that pause the main program instantly.
2. **The Super Loop:** An infinite `while(1)` loop inside `main()` that continuously checks flags and calls processing functions in a strict sequential order.

## 2. The Naive Approach (Blocking Code)
Beginners often write bare-metal code using blocking functions.
```cpp
void main() {
    while(1) {
        turn_on_led();
        delay_ms(1000);   // DEAD TIME: The CPU sits in a useless loop for 1 second!
        turn_off_led();
        delay_ms(1000);   // DEAD TIME
        read_sensor();    // The sensor is only read every 2 seconds!
    }
}
```
If the user presses a button during the `delay_ms(1000)`, the system will completely ignore it (unless the button is wired to an Interrupt). This architecture does not scale beyond a simple blinking LED.

## 3. The Professional Approach (Non-Blocking State Machines)
To build a complex bare-metal system, **you are never allowed to use `delay_ms()`**.
Instead, you must use hardware Timers to check how much time has passed. The Super Loop must run as fast as possible (e.g., looping 100,000 times per second). Every function inside the loop must do a quick check, execute instantly if needed, and immediately return.

```cpp
void main() {
    while(1) {
        process_led_blinking(); // Checks a timer. Instantly returns if not time to blink.
        process_sensor();       // Checks a flag. Instantly returns if no data.
        process_network();      // Checks RX buffer. Instantly returns if empty.
    }
}
```

## 4. Example
*(See `examples/` for a simulation of a blocking loop vs a non-blocking Super Loop).*

## 5. When the Super Loop Breaks Down (The Breaking Point)
The Super Loop architecture fails when you have **Asymmetric Workloads**. 
Suppose `process_network()` needs to cryptographically decrypt a TLS packet, taking 200 milliseconds. During those 200ms, the CPU is trapped inside `process_network()`. 
Because it's trapped, `process_sensor()` is not called. If the sensor generates data every 10ms, you will lose 20 sensor readings while the network packet is decrypting.
When you reach this point—where long calculations block critical fast tasks—you have outgrown Bare-Metal and must upgrade to an RTOS.

## 6. Trade-offs
- **Pros:** Extremely simple to debug (code always executes linearly). Zero RAM wasted on multiple Stacks. Zero ROM wasted on a Scheduler.
- **Cons:** A long function blocks the entire system. Very difficult to manage complex networking stacks or heavy math concurrently with strict timing requirements.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
