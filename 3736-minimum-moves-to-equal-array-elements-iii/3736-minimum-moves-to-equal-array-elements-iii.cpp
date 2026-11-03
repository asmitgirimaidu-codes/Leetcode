#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        // Find the maximum element in the array
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        int total_moves = 0;
        // Sum the differences between the max value and each element
        for (int num : nums) {
            total_moves += (max_val - num);
        }
        
        return total_moves;
    }
};