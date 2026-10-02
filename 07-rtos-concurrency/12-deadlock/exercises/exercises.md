# Exercises: Deadlock

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Watchdog Timer
A junior developer is warned about Deadlocks. They say: *"It's fine. If my two tasks deadlock, the Hardware Watchdog Timer will detect that the system is frozen and automatically reboot the microcontroller."*
**Task:** Why might the developer be wrong? Under what specific conditions would a classic 2-task Deadlock completely fail to trigger the hardware Watchdog Timer?

## Exercise 2: C++11 std::lock
**Task:** Read the C++11 documentation for `std::lock(m1, m2)`. How does it internally avoid deadlocks when asked to lock multiple mutexes simultaneously? Which of the 4 Coffman Conditions is it breaking?
