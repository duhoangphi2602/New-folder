# Solutions: The ISR Buffer Pattern

## Solution 1: The Queue Overload
**Answer:** The RTOS will collapse under the overhead. 
`xQueueSendFromISR` is a complex OS function. It disables interrupts, copies data, updates linked lists, checks if Tasks need to be woken, and restores interrupts. Executing this massive OS function 44,100 times per second will consume nearly 100% of the CPU's processing power. The SysTick timer will be constantly preempted, and the UI Task will receive 0% of the CPU. RTOS Queues must NEVER be used for high-frequency data streams.

## Solution 2: DMA (Direct Memory Access)
**Answer:** DMA (Direct Memory Access). 
DMA is a dedicated hardware chip that sits next to the CPU. You configure the DMA by giving it a pointer to the ADC hardware register, and a pointer to a large `std::array` in RAM. When the ADC has data, the DMA hardware physically moves the byte from the ADC directly into the RAM array in 0 CPU cycles. The CPU is completely asleep or doing math while this happens. The DMA is configured to trigger a single ISR only when the *entire array* (e.g., 1024 samples) is full. This reduces 1024 interrupts down to just 1 interrupt, freeing up 99% of the CPU.
