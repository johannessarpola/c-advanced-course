# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source file
SOURCE = mylib.c

# Object files
OBJECTS = $(SOURCE:.c=.o)

# Library name
LIBRARY_NAME = mylib
LIBRARY = lib$(LIBRARY_NAME).a

EXECUTABLE = main.out
MAIN_SOURCE = lib_user_main.c

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
	rm -f $(OBJECTS) $(LIBRARY) $(EXECUTABLE)

# Phony target to avoid conflicts with file named "clean"
.PHONY: clean

# gcc -L looks in directory for library files. -> -L. (working dir)
$(EXECUTABLE): $(MAIN_SOURCE) $(LIBRARY)
	$(CC) $(CFLAGS) $< -o $@ -L. -l$(LIBRARY_NAME)