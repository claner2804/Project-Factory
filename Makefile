# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Name of the executable
EXECUTABLE = factory

# Source files
SOURCES = MachineA.cpp MachineB.cpp ProductB.cpp main.cpp Machine.cpp ProductA.cpp Product.cpp Factory.cpp

# Header files
HEADERS = Exception.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXECUTABLE)

# Rule to link the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Rule to compile source files
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the directory
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)