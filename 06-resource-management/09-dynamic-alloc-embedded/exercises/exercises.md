# Exercises: Safe Dynamic Allocation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Wi-Fi Disconnect Bug
An IoT coffee machine connects to a cloud server to download JSON recipes. When it connects, it dynamically allocates a 2KB buffer. When the JSON is processed, it frees the buffer.
A bug is reported: If the user unplugs their Wi-Fi router while the machine is downloading the JSON, the coffee machine permanently locks up and stops responding to buttons.
**Task:** Using your knowledge of dynamic allocation failure modes, what architectural mistake likely caused this bug, and how does Modern C++ (Smart Pointers) solve it?

## Exercise 2: Static vs Allocate-Once
**Task:** What is the functional difference between using a `std::array` (Static Allocation) versus using the "Allocate Once, Run Forever" dynamic pattern? Why would a company choose the dynamic pattern for their firmware?
