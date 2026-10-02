# Solutions: Semaphores

## Solution 1: The Broken Lock
**Answer:** 
- **Mutex:** FreeRTOS Mutexes strictly enforce "Ownership". If Task A took the Mutex, the RTOS kernel records Task A as the owner. If Task B tries to call `Give` on it, the RTOS will instantly block the action, return an error, and the lock remains secure.
- **Binary Semaphore:** Semaphores have *no ownership*. If Task B randomly calls `Give`, the OS accepts it and sets the Semaphore back to 1! If Task C is waiting for the SPI bus, the OS will instantly wake Task C up and give it the lock. Now Task A and Task C are using the SPI bus simultaneously, causing a fatal data collision. This is why Semaphores should strictly be used for *signaling*, and Mutexes for *protection*.

## Solution 2: Losing Events
**Answer:** A Binary Semaphore can only hold a value of `0` or `1`. 
When the first rapid button press happens, the ISR calls `Give`, setting the semaphore to `1`. When the second and third presses happen, the ISR calls `Give` again, but the semaphore is *already* at `1`. The subsequent Gives are completely ignored and lost forever. When the Task finally loops back, it will only process exactly 1 button press.
**The Fix:** A **Counting Semaphore** is essentially an integer counter. If initialized with a max count of 10, the first Give makes it 1, the second makes it 2, the third makes it 3. When the Task loops back, it can successfully `Take` the semaphore 3 separate times before going back to sleep, perfectly processing all 3 buffered events.
