class Solution {
public:
    int numSquares(int n) {
        // dp[i] will store the least number of perfect square numbers that sum to i
        vector<int> dp(n + 1, n);
        dp[0] = 0; // Base case: 0 sum requires 0 squares

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                int square = j * j;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        
        return dp[n];
    }
};