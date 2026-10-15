#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Generate all possible subarrays
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            for (int j = i; j < n; ++j) {
                // Add the current element to the set for subarray nums[i..j]
                distinctElements.insert(nums[j]);
                
                // Get the count of distinct elements
                int count = distinctElements.size();
                
                // Add the square of the distinct count to the total sum
                totalSum += count * count;
            }
        }

        return totalSum;
    }
};