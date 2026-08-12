#include <vector>
#include <algorithm>

class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int n = nums.size() - 1;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        
        return nums.back() == n;
    }
};