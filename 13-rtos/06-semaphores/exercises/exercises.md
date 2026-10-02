# Exercises: Semaphores

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Broken Lock
A developer wants to protect access to a shared SPI bus. Instead of creating a Mutex, they create a Binary Semaphore initialized to `1` (Available).
```cpp
xSemaphoreTake(spi_binary_sem, portMAX_DELAY); // Take lock
spi_transmit(data);
xSemaphoreGive(spi_binary_sem);                // Give lock
```
Task A takes the lock. While Task A is transmitting, a massive software bug causes Task B to randomly call `xSemaphoreGive(spi_binary_sem)`.
**Task:** In FreeRTOS, what will happen if Task B gives a Mutex that it doesn't own? What will happen if Task B gives a Binary Semaphore it doesn't own? Explain why Mutexes are safer for this scenario.

## Exercise 2: Losing Events
You use a Binary Semaphore to sync a button press (ISR) to a Task.
If the user presses the button, the ISR calls `Give`. The Task wakes up, takes it, and processes the press.
What if the Task takes 500ms to process a button press? During that 500ms, the user presses the button rapidly 3 more times. The ISR fires 3 times and calls `Give` 3 times.
**Task:** When the Task finishes its 500ms job and loops back to `xSemaphoreTake`, how many "Gives" will the RTOS have stored? Will the Task process all 3 presses, or were they lost? How does a Counting Semaphore fix this?
