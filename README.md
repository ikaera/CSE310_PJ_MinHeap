# CSE310_PJ_MinHeap

## Project Description
This C++ project implements a min-heap data structure with all core operations. The program reads input data, processes heap operations through user commands, and outputs results to both console and files.

## Key Features
- Complete min-heap implementation
- Support for all fundamental heap operations:
  - BuildHeap (linear time)
  - Insert
  - ExtractMin
  - DecreaseKey
- Dynamic memory management
- Input/output file handling

## File Structure
```
Project/
├── data_structures.h - Defines ELEMENT and HEAP structures
├── heap.h           - Heap function declarations
├── heap.cpp         - Heap function implementations
├── main.h           - Main program header
├── main.cpp         - Main program logic
├── util.h           - Utility functions header
├── util.cpp         - Utility functions
└── Makefile         - Build configuration
```

## How to Build and Run
1. Compile the project:
   ```bash
   make clean && make
   ```

2. Execute the program:
   ```bash
   ./PJ2 <input-file> <output-file>
   ```

## Input File Format
The input file should contain:
1. An integer n (number of elements)
2. n floating-point numbers (element keys)

Example:
```
5
12.5
8.2
15.0
3.7
9.1
```

## Available Commands
| Command                 | Description                          | Example                     |
|-------------------------|--------------------------------------|-----------------------------|
| Read                    | Load data from input file           | Read                        |
| PrintArray              | Display element array               | PrintArray                  |
| PrintHeap               | Show current heap state             | PrintHeap                   |
| BuildHeap               | Construct heap from array           | BuildHeap                   |
| Insert <index>          | Add element to heap                 | Insert 3                    |
| ExtractMin              | Remove minimum element              | ExtractMin                  |
| DecreaseKey <i> <key>   | Reduce an element's key             | DecreaseKey 2 5.0           |
| Write                   | Save results to output file         | Write                       |
| Stop                    | Exit program                        | Stop                        |

## Output Examples
1. PrintArray output:
   ```
   1 12.500000 0
   2 8.200000 2
   3 15.000000 0
   4 3.700000 1
   5 9.100000 3
   ```

2. PrintHeap output:
   ```
   Capacity = 5, size = 3
   H[1] = 4
   H[2] = 2
   H[3] = 5
   ```

3. DecreaseKey confirmation:
   ```
   Key of V[2] decreased to 5.000000
   ```

## Technical Details
- Implemented in standard C++ (C++11 compatible)
- Requires g++ compiler
- Tested on Linux environment
- Proper memory management (alloc/free)
- O(n) BuildHeap implementation
- O(log n) for Insert/ExtractMin operations

## Testing
The implementation handles:
- Empty heap cases
- Invalid commands
- Out-of-bound indices
- Key validation
- File I/O errors
