# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source file
SOURCE = StringFunctions.c

# Object files
OBJECTS = $(SOURCE:.c=.o)

# Library name
LIBRARY = libstringlib.a

# Main target
all: $(LIBRARY)

# Compile source file into object file
$(OBJECTS): $(SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

# Clean up
clean:
	rm -f $(OBJECTS) $(LIBRARY)
