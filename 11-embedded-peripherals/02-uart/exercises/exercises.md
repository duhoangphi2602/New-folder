# Exercises: UART

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Infinite Hang
You write a simple logging function to send debugging messages to your PC:
```cpp
void log_message(const char* msg) {
    while(*msg != '\0') {
        // Wait until the Transmit Data Register is Empty (TXE flag is 1)
        while ((UART1->SR & TXE_FLAG) == 0) { } 
        
        // Write the next character to the data register
        UART1->DR = *msg;
        msg++;
    }
}
```
You test it with `log_message("Init");` and it works perfectly.
Then, you deploy the device to the field, but you accidentally **unplug the TX wire** so it's not connected to the PC anymore.
**Task:** Will the microcontroller crash, hang infinitely, or continue working normally? Explain exactly how the hardware `TXE` flag behaves when the wire is disconnected.

## Exercise 2: The Baud Rate Math
You want to transmit a massive 1 Megabyte (1,048,576 bytes) firmware update file over UART using a baud rate of `115200 8-N-1`.
**Task:** Mathematically calculate exactly how many seconds it will take to transmit the entire file. (Hint: Remember that UART requires a Start bit and a Stop bit for every byte sent).
