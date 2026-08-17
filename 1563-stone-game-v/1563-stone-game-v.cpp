class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        // dp[i][j] stores the max score for subarray stoneValue[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate by length of the subarray
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int maxScore = 0;
                
                for (int k = i; k < j; ++k) {
                    int leftSum = prefixSum[k + 1] - prefixSum[i];
                    int rightSum = prefixSum[j + 1] - prefixSum[k + 1];
                    
                    int currentScore = 0;
                    if (leftSum < rightSum) {
                        currentScore = leftSum + dp[i][k];
                    } else if (leftSum > rightSum) {
                        currentScore = rightSum + dp[k + 1][j];
                    } else {
                        currentScore = max(leftSum + dp[i][k], rightSum + dp[k + 1][j]);
                    }
                    
                    maxScore = max(maxScore, currentScore);
                }
                dp[i][j] = maxScore;
            }
        }

        return dp[0][n - 1];
    }
};