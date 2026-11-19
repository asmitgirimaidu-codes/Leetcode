#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        // Case 1: discard two smallest -> range [nums[2], nums[n - 1]]
        int dropTwoSmallest = nums[n - 1] - nums[2];
        // Case 2: discard two largest  -> range [nums[0], nums[n - 3]]
        int dropTwoLargest  = nums[n - 3] - nums[0];
        // Case 3: discard one smallest & one largest -> range [nums[1], nums[n - 2]]
        int dropBothEnds    = nums[n - 2] - nums[1];

        return min({dropTwoSmallest, dropTwoLargest, dropBothEnds});
    }
};