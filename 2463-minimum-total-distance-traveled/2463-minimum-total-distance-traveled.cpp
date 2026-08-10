#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());
        
        // Expand factories based on their limits
        std::vector<int> factory_positions;
        for (const auto& f : factory) {
            int pos = f[0];
            int limit = f[1];
            for (int i = 0; i < limit; ++i) {
                factory_positions.push_back(pos);
            }
        }
        
        int n = robot.size();
        int m = factory_positions.size();
        
        // dp[i][j] stores the min distance for first i robots using first j factory slots
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1, 1e18));
        
        // Base case: 0 robots require 0 distance
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Option 1: Do not use the j-th factory slot for the i-th robot
                long long skip = dp[i][j - 1];
                
                // Option 2: Use the j-th factory slot for the i-th robot
                long long use = dp[i - 1][j - 1] + std::abs((long long)robot[i - 1] - factory_positions[j - 1]);
                
                dp[i][j] = std::min(skip, use);
            }
        }
        
        return dp[n][m];
    }
};