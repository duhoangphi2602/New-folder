# Exercises: Queues

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The String Pointer Bug
A junior developer writes a task to read UART characters, build a string, and send the string to a Parser task via a Queue.
They create a queue designed to hold Character Pointers: `xQueueCreate(10, sizeof(char*));`
```cpp
void vTaskUart(void *pvParams) {
    char local_buffer[100]; // Array in the local task stack
    while(1) {
        read_uart_string(local_buffer);
        
        char* ptr_to_buffer = local_buffer;
        xQueueSendToBack(string_queue, &ptr_to_buffer, portMAX_DELAY);
    }
}
```
**Task:** When the Parser task receives the pointer and tries to print the string, it often prints absolute garbage, or strings from previous UART messages mixed together. Explain exactly why passing a pointer to `local_buffer` causes this massive data corruption. 

## Exercise 2: Queue Sizing
You have a high-priority hardware interrupt (ISR) that receives exactly 1 byte from an I2C sensor every 5 milliseconds. The ISR pushes this byte onto a queue.
A low-priority `Task_Process` wakes up, reads the byte, processes it, and goes back to sleep.
Under heavy system load, `Task_Process` might be preempted and prevented from running for up to 50 milliseconds!
**Task:** What is the absolute minimum depth (number of items) you must configure the Queue to hold to guarantee you NEVER lose a byte of data during that 50ms period?
