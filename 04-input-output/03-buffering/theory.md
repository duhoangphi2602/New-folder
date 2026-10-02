# Buffering in I/O

## 1. Concept
A buffer is a block of RAM. When you call `printf` or `std::cout`, the standard library does not immediately talk to the hardware (UART, Screen, Disk). Instead, it copies your string into the buffer. Once the buffer hits a specific trigger condition, it **"flushes"**—meaning it dumps the entire block of RAM to the hardware in one massive, highly efficient transaction.

## 2. Why
Efficiency. 
Imagine mailing a book to a friend. 
- **Unbuffered:** You put 1 page in an envelope, drive to the post office, mail it, and repeat 500 times.
- **Buffered:** You put all 500 pages in a box and drive to the post office once.

## 3. The Three Types of Buffering

1. **Unbuffered:** Every character is sent to hardware instantly. (Used by `stderr` / `std::cerr` so error messages are never delayed).
2. **Line Buffered:** Characters are stored in RAM until a newline `\n` is encountered. Once `\n` hits, the whole line flushes. (Default for `stdout` / `printf` when connected to a terminal).
3. **Fully Buffered:** Characters are stored in RAM until the buffer is physically full (e.g., 4096 bytes). (Default when writing to a File or Disk).

## 4. Example
*(See `examples/` for runnable code demonstrating how to manually control buffering).*

## 5. Embedded usage (The Silent Crash)
The most common beginner bug in embedded systems:
```cpp
void execute_critical_task() {
    printf("Starting task..."); // Line-Buffered! NO NEWLINE!
    
    // The CPU crashes here (e.g., divide by zero, hard fault)
    crash_system(); 
    
    printf("Task finished\n");
}
```
**What happens?** The developer looks at the serial terminal and sees *nothing*. They assume `execute_critical_task()` was never called!
**Why?** The string `"Starting task..."` was written to the RAM buffer. Because there was no `\n`, the buffer did not flush. The system crashed, RAM was wiped, and the message never reached the UART hardware.

**The Fix:**
Always include `\n`, or manually flush!
```cpp
printf("Starting task...\n"); // The \n triggers the flush. Safe!
// OR
printf("Starting task...");
fflush(stdout); // Manually forces the buffer to dump to hardware immediately.
```

## 6. Trade-offs (Performance vs Safety)
- **Frequent Flushing (`fflush` or `std::endl`):** Safest for debugging. If a crash happens, you are guaranteed to see the last log message. However, it completely destroys performance inside fast loops (e.g., logging motor speeds at 1000Hz).
- **Relying on Buffer:** Highest performance, but risks losing critical clues if the system crashes unexpectedly.

*In professional systems, standard logs are buffered, but fatal error handlers (Asserts, Hard Faults) instantly switch to an unbuffered UART polling mode to guarantee the dying words of the CPU make it to the screen.*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
