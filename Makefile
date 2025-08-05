CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O2
SRCDIR=src
SOURCES=$(SRCDIR)/main.c
TARGET=word_counter

# Default target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Debug version
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET).exe *.o

# Install to system (Unix-like systems)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Create test file
test-file:
	echo "This is a sample text file." > tests/sample.txt
	echo "It has multiple lines." >> tests/sample.txt
	echo "We can use it to test our word counter!" >> tests/sample.txt

# Run tests
test: $(TARGET) test-file
	./$(TARGET) tests/sample.txt

.PHONY: all debug clean install test-file test