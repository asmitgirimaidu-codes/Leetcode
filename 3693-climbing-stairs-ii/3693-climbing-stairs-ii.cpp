class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j] stores the minimum total cost to reach step j
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            // Try jumping from i to j, where i can be j-1, j-2, or j-3
            for (int i = max(0, j - 3); i < j; ++i) {
                long long cost = dp[i] + costs[j - 1] + (long long)(j - i) * (j - i);
                dp[j] = min(dp[j], cost);
            }
        }
        
        return dp[n];
    }
};