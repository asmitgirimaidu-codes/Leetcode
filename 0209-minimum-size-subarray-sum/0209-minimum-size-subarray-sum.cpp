#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0;
        int currentSum = 0;
        
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            while (currentSum >= target) {
                minLength = std::min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};