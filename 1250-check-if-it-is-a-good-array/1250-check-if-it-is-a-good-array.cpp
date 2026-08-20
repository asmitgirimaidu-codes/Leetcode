#include <vector>
#include <numeric>

class Solution {
public:
    bool isGoodArray(std::vector<int>& nums) {
        int currentGcd = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentGcd = std::gcd(currentGcd, nums[i]);
            // Early exit if GCD becomes 1
            if (currentGcd == 1) {
                return true;
            }
        }
        return currentGcd == 1;
    }
};