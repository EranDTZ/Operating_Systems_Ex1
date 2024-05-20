#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "MaxSub_alg.hpp"

using namespace std;
using namespace std::chrono;

//gprof maxsub gmon.out > analysis_100.txt
//gprof maxsub gmon.out > analysis_1000.txt
//gprof maxsub gmon.out > analysis_10000.txt


vector<int> generateRandomArray(int seed, int size) {
    srand(seed);
    vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 100 - 25;
    }
    return nums;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <random_seed> <input_size>" << endl;
        return 1;
    }

    int seed = atoi(argv[1]);
    int n = atoi(argv[2]);

    auto start_gen = high_resolution_clock::now();
    vector<int> nums = generateRandomArray(seed, n);
    auto end_gen = high_resolution_clock::now();
    auto duration_gen = duration_cast<microseconds>(end_gen - start_gen);
    cout << "Time to generate random array: " << duration_gen.count() << " microseconds" << endl;

    MaxSubArray msa;

    auto start_alg = high_resolution_clock::now();
    cout << "Max sub array sum (O(n)): " << msa.maxSubArraySumON(nums) << endl;
    auto end_alg = high_resolution_clock::now();
    auto duration_alg = duration_cast<microseconds>(end_alg - start_alg);
    cout << "Time for O(n) algorithm: " << duration_alg.count() << " microseconds" << endl;

    start_alg = high_resolution_clock::now();
    cout << "Max sub array sum (O(n^2)): " << msa.maxSubArraySumON2(nums) << endl;
    end_alg = high_resolution_clock::now();
    duration_alg = duration_cast<microseconds>(end_alg - start_alg);
    cout << "Time for O(n^2) algorithm: " << duration_alg.count() << " microseconds" << endl;

    start_alg = high_resolution_clock::now();
    cout << "Max sub array sum (O(n^3)): " << msa.maxSubArraySumON3(nums) << endl;
    end_alg = high_resolution_clock::now();
    duration_alg = duration_cast<microseconds>(end_alg - start_alg);
    cout << "Time for O(n^3) algorithm: " << duration_alg.count() << " microseconds" << endl;

    return 0;
}
