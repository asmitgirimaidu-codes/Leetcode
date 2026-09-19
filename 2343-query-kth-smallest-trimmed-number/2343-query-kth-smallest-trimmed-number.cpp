#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> ans;

        for (const auto& q : queries) {
            int k = q[0];
            int trim = q[1];

            // Store pairs of (trimmed_string, original_index)
            vector<pair<string, int>> trimmedNums(n);
            for (int i = 0; i < n; i++) {
                trimmedNums[i] = {nums[i].substr(m - trim), i};
            }

            // Sort based on the trimmed string values; if equal, sort by original index
            sort(trimmedNums.begin(), trimmedNums.end());

            // The k-th smallest (1-indexed, so k - 1)
            ans.push_back(trimmedNums[k - 1].second);
        }

        return ans;
    }
};