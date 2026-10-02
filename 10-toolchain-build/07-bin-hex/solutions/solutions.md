# Solutions: Bin and Hex

## Solution 1: The Bootloader Size Limit
**Answer:** The `.hex` file is much larger because it is a plain text file representing binary data using ASCII characters. To represent a single byte of data like `0xFF`, the `.hex` file uses two ASCII characters ('F' and 'F'), doubling the size immediately. It also adds significant overhead per line (colons, addresses, record types, checksums, newlines). 
You should transmit the **`.bin`** file. It is the raw, compressed payload with zero overhead, saving 60% of your cellular data costs. The bootloader running on the device already knows what physical Flash address to start writing the incoming data to, making the address information in the `.hex` file redundant anyway.

## Solution 2: The Giant Gap
**Answer:** 
- **The `.bin` file:** It will be roughly **1 Megabyte** (1048 KB). A raw binary file has no concept of addresses. To place data at `0x08000000` and `0x08100000` in the same file, `objcopy` is forced to literally pad the gap with 1,024,000 bytes of zeros (or `0xFF`) so the second bank of data is physically located 1MB deep into the file.
- **The `.hex` file:** It will be roughly **50 KB**. Intel Hex handles gaps perfectly. It simply writes the records for Bank 1, issues an "Extended Linear Address Record" jumping the address pointer to `0x0810`, and then writes the records for Bank 2. There is zero padding. In this specific scenario with large memory gaps, `.hex` is vastly superior.
