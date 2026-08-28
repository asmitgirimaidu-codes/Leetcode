#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        int target = sum / k;
        int n = nums.size();
        
        // Sort elements in descending order for better pruning
        std::sort(nums.rbegin(), nums.rend());
        
        // If the largest element is greater than the target subset sum, return false
        if (nums[0] > target) return false;
        
        std::vector<int> memo(1 << n, -1);
        
        // Lambda function for backtracking with memoization
        // mask represents which elements have been used
        auto dfs = [&](auto& self, int mask) -> bool {
            if (mask == (1 << n) - 1) return true;
            if (memo[mask] != -1) return memo[mask];
            
            // Calculate current sum of the subset being formed
            int current_sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    current_sum += nums[i];
                }
            }
            
            int rem = current_sum % target;
            
            for (int i = 0; i < n; ++i) {
                if (!((mask >> i) & 1)) {
                    if (rem + nums[i] <= target) {
                        if (self(self, mask | (1 << i))) {
                            return memo[mask] = 1;
                        }
                    }
                    // Optimization: if rem == 0, trying subsequent elements 
                    // that didn't work means we can break early
                    if (rem == 0) break;
                }
            }
            
            return memo[mask] = 0;
        };
        
        return dfs(dfs, 0);
    }
};