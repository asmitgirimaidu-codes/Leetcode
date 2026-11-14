#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;
        int n = nums.size();
        
        // Iterate over all possible subarray lengths from l to r
        for (int len = l; len <= r; ++len) {
            // Check all subarrays of the current length
            for (int i = 0; i <= n - len; ++i) {
                int current_sum = 0;
                for (int j = i; j < i + len; ++j) {
                    current_sum += nums[j];
                }
                
                // We are only interested in strictly positive sums
                if (current_sum > 0) {
                    min_sum = std::min(min_sum, current_sum);
                }
            }
        }
        
        // If min_sum was never updated, no valid subarray exists
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};