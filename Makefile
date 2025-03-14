# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = $(wildcard src/*.cpp) $(wildcard test/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = chip8_emulator

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build executable target
build-exe: $(EXEC)

# Test target
test:
	for test_file in test/*; do ./$$test_file; done

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean build-exe test