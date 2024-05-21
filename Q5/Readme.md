
```markdown
# Max Subarray Sum Algorithms

This project demonstrates three different algorithms to find the maximum subarray sum in an array of integers. The algorithms have different time complexities: O(n), O(n^2), and O(n^3). The project also includes a comparison of their runtimes using `gprof`.

## Files
- `main.cpp`: The main file which generates random arrays and runs the algorithms.
- `MaxSub_alg.hpp`: Header file for the `MaxSubArray` class.
- `MaxSub_alg.cpp`: Implementation file for the `MaxSubArray` class.
- `Makefile`: Makefile to compile and run the project using `clang++`.

## Algorithms
### 1. O(n) - Kadane's Algorithm
This algorithm scans the array from left to right, keeping track of the maximum sum found so far. It has a linear time complexity of O(n).

### 2. O(n^2) - Double Loop Algorithm
This algorithm uses two nested loops to consider all possible subarrays and find the one with the maximum sum. It has a quadratic time complexity of O(n^2).

### 3. O(n^3) - Brute Force Algorithm
This algorithm uses three nested loops to consider all possible subarrays and compute their sums. It has a cubic time complexity of O(n^3).

## Compilation and Execution
### Requirements
- `clang++` compiler
- `make` build tool
- `gprof` for profiling

### Compilation
To compile the project, run:
```sh
make
```

### Execution
To run the project with a random seed of 42 and input size:
```sh
./maxsub seed size
```

This will generate random arrays of the specified sizes and run all three algorithms on the array, printing the runtime for each algorithm.

### Profiling with gprof
After running the program, you can profile it using `gprof`. First, make sure the program was compiled with profiling enabled (`-pg` flag):
```sh
make clean
make
```

Then run the program:
```sh
./maxsub seed size
```

After the run, generate the profiling report:
```sh
gprof max_subarray gmon.out > analysis.txt
```

## Example Output
### Runtime Example
```
Input array: ...
Time to generate random array: 300 microseconds
Max sub array sum (O(n)): ...
Time for O(n) algorithm: 50 microseconds
Max sub array sum (O(n^2)): ...
Time for O(n^2) algorithm: 4000 microseconds
Max sub array sum (O(n^3)): ...
Time for O(n^3) algorithm: 1200000 microseconds
```

### gprof Output Example
```
Flat profile:

Each sample counts as 0.01 seconds.
 no time accumulated

  %   cumulative   self              self     total
 time   seconds   seconds    calls   Ts/call  Ts/call  name
  0.00      0.00     0.00                             generateRandomArray(int, int)
  0.00      0.00     0.00                             MaxSubArray::maxSubArraySumON(std::vector<int, std::allocator<int> > const&)
  0.00      0.00     0.00                             MaxSubArray::maxSubArraySumON2(std::vector<int, std::allocator<int> > const&)
  0.00      0.00     0.00                             MaxSubArray::maxSubArraySumON3(std::vector<int, std::allocator<int> > const&)
```

## Conclusion
This project demonstrates the differences in runtime between three algorithms for finding the maximum subarray sum. By using `gprof`, we can analyze the performance and understand the time complexity impacts on large inputs.

Feel free to explore the code and modify the input sizes and random seeds to see how the algorithms perform under different conditions.

![Runtime of 100 Example](images/maxsub_run_100.png)
![Runtime of 1000 Example](images/maxsub_run_1000.png)
![Runtime of 10000 Example](images/maxsub_run_10000.png)

```
