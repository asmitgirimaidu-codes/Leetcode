#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // dp[j] will store the maximum square side length ending at the current row, column j
        std::vector<int> dp(cols + 1, 0);
        int maxSide = 0;
        int prev = 0; // stores dp[i-1][j-1] from the previous row
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = std::min({dp[j], dp[j - 1], prev}) + 1;
                    maxSide = std::max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        
        return maxSide * maxSide; // return the area
    }
};