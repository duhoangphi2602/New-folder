# Packet Data Representation

## 1. Concept
A Binary Packet is a predefined sequence of bytes with a strict layout. 
For example, a drone telemetry packet might be exactly 9 bytes long:
- Byte 0: Start Byte (`0xAA`)
- Byte 1: Packet Type
- Bytes 2-5: Altitude (32-bit integer, Big Endian)
- Bytes 6-7: Checksum (16-bit integer)
- Byte 8: End Byte (`0x55`)

## 2. Why
Sending data this way is incredibly efficient. A 9-byte packet takes just 72 microseconds to transmit over a standard 115200 baud UART connection. Sending the same data as JSON (`{"type":1,"alt":15000}`) could take 30+ bytes and requires heavy string parsing on the receiver.

## 3. The Two Approaches to Parsing

### Approach 1: The Struct Overlay (Fast but Dangerous)
You define a struct with `__attribute__((packed))`, receive the raw bytes, and cast a pointer to the struct.
```cpp
struct __attribute__((packed)) DronePacket {
    uint8_t start_byte;
    uint8_t type;
    uint32_t altitude;
    uint16_t checksum;
    uint8_t end_byte;
};

// Receiving a raw byte array
uint8_t raw_buffer[9] = {0xAA, 0x01, /*...*/};

// DANGEROUS: Struct overlay!
DronePacket* pkt = reinterpret_cast<DronePacket*>(raw_buffer);
```
**Why it is dangerous:**
1. **Alignment Faults:** If `raw_buffer` is not aligned to a 4-byte boundary, `pkt->altitude` will trigger a Hard Fault on an ARM Cortex-M0.
2. **Endianness Bugs:** If the sender is Big Endian and the receiver is Little Endian, `pkt->altitude` will be backwards. The struct overlay assumes the host and network share the same Endianness.

### Approach 2: Manual Serialization (The Industry Standard)
Instead of forcing the compiler to overlay a struct, you manually extract the bytes using bit-masks and bit-shifts. This is 100% portable, alignment-safe, and Endian-safe.

```cpp
// 1. We receive a raw buffer (Assume Network is Big Endian)
uint8_t raw_buffer[9] = {0xAA, 0x01, 0x00, 0x00, 0x3A, 0x98, 0x12, 0x34, 0x55};

// 2. We extract the 32-bit altitude safely
// We take Byte 2, shift it up to the MSB, take Byte 3, shift it...
uint32_t altitude = (raw_buffer[2] << 24) |
                    (raw_buffer[3] << 16) |
                    (raw_buffer[4] << 8)  |
                    (raw_buffer[5] << 0);
// Result: 0x00003A98 (15000)
```
Even though this looks like more code, modern C++ compilers (GCC/Clang) recognize this specific bit-shifting pattern and optimize it into a single hardware `LDR` (Load Register) instruction with automatic byte-reversal. It costs zero extra CPU cycles.

## 4. Example
*(See `examples/` for a full runnable simulation of a Drone Telemetry transmission and reception).*

## 5. Embedded usage (Checksums)
Real-world packets always include a Checksum or CRC (Cyclic Redundancy Check) to detect if the wire corrupted any bits. The receiver calculates the checksum of the incoming data and compares it to the checksum sent in the packet. If they don't match, the packet is thrown away.

## 6. Trade-offs

| Method | Speed to Write Code | Portability & Safety | CPU Performance |
|--------|---------------------|----------------------|-----------------|
| **Struct Overlay (Packed)** | Very Fast | Poor (Endian & Alignment risks) | Good |
| **Manual Bit-Shifting** | Slower (Verbose) | **Perfect (Bulletproof)** | **Excellent (Compiler optimized)** |

**Rule of Professional Embedded C++:** Always use Manual Bit-Shifting for parsing network packets. Never use packed struct overlays for cross-platform data.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
