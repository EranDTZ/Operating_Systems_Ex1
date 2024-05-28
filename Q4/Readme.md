
---

# Dijkstra's Algorithm Implementation

## Overview

This project implements Dijkstra's algorithm to find the shortest path in a graph. The program reads the graph's adjacency matrix from the user and computes the shortest paths from a source vertex to all other vertices.

## Files

- `dijkstra.cpp`: Implementation of Dijkstra's algorithm.
- `dijkstra.hpp`: Header file for the Dijkstra class.
- `main.cpp`: Contains the `main` function to run the program.
- `Makefile`: Makefile to compile and run the program, and perform additional checks like code coverage and memory leak detection.

## Compilation and Execution

### Prerequisites

Ensure you have `clang++` and `gcov` installed on your system.

### Steps

1. **Compile the Program:**
   ```sh
   make
   ```

2. **Run the Program:**
   ```sh
   ./main
   ```

3. **Clean the Build Files:**
   ```sh
   make clean
   ```

## Usage

1. The program will prompt you to enter the number of vertices in the graph.
2. Next, it will prompt you to enter the adjacency matrix for the graph.

Example input for a graph with 9 vertices:
```
Enter the number of vertices in the graph: 9
Enter the adjacency matrix of the graph:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
```

The program will then output the shortest distances from the source vertex (vertex 0) to all other vertices.

## Memory Leak Detection

To check for memory leaks using `valgrind`, run:
```sh
make valgrind
```

## Code Coverage

To check code coverage using `gcov`, follow these steps:

1. **Run the Program:**
   ```sh
   ./main
   ```

2. **Generate the Coverage Report:**
   ```sh
   gcov dijkstra.cpp
   ```

   The output will show the percentage of lines executed in each file.

## Error Handling

The program includes basic error handling for invalid inputs such as:

- Non-numeric input for the number of vertices.
- Invalid values in the adjacency matrix.
- Adjacency matrix with incorrect dimensions.

## Example Output

```
Enter the number of vertices in the graph: 9
Enter the adjacency matrix of the graph:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

Vertex           Distance from Source
0                               0
1                               4
2                               12
3                               19
4                               21
5                               11
6                               9
7                               8
8                               14
```


---