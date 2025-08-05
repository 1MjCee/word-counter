# Word Counter

A simple, fast, and reliable command-line utility written in C that counts words, lines, and characters in text files.

## Features

- **Multi-metric counting**: Words, lines, characters (with and without spaces)
- **Multiple file support**: Process single or multiple files in one command
- **Cross-platform**: Works on Linux, macOS, and Windows
- **Fast processing**: Efficient C implementation handles large files quickly
- **Error handling**: Graceful handling of missing or inaccessible files
- **Summary statistics**: Provides totals when processing multiple files

## Installation

### Prerequisites

- GCC compiler or compatible C compiler
- Make utility (optional, for easier building)

### Quick Install

```bash
# Clone or download the project
git clone <repository-url>
cd word_counter

# Build the program
make

# Test with sample file
make test

# Install system-wide (optional)
sudo make install
```

### Manual Build

If you don't have Make:

```bash
gcc -Wall -Wextra -std=c99 -O2 -o word_counter src/main.c
```

## Usage

### Basic Usage

```bash
# Count statistics for a single file
./word_counter filename.txt

# Process multiple files
./word_counter file1.txt file2.txt file3.txt

# Example output
=== File Statistics for 'sample.txt' ===
Lines:                    8
Words:                    45
Characters (with spaces): 234
Characters (no spaces):   189
=========================================
```

### Command Line Options

```bash
word_counter <filename>              # Single file
word_counter <file1> <file2> ...     # Multiple files
word_counter --help                  # Show usage information
```

## Examples

### Single File Processing

```bash
$ ./word_counter README.md
=== File Statistics for 'README.md' ===
Lines:                    127
Words:                    856
Characters (with spaces): 5432
Characters (no spaces):   4576
=========================================
```

### Multiple File Processing

```bash
$ ./word_counter *.txt
=== File Statistics for 'doc1.txt' ===
Lines:                    15
Words:                    120
Characters (with spaces): 645
Characters (no spaces):   525
=========================================

=== File Statistics for 'doc2.txt' ===
Lines:                    23
Words:                    189
Characters (with spaces): 987
Characters (no spaces):   798
=========================================

=== TOTAL STATISTICS ===
Files processed:          2
Total lines:              38
Total words:              309
Total characters (with):  1632
Total characters (no):    1323
========================
```

## Building from Source

### Using Make (Recommended)

```bash
# Standard build
make

# Debug build (with debugging symbols)
make debug

# Clean build files
make clean

# Create test files and run tests
make test

# Install to system PATH
sudo make install
```

### Build Targets

- `make` or `make all` - Build release version
- `make debug` - Build with debugging symbols
- `make clean` - Remove build artifacts
- `make test` - Build and run basic tests
- `make install` - Install to `/usr/local/bin`
- `make test-file` - Create sample test file

### Compiler Options

The default build uses these GCC flags:
- `-Wall -Wextra` - Enable comprehensive warnings
- `-std=c99` - Use C99 standard
- `-O2` - Optimize for performance

## Project Structure

```
word_counter/
├── src/
│   └── main.c          # Main source code
├── tests/
│   └── sample.txt      # Sample test file
├── Makefile           # Build configuration
├── README.md          # This file
└── .gitignore         # Git ignore rules
```

## Technical Details

### What Counts as a Word?

A word is defined as any sequence of non-whitespace characters. This means:
- `hello` = 1 word
- `don't` = 1 word  
- `123` = 1 word
- `user@example.com` = 1 word

### Character Counting

- **Characters (with spaces)**: All characters including spaces, tabs, newlines
- **Characters (no spaces)**: Only visible characters, excluding whitespace

### Line Counting

- Each `\n` character counts as a line break
- Files not ending with newline still count the final line

## Performance

The word counter is optimized for performance:
- **Memory efficient**: Uses minimal memory regardless of file size
- **Fast processing**: Can handle large files (100MB+) quickly
- **Low overhead**: Single-pass algorithm through each file

### Benchmark Results

On a typical modern system:
- **Small files** (< 1KB): < 1ms
- **Medium files** (1-10MB): 10-100ms  
- **Large files** (100MB+): 1-5 seconds

## Error Handling

The program gracefully handles various error conditions:

```bash
# File not found
$ ./word_counter nonexistent.txt
Error: Could not open file 'nonexistent.txt'

# No arguments provided
$ ./word_counter
Usage: ./word_counter <filename>
       ./word_counter <file1> <file2> ... <fileN>

Counts words, lines, and characters in text files.
```

## Contributing

### Code Style

- Follow C99 standard
- Use 4-space indentation
- Include comprehensive comments
- Maintain cross-platform compatibility

### Testing

Before submitting changes:

```bash
# Run basic tests
make test

# Test with various file types
./word_counter tests/*.txt

# Test edge cases
touch empty.txt
echo "   " > spaces.txt
./word_counter empty.txt spaces.txt
```

## License

This project is released under the MIT License. See LICENSE file for details.

## Changelog

### v1.0.0
- Initial release
- Basic word, line, and character counting
- Multiple file support
- Cross-platform compatibility

## Support

For issues, questions, or contributions:
- Create an issue on the project repository
- Check existing documentation
- Review the source code for implementation details

## Similar Tools

This word counter is similar to Unix `wc` command but with some differences:
- More detailed character counting (with/without spaces)
- Cleaner output format
- Better error messages
- Consistent behavior across platforms

## Future Enhancements

Potential features for future versions:
- Configuration file support
- JSON/CSV output formats
- Recursive directory processing
- Regular expression filtering
- Multi-threading for large file sets
- Unicode support improvements