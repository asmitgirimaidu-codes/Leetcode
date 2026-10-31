#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        // dp[i] stores the size of the largest divisible subset ending at index i
        std::vector<int> dp(n, 1);
        
        // prev_idx[i] stores the previous index in the subset chain for reconstruction
        std::vector<int> prev_idx(n, -1);

        int max_len = 1;
        int max_index = 0;

        // Step 2: Compute DP values
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                }
            }
            // Track the maximum length and its ending index
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_index = i;
            }
        }

        // Step 3: Reconstruct the subset by backtracking from max_index
        std::vector<int> result;
        int curr = max_index;
        while (curr != -1) {
            result.push_back(nums[curr]);
            curr = prev_idx[curr];
        }

        return result;
    }
};