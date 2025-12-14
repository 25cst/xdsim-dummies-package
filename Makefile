# Compiler
CC = gcc

# Compiler flags
CFLAGS = -fPIC -Wall

# Shared object files
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
SHARED_LIBS = $(SOURCES:.c=.so)

# Default target
all: $(SHARED_LIBS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create shared objects from object files
%.so: %.o
	$(CC) -shared -o $@ $<

# Clean up
clean:
	rm -f $(OBJECTS) $(SHARED_LIBS)
