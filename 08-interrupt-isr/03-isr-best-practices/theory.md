# ISR Best Practices

## 1. The 3 Golden Rules of ISRs
Whenever you write an ISR, it must adhere to these three strict rules:
1. **Short:** Execute as few assembly instructions as physically possible.
2. **Fast:** Never wait, never block, never loop indefinitely.
3. **Non-Blocking OS APIs:** Never call an OS function that can put a task to sleep (like taking a Mutex or a standard Queue Read).

## 2. The Danger of "printf"
Beginners often try to debug an interrupt like this:
```cpp
void UART_ISR() {
    uint8_t byte = UART->DATA_REGISTER;
    printf("Received byte: %c\n", byte); // CATASTROPHIC MISTAKE
}
```
`printf` is a massive, slow function. It formats strings, allocates memory, and blocks the CPU until the text is fully sent over a debug cable (which can take 10 milliseconds). 
If your ISR takes 10ms to run, you are physically blinding the CPU to all other hardware events for 10ms. If a motor control interrupt needs to fire every 1ms, it will be blocked, and the motor will crash.
**Rule:** Never use `printf`, `malloc`, `new`, or `delay_ms` inside an ISR.

## 3. The Danger of Mutexes
As covered in Topic 08, an ISR is a hardware context, not an RTOS Task. It has no Task Control Block. If you attempt to take a Mutex inside an ISR, the RTOS will attempt to put the "current task" to sleep. But there is no task running! The system will suffer a Hard Fault memory violation and reboot.
**Rule:** Never use a Mutex in an ISR. If you must share data, use `std::atomic`, a Critical Section (in the Task, not the ISR), or an RTOS Lock-Free Queue.

## 4. The Professional Pattern (Deferral)
If an ISR receives a 1000-byte JSON packet over UART, it should *not* parse the JSON. Parsing JSON takes millions of CPU cycles. 
Instead, you must use the **Deferred Interrupt Pattern**:
1. ISR triggers.
2. ISR copies the 1000 bytes into a global RAM buffer.
3. ISR "Gives" a Binary Semaphore to wake up a "Parsing Task".
4. ISR exits immediately (total time: 2 microseconds).
5. The RTOS Scheduler takes over, wakes up the Parsing Task, and the Task parses the JSON at a normal software priority level.

## 5. Clearing the Hardware Flag
When a hardware peripheral triggers an interrupt, it sets a specific bit in a status register (e.g., `RX_DATA_READY = 1`). 
If your ISR finishes and exits, but you forgot to write code to clear that bit back to 0, the NVIC will instantly think a *new* interrupt has occurred. It will immediately re-enter the ISR. Your CPU will be permanently trapped in an infinite loop of entering and exiting the ISR, freezing the main program.
**Rule:** The very first (or last) thing every ISR must do is explicitly clear the hardware pending flag.

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
