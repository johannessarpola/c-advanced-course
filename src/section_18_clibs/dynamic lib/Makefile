# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source files
LIB_SOURCE = mylib.c
MAIN_SOURCE = main.c

# Object files
LIB_OBJECTS = $(LIB_SOURCE:.c=.o)

# Library name
LIBRARY = libmylib.so

# Executable name
EXECUTABLE = main

# Main target
all: $(LIBRARY) $(EXECUTABLE)

# Compile library source file into object file
$(LIB_OBJECTS): $(LIB_SOURCE)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Create shared library
$(LIBRARY): $(LIB_OBJECTS)
	$(CC) -shared -o $(LIBRARY) $(LIB_OBJECTS)

# Compile main source file into object file and link with the library
$(EXECUTABLE): $(MAIN_SOURCE) $(LIBRARY)
	$(CC) $(CFLAGS) $< -o $@ -L. -lmylib

$(EXECUTABLE)-fat: $(MAIN_SOURCE) $(LIBRARY)
	$(CC) $(CFLAGS) $< -o $@ -L. -lmylib -Wl,-rpath=.
# Clean up
clean:
	rm -f $(LIB_OBJECTS) $(LIBRARY) $(EXECUTABLE) $(EXECUTABLE)-fat 

# Phony target to avoid conflicts with file named "clean"
.PHONY: clean
