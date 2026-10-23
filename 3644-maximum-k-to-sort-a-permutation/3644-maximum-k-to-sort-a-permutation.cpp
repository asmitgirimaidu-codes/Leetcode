#include <vector>

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        
        for (int i = 0; i < n; ++i) {
            // Check if the element is not in its correct position
            if (nums[i] != i) {
                if (k == -1) {
                    k = nums[i];
                } else {
                    k &= nums[i];
                }
            }
        }
        
        // If all elements are already in their correct positions
        return (k == -1) ? 0 : k;
    }
};