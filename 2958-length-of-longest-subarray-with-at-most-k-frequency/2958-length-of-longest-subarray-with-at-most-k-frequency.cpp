#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            
            // If the frequency of the current element exceeds k, shrink the window from the left
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            // Update the maximum length of the good subarray
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};