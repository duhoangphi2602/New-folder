# Tests

This directory contains tests for the practical projects and examples in the repository.

## Structure

| Directory | Purpose |
|-----------|---------|
| `unit/` | Unit tests for individual modules (ring buffer, state machine, etc.) |
| `integration/` | Integration tests (ISR + task communication, etc.) |
| `compile-tests/` | Compile-time tests using `static_assert` |

## Running Tests

```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```
