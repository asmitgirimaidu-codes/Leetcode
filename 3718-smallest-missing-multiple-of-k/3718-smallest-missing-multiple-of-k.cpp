#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int multiple = k;
        while (true) {
            if (numSet.find(multiple) == numSet.end()) {
                return multiple;
            }
            multiple += k;
        }
    }
};