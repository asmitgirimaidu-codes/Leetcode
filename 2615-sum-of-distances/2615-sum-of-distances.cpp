#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> indices;

        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        // Process each unique number's index list
        for (auto& pair : indices) {
            const vector<int>& idx_list = pair.second;
            int m = idx_list.size();
            if (m <= 1) continue;

            vector<long long> prefix_sum(m + 1, 0);
            for (int i = 0; i < m; ++i) {
                prefix_sum[i + 1] = prefix_sum[i] + idx_list[i];
            }

            for (int i = 0; i < m; ++i) {
                long long current_idx = idx_list[i];
                
                // Left side contribution: (i * current_idx) - sum of indices to the left
                long long left_contrib = (long long)i * current_idx - prefix_sum[i];
                
                // Right side contribution: sum of indices to the right - ((m - 1 - i) * current_idx)
                long long right_contrib = (prefix_sum[m] - prefix_sum[i + 1]) - (long long)(m - 1 - i) * current_idx;
                
                arr[current_idx] = left_contrib + right_contrib;
            }
        }

        return arr;
    }
};