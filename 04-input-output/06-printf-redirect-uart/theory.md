# Printf Redirection to UART

## 1. Concept
When you call `printf`, the C Standard Library formats the string in RAM. It then calls a low-level system function (a "syscall") to output that RAM buffer to the hardware. 
In the GNU ARM GCC toolchain (Newlib), this syscall is named `_write`. The standard library provides a **weak** implementation of `_write` that simply discards the data. Your job is to write a **strong** implementation of `_write` in your own code to override the default one.

## 2. Why
This architecture separates formatting from hardware. The C library handles the complex `%d` and `%f` string formatting, and you handle the simple task of sending a raw array of characters to the UART register.

## 3. Syntax (Overriding `_write`)

To redirect `printf` on an ARM GCC compiler, you must define this exact function signature:
```c
// Usually defined in an external 'syscalls.c' file
int _write(int file, char *ptr, int len) {
    // 1. Loop through the characters in the buffer
    for (int i = 0; i < len; i++) {
        // 2. Call YOUR hardware-specific UART function
        uart_send_char(ptr[i]);
    }
    // 3. Return the number of characters written
    return len;
}
```

## 4. Example
*(See `examples/` for runnable code demonstrating standard library hooking).*

## 5. Embedded usage (The `\n` vs `\r\n` Problem)
On a Linux PC, a newline (`\n`) simply moves the cursor down to the next line.
In ancient hardware teletypes (and modern Serial Terminals like PuTTY), moving to the next line requires two distinct commands:
1. `\r` (Carriage Return): Move the cursor to the far left of the screen.
2. `\n` (Line Feed): Move the cursor down one line.

If you don't send `\r`, your terminal output will look like this:
```
Starting system...
                  System initialized!
                                     Waiting for input...
```
Therefore, your `_write` function must intercept `\n` and inject a `\r` right before it.
```c
int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        // The fix: Inject Carriage Return before Line Feed
        if (ptr[i] == '\n') {
            uart_send_char('\r');
        }
        uart_send_char(ptr[i]);
    }
    return len;
}
```

## 6. Trade-offs (Interrupts and Blocking)
Because `printf` relies on your `uart_send_char` function, the performance of `printf` is entirely dictated by your UART driver. If your UART driver uses a blocking `while` loop (Polling), then calling `printf` will freeze your entire CPU until all characters are transmitted!
For example, printing 100 characters at 9600 baud will freeze the CPU for 100 milliseconds. In a drone flight controller, a 100ms freeze will cause the drone to crash. 

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
