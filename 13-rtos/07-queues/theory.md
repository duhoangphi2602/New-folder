# Queues

## 1. The Producer / Consumer Model
The most common RTOS architecture is the Producer/Consumer model.
- **Producer Task:** Reads data from a hardware sensor (e.g., an I2C ADC) every 10ms. 
- **Consumer Task:** Takes the data, formats it into a JSON string, and sends it over WiFi to AWS. (Takes 500ms).

Because the Consumer is so slow, if they shared a global variable, the Producer would overwrite the global variable 50 times before the Consumer could finish uploading the first one. Data is lost.

## 2. The RTOS Queue
A Queue solves this by acting as a buffered conveyor belt. 
You configure a Queue to hold, for example, 10 items.
- The Producer pushes item 1 onto the back of the belt. Then item 2. Then item 3.
- The Consumer takes item 1 off the front of the belt. (FIFO - First In, First Out).

**The Magic of Blocking:**
- If the Queue is EMPTY, and the Consumer tries to read from it, the OS puts the Consumer to sleep (`Blocked`) until the Producer pushes new data.
- If the Queue is FULL (10 items), and the Producer tries to push item 11, the OS puts the Producer to sleep until the Consumer reads an item and makes room.
The OS completely automates the flow of data!

## 3. Pass-by-Copy
In FreeRTOS, queues pass data by **Copy**. 
If you push an `int x = 42` onto a queue, the RTOS physically copies the bytes `42` into the Queue's private RAM buffer. You can immediately delete or change your local variable `x`, and the queue's data remains perfectly safe.

## 4. Pass-by-Reference (Pointers)
What if you need to send a massive 1 Megabyte Image Array from a Camera Task to a SD Card Task?
Passing it by copy would take millions of CPU cycles and instantly crash the RAM.
Instead, you push a **Pointer** to the image onto the queue. The Queue only copies 4 bytes (the memory address). The Consumer receives the 4-byte pointer and can instantly access the 1MB image in RAM.
*(Warning: The Producer MUST NOT modify the image array in RAM until it is absolutely sure the Consumer is finished reading it, otherwise a Race Condition occurs!).*

## 5. Example
*(See `examples/` for FreeRTOS Queue syntax passing a C-Struct).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
