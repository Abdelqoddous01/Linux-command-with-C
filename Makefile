# Makefile for compiling a C program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source file
SRC = cp2.c

# Output executable
EXE = cp2

# Default target
all: $(EXE)

# Rule to build the executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean rule
clean:
	rm -f $(EXE)
