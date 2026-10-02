# Common Utilities

This directory contains shared utilities used across the code examples in this repository.

To keep examples focused on the learning topic rather than boilerplate, we provide:
1. `common/types.h`: Explicit size integer aliases if `<cstdint>` is not used directly.
2. `common/assert.h`: A simple assertion macro for examples.
3. `common/log.h`: A simple logging utility for demonstrating state.

## Integration
In the CMake build system, this is an `INTERFACE` or `STATIC` library that other examples link against.
