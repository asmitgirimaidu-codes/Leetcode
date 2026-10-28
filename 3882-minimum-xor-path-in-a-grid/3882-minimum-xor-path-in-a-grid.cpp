#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] is a bitset representing all possible XOR values to reach cell (i, j)
        // Max value of grid[i][j] is 1023, so max XOR value is < 1024
        std::vector<std::vector<std::bitset<1024>>> dp(m, std::vector<std::bitset<1024>>(n));
        
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the current cell is reachable with any XOR value
                if (dp[i][j].none()) continue;
                
                // Move right
                if (j + 1 < n) {
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i][j + 1].set(x ^ grid[i][j + 1]);
                        }
                    }
                }
                
                // Move down
                if (i + 1 < m) {
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i + 1][j].set(x ^ grid[i + 1][j]);
                        }
                    }
                }
            }
        }
        
        // Find the minimum XOR value present at the bottom-right cell (m - 1, n - 1)
        for (int x = 0; x < 1024; ++x) {
            if (dp[m - 1][n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};