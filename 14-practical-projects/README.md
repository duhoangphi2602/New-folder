# 13 — Practical Projects

These projects integrate knowledge from all previous chapters. Each project combines multiple concepts (pointers, structs, bit manipulation, RAII, C++17 features, ISR patterns) into a cohesive, working example.

## Projects

| # | Project | Key Concepts |
|---|---------|-------------|
| 01 | [GPIO Register](./01-gpio-register/) | Pointers, bit manipulation, class |
| 02 | [UART Driver](./02-uart-driver/) | C driver, ISR simulation |
| 03 | [Sensor Driver](./03-sensor-driver/) | C driver + C++ wrapper + `std::optional` |
| 04 | [Packet Parser](./04-packet-parser/) | Struct, serialization, endianness |
| 05 | [Ring Buffer](./05-ring-buffer/) | Template, `std::array`, static allocation |
| 06 | [ISR-Task Communication](./06-isr-task-communication/) | ISR → Ring Buffer → Task |
| 07 | [Producer-Consumer](./07-producer-consumer/) | Mutex, semaphore, queue |
| 08 | [C Driver → C++ Wrapper](./08-c-driver-cpp-wrapper/) | `extern "C"`, RAII, `std::optional` |
| 09 | [RAII Resource Manager](./09-raii-resource-manager/) | Constructor/destructor, lock guard |
| 10 | [C++17 State Machine](./10-cpp17-state-machine/) | `std::variant`, `std::visit`, lambda |
| 11 | [Mini Embedded System](./11-mini-embedded-system/) | ALL concepts integrated |

## Project 11: Mini Embedded System

The capstone project integrates:
- C driver + C++ wrapper
- C++17 types (`optional`, `variant`, `string_view`)
- Static buffers (`std::array`)
- Ring buffer (template)
- Volatile register abstraction
- ISR simulation + atomic state
- Mutex/semaphore synchronization
- RTOS-like task model
- HAL/Driver/App layered architecture
- CMake build system
- Unit tests
