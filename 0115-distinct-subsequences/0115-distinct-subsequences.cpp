#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // Use double to avoid 32-bit signed integer overflow during intermediate DP transitions,
        // although LeetCode states test cases fit in a 32-bit signed integer.
        std::vector<std::vector<double>> dp(m + 1, std::vector<double>(n + 1, 0));
        
        // An empty string 't' can always be formed 1 way by deleting all characters from 's'
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return static_cast<int>(dp[m][n]);
    }
};