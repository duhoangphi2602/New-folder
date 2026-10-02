# Solutions: RTC

## Solution 1: The BCD Trap
**Answer:** The alarm will actually fire at exactly **18 seconds**. 
In C++, writing `uint8_t seconds = 30;` stores the standard binary representation of 30, which is `0001 1110` (or `0x1E` in Hex).
When you push `0x1E` into the RTC's BCD register, the RTC hardware interprets it using BCD rules (where each 4-bit nibble is a decimal digit).
- The upper nibble is `1`. (Tens place = 10).
- The lower nibble is `E` (14). (Units place = 14. *Wait, BCD digits can only be 0-9. This is technically an invalid BCD state, but some hardware will lazily evaluate it as 10 + 8 = 18*).
Ultimately, it does not mean 30. You must convert Decimal to BCD before writing to the register!
`Decimal 30 -> Tens = 3, Units = 0 -> BCD = 0011 0000 -> 0x30`.

## Solution 2: UNIX Time vs RTC Registers
**Answer:** The primary advantage is **Absolute Global Synchronization (and Timezones)**.
A UNIX timestamp (e.g., `1696118400`) represents the exact same moment in time everywhere on planet Earth. Cloud servers operate entirely on UNIX time. If an IoT device uploads a sensor reading tagged with `1696118400`, the server knows exactly when it happened.
If the device relies on local BCD calendar registers (e.g., "Oct 1, 2:00 PM"), the cloud server has no idea what Timezone the device is in, whether Daylight Savings Time (DST) is active, or if the device was shipped to another country. Using a flat 32-bit counter for UNIX time makes the embedded device universally compatible with web servers and prevents nightmare bugs involving leap years and DST shifting.
