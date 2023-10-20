# File Copy in C

## Overview

This C program copies the contents from a source file to a destination file using low level file I/O operations.

## Usage

```
./filecpy source_file destination_file
```

- source_file: Path to source file to copy from
- destination_file: Path to destination file to copy to

## How it works

- The program takes two command line arguments - source and destination file paths
- It opens both files using `open()`
- It reads from source file in chunks into a buffer using `read()`
- It writes the buffer chunks to the destination file using `write()`
- This repeats in a loop until read returns 0 bytes (end of file)
- Finally it closes both files using `close()`

## Key functions

- `open()` - Opens file and returns file descriptor
- `read()` - Reads data from file into buffer
- `write()` - Writes buffer data to file
- `close()` - Closes open file

## Error handling

- Checks argc to ensure correct number of arguments passed
- Checks return value of open() to ensure files opened successfully
- Prints error messages for any failures

## Compilation

```bash
gcc filecpy.c -o filecpy
```

## Author

[Omar Elhorbity](https://www.linkedin.com/in/omar-elhorbity/)