#include <climits>
#include <vector>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num; // Update smallest element
            } else if (num <= second) {
                second = num; // Update second smallest element
            } else {
                // Found a number greater than both first and second
                return true;
            }
        }
        
        return false;
    }
};