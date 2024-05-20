#include "MaxSub_alg.hpp"
#include <algorithm>
#include <climits>

using namespace std;

int MaxSubArray::maxSubArraySumON(const vector<int>& nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int num : nums) {
        current_sum = max(num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int MaxSubArray::maxSubArraySumON2(const vector<int>& nums) {
    int n = nums.size();
    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += nums[j];
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

int MaxSubArray::maxSubArraySumON3(const vector<int>& nums) {
    int n = nums.size();
    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int current_sum = 0;
            for (int k = i; k <= j; ++k) {
                current_sum += nums[k];
            }
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}
