# Solutions: Semaphore

## Solution 1: The Missing Events
**Answer:** The 2nd and 3rd signals will be completely lost (dropped). 
A Binary Semaphore has a maximum count of 1. 
1. The 1st byte arrives, ISR gives the Semaphore. (Count = 1).
2. The 2nd byte arrives 5 microseconds later. ISR gives the Semaphore. Because the count is already 1, the signal is ignored. (Count = 1).
3. The 3rd byte arrives 5 microseconds later. ISR gives Semaphore. Ignored. (Count = 1).
When the Task finally wakes up, it will take the Semaphore (Count goes to 0) and process *one* byte. It will then go back to sleep, completely unaware that 2 other bytes arrived.

## Solution 2: Counting Solution
**Answer:** You must use a **Counting Semaphore** (e.g., initialized with a max count of 10). 
When the 1st byte arrives, the ISR increments the count to 1. The 2nd byte increments it to 2. The 3rd byte increments it to 3. 
When the Task wakes up, it Takes the Semaphore (Count drops to 2) and processes one byte. The Task then loops immediately, Takes the Semaphore again (Count drops to 1), and so on, until the Count reaches 0, at which point the Task goes back to sleep. No events are lost.
*(Note: In reality, modern RTOSs prefer using a Message Queue or Stream Buffer for UART data rather than pure Semaphores).*
