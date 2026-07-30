#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int n = nums.size();
        int left = k, right = k;
        int min_val = nums[k];
        int max_score = nums[k];

        // Expand the window outward from index k
        while (left > 0 || right < n - 1) {
            // Decide whether to expand to the left or right based on which adjacent element is larger
            if (left == 0) {
                right++;
            } else if (right == n - 1) {
                left--;
            } else if (nums[left - 1] > nums[right + 1]) {
                left--;
            } else {
                right++;
            }

            // Update the minimum value in the current window
            min_val = std::min({min_val, nums[left], nums[right]});

            // Calculate and update the maximum score
            max_score = std::max(max_score, min_val * (right - left + 1));
        }

        return max_score;
    }
};