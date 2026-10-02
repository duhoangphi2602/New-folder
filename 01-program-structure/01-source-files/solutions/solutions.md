# Solutions: Source Files

## Solution 1: Include Guard Conversion
**Modern Syntax:**
```c
#pragma once

void display_init(void);
void display_print(const char* msg);
```
**Benefit:** `#pragma once` is simpler, prevents typo-related bugs (e.g., `#define DISPLA_H`), and allows the compiler to completely skip the file if it sees it again, speeding up compile times slightly.

## Solution 2: The Multiple Definition Bug
**Why it fails:** The compilation model treats each `.cpp` file as an independent translation unit. When `main.cpp` and `uart.cpp` include `config.h`, the preprocessor copies `int system_timeout = 1000;` into both files. The compiler generates two separate object files, both containing a definition for `system_timeout`. The linker then complains because it doesn't know which one to use.

**The Fix:**
In `config.h` (Declaration only):
```cpp
#pragma once
extern int system_timeout; 
```
In *one* source file, e.g., `config.cpp` (Definition):
```cpp
#include "config.h"
int system_timeout = 1000;
```

## Solution 3: C/C++ Interoperability
**The Fix:** You must wrap the C declarations in an `extern "C"` block so the C++ compiler doesn't mangle the function names.

```c
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void spi_init(void);

#ifdef __cplusplus
}
#endif
```
