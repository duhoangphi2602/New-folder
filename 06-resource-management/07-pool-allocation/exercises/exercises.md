# Exercises: Pool Allocation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Fragmentation Defense
A developer tries to create a custom memory pool that supports requesting *variable* sizes (e.g., `pool.allocate(10)`, then `pool.allocate(500)`). 
**Task:** Why does allowing variable sizes completely defeat the primary architectural purpose of a Memory Pool?

## Exercise 2: Out of Memory Recovery
In a standard Desktop application, if `malloc` fails, the program usually crashes or aborts. 
In an RTOS using a Memory Pool for UART RX packets, the pool might be empty if the CPU is too busy to process the incoming packets fast enough. 
**Task:** When an RTOS task tries to allocate a block from an empty pool, it doesn't crash. What does the RTOS task typically do while it waits for a block to become available?
