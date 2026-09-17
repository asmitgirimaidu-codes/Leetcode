#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Compute prefix sums: P[i] stores the sum of the first i elements
        std::vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int min_length = n + 1;
        std::deque<int> dq; // Stores indices of the prefix sum array
        
        for (int i = 0; i <= n; ++i) {
            // 1. Check if we can form a valid subarray with sum >= k
            // Using the current prefix[i] as the right endpoint
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                min_length = std::min(min_length, i - dq.front());
                dq.pop_front(); // This left endpoint is optimized; remove it
            }
            
            // 2. Maintain monotonic increasing order in the deque
            // If the current prefix sum is smaller than or equal to the back,
            // the back can never be a better (shorter/larger sum) left endpoint.
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            
            // 3. Push current index to the deque
            dq.push_back(i);
        }
        
        return min_length <= n ? min_length : -1;
    }
};