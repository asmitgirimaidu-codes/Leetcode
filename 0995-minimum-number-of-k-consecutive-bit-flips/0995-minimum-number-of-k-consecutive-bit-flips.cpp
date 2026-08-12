#include <vector>
#include <queue>

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        std::queue<int> q; // Stores indices where previous flips end

        for (int i = 0; i < n; ++i) {
            // If the oldest flip is out of the current window [i - k + 1, i], remove it
            if (!q.empty() && q.front() < i) {
                q.pop();
            }

            // The effective value at nums[i] depends on the parity of current active flips
            // q.size() % 2 represents whether the current bit is flipped an odd or even number of times
            if ((nums[i] + q.size()) % 2 == 0) {
                // If it's 0 (effectively), we must flip starting from i
                if (i + k > n) {
                    return -1; // Cannot form a subarray of length k
                }
                flips++;
                q.push(i + k - 1);
            }
        }

        return flips;
    }
};