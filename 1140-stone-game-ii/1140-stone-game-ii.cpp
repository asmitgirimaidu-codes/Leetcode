class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // suffixSum[i] stores the sum of piles from i to n-1
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // dp[i][M] memoization table initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, suffixSum, dp, n);
    }

private:
    int solve(int i, int M, const vector<int>& suffixSum, vector<vector<int>>& dp, int n) {
        // If we have reached or passed the end, no stones left
        if (i >= n) return 0;

        // If the current player can take all the remaining piles, take them all
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        // Return cached result if already computed
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int maxStones = 0;
        // Try all valid choices for X (1 <= X <= 2M)
        for (int X = 1; X <= 2 * M; ++X) {
            int stonesTaken = suffixSum[i] - suffixSum[i + X];
            int opponentScore = solve(i + X, max(M, X), suffixSum, dp, n);
            maxStones = max(maxStones, stonesTaken + (suffixSum[i + X] - opponentScore));
        }

        return dp[i][M] = maxStones;
    }
};