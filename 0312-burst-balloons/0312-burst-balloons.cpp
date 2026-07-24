class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add 1 at both ends to handle boundary conditions easily
        vector<int> extendedNums(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            extendedNums[i + 1] = nums[i];
        }
        
        // dp[i][j] represents the maximum coins that can be collected by bursting balloons between index i and j (exclusive)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // Length of the sub-array of balloons
        for (int length = 1; length <= n; ++length) {
            for (int left = 1; left <= n - length + 1; ++left) {
                int right = left + length - 1;
                
                // Try bursting each balloon 'k' as the LAST balloon to burst in the range [left, right]
                for (int k = left; k <= right; ++k) {
                    int coins = extendedNums[left - 1] * extendedNums[k] * extendedNums[right + 1];
                    coins += dp[left][k - 1] + dp[k + 1][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        
        return dp[1][n];
    }
};