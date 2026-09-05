#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // prefMax[i] will store the maximum of nums[0..i]
        std::vector<int> prefMax(n);
        prefMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = std::max(prefMax[i - 1], nums[i]);
        }
        
        // suffMin[i] will store the minimum of nums[i..n-1]
        std::vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = std::min(suffMin[i + 1], nums[i]);
        }
        
        // Check each index from 0 to n-1 for the first stable index
        for (int i = 0; i < n; ++i) {
            if (prefMax[i] - suffMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};