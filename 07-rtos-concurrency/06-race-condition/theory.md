# Race Conditions

## 1. Concept
A **Race Condition** occurs when two or more Tasks (or a Task and an ISR) attempt to access a shared piece of data at exactly the same time, and at least one of them is modifying the data. The final value of the data depends completely on the microscopic timing of the CPU Scheduler (which task "wins the race").

## 2. The Assembly Reality
To understand why it happens, you must understand that a simple C++ line like `counter++;` is **NOT one CPU instruction**. It is typically three Assembly instructions:
1. **LDR:** Load the value of `counter` from RAM into a CPU Register (e.g., `R0`).
2. **ADD:** Add 1 to `R0`.
3. **STR:** Store the value of `R0` back into the RAM address of `counter`.

## 3. The Anatomy of a Crash

Imagine `counter` is currently `10`.
Task A and Task B both execute `counter++;`.

**What you EXPECT (Value becomes 12):**
1. Task A Loads 10, Adds 1, Stores 11.
2. Task B Loads 11, Adds 1, Stores 12.

**What ACTUALLY HAPPENS (Value becomes 11!):**
1. Task A executes LDR (`R0 = 10`).
2. Task A executes ADD (`R0 = 11`).
3. **[SYSTICK INTERRUPT!]** The Scheduler pauses Task A before it can save!
4. Task B starts. It executes LDR. Because Task A never saved, RAM still holds `10`! Task B loads 10.
5. Task B executes ADD (`R0 = 11`).
6. Task B executes STR (RAM now holds `11`).
7. **[SYSTICK INTERRUPT!]** Task A resumes!
8. Task A resumes exactly where it left off. Its internal `R0` still holds `11`. It executes STR. RAM is overwritten with `11`.

One count was silently deleted from existence. If this counter tracks the number of bytes written to an SD card, your file system is now corrupted.

## 4. Example
*(See `examples/` for a C++ simulation of the exact Assembly sequence causing a Race Condition).*

## 5. Identifying the Danger Zone
Any operation that is not **Atomic** (indivisible) is susceptible to a Race Condition if shared between contexts.
- `x++` (Not atomic, 3 instructions).
- `flag = true` (Usually atomic on 32-bit CPUs if aligned).
- `my_struct.a = 5; my_struct.b = 10;` (Not atomic).

## 6. How to Fix It
To prevent Race Conditions, you must guarantee that the Scheduler cannot preempt the CPU while a task is modifying shared data. We use:
1. **Critical Sections** (Topic 07)
2. **Mutexes** (Topic 08)
3. **Hardware Atomics** (Topic 10)

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
