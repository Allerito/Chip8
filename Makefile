# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = $(wildcard src/*.c) $(wildcard test/*.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = chip8_emulator

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
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
