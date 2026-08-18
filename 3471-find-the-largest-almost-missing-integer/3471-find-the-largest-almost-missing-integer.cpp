#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k = 1
        if (k == 1) {
            std::unordered_map<int, int> count;
            for (int x : nums) {
                count[x]++;
            }
            int ans = -1;
            for (auto& pair : count) {
                if (pair.second == 1) {
                    ans = std::max(ans, pair.first);
                }
            }
            return ans;
        }
        
        // Case 2: k = n
        if (k == n) {
            int max_val = -1;
            for (int x : nums) {
                max_val = std::max(max_val, x);
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n
        // Only nums[0] and nums[n - 1] can possibly appear in exactly one subarray of size k.
        int ans = -1;
        
        // Check frequency of nums[0]
        int count_first = 0;
        for (int x : nums) {
            if (x == nums[0]) count_first++;
        }
        if (count_first == 1) {
            ans = std::max(ans, nums[0]);
        }
        
        // Check frequency of nums[n - 1]
        int count_last = 0;
        for (int x : nums) {
            if (x == nums[n - 1]) count_last++;
        }
        if (count_last == 1) {
            ans = std::max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};