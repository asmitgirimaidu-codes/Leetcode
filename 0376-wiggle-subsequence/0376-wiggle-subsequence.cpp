#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        int prevDiff = nums[1] - nums[0];
        int count = (prevDiff != 0) ? 2 : 1;
        
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            // If we find a peak or a valley (alternating signs)
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        
        return count;
    }
};