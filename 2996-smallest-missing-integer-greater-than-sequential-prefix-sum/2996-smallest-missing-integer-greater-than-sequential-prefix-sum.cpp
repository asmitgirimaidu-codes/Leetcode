#include <vector>
#include <numeric>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        
        // Find the longest sequential prefix sum
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }
        
        // Store all elements in an unordered_set for O(1) lookups
        std::unordered_set<int> present(nums.begin(), nums.end());
        
        // Find the smallest integer >= sum that is not in nums
        int x = sum;
        while (present.count(x)) {
            x++;
        }
        
        return x;
    }
};