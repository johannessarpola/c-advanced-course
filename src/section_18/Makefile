# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source file
SOURCE = static_lib.c

# Object files
OBJECTS = $(SOURCE:.c=.o)

# Library name
LIBRARY = static_lib.a

EXECUTABLE = main.out
MAIN_SOURCE = static_lib_user.c

# Main target
all: $(LIBRARY) $(EXECUTABLE)

# Compile source file into object file
$(OBJECTS): $(SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

# Clean up
clean:
	rm -f $(OBJECTS) $(LIBRARY)

# Phony target to avoid conflicts with file named "clean"
.PHONY: clean

# gcc -L looks in directory for library files. -> -L. (working dir)
$(EXECUTABLE): $(MAIN_SOURCE) $(LIBRARY)
	$(CC) $(CFLAGS) $< -o $@ -L. -l:$(LIBRARY)