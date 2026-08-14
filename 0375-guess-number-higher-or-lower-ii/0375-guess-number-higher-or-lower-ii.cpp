class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] represents the minimum cost to guarantee a win in the range [i, j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // len is the length of the range
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try every number 'x' in the range [i, j] as our first guess
                for (int x = i; x <= j; ++x) {
                    int cost = x + max(x - 1 >= i ? dp[i][x - 1] : 0, 
                                       x + 1 <= j ? dp[x + 1][j] : 0);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n];
    }
};