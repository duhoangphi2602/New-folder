# Example Makefile

# Variables
CXX = arm-none-eabi-g++
CFLAGS = -Wall -Werror -O2 -mcpu=cortex-m4 -mthumb
LDFLAGS = -T linker_script.ld

# The Final Target (The Executable)
# It depends on main.o and sensor.o. 
# If either .o file changes, run the Linker command.
firmware.elf: main.o sensor.o
	$(CXX) $(LDFLAGS) main.o sensor.o -o firmware.elf

# Stage 2: Compile main.cpp into main.o
# Depends on main.cpp. If main.cpp is modified, run the Compiler.
main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp -o main.o

# Stage 2: Compile sensor.cpp into sensor.o
sensor.o: sensor.cpp
	$(CXX) $(CFLAGS) -c sensor.cpp -o sensor.o

# A Phony target to clean up the build folder
.PHONY: clean
clean:
	rm -f *.o *.elf
