#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        nums.reserve(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        int rem = nums[0] % x;
        for (int num : nums) {
            if (num % x != rem) {
                return -1;
            }
        }

        int median = nums[nums.size() / 2];
        long long total_operations = 0;

        for (int num : nums) {
            total_operations += abs(num - median) / x;
        }

        return total_operations;
    }
};