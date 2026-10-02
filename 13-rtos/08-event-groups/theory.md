# Event Groups

## 1. The Multi-Condition Problem
Imagine a system that uploads GPS coordinates to AWS.
You have three Initialization tasks that run at boot:
1. `Init_WiFi()`
2. `Init_GPS()`
3. `Init_AWS_Crypto()`

You have a 4th task, `Main_App()`. It must wait until **all three** initialization tasks have successfully finished before it can start sending data. 
If `Main_App()` tries to use the AWS Crypto before the GPS is ready, the system will crash.

## 2. What is an Event Group?
An Event Group is essentially just a single 32-bit integer managed by the RTOS. 
Usually, 24 of those bits are available to the programmer. Each bit acts as an independent binary flag.
- Bit 0: WiFi Ready
- Bit 1: GPS Ready
- Bit 2: AWS Ready

## 3. Setting Flags (The Producers)
When `Init_WiFi()` finishes, it calls `xEventGroupSetBits()`, setting Bit 0 to `1`.
When `Init_GPS()` finishes, it sets Bit 1 to `1`.
When `Init_AWS_Crypto()` finishes, it sets Bit 2 to `1`.

## 4. Waiting on Flags (The Consumer)
The magic happens in `Main_App()`. It calls `xEventGroupWaitBits()`.
It tells the RTOS: *"Put me to sleep infinitely. Do not wake me up until Bit 0 AND Bit 1 AND Bit 2 are all set to 1."*
The RTOS puts `Main_App()` in the Blocked List. It consumes 0% CPU.
The exact nanosecond the final initialization task sets the 3rd bit, the RTOS evaluates the Event Group, sees the condition is met, and instantly wakes up `Main_App()`.

## 5. AND vs OR Logic
The `xEventGroupWaitBits()` function allows you to specify boolean logic:
- **Wait for ALL (AND):** Wake me up only if Bit 0 *AND* Bit 1 are set. (Useful for initialization).
- **Wait for ANY (OR):** Wake me up if Bit 0 *OR* Bit 1 is set. (Useful for a generic "Error Handler" task that wakes up if *any* subsystem flags an error bit).

## 6. Example
*(See `examples/` for FreeRTOS Event Group syntax).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
