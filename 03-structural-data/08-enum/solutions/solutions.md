# Solutions: C-Style Enums

## Solution 1: Finding the Value
**Answer:**
- `PIN_LOW`: **0** (Starts at 0 by default).
- `PIN_HIGH`: **1** (Increments from the previous value).
- `PIN_PULLUP`: **6** (Increments from the manually set `PIN_FLOATING = 5`).
- `PIN_PULLDOWN`: **7**

## Solution 2: The Name Prefix Hack
**Answer:** In C and C++ (with legacy enums), the constant names defined inside an enum "leak" into the surrounding scope (e.g., the global namespace). If the I2C driver defines `enum { IDLE, BUSY };` and the SPI driver defines `enum { IDLE, BUSY };`, the compiler will see two global constants named `IDLE` and throw a **Redefinition Error**. 
To fix this, C developers are forced to manually prefix every single enum value with the name of the module (e.g., `I2C_STATE_...`) to ensure global uniqueness.
