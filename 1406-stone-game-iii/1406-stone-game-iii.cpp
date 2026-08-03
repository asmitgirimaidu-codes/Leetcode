#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] represents the max score difference starting from index i
        // Using three variables to optimize space: dp[i%4], dp[(i+1)%4], etc.
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int takeSum = 0;
            int maxDiff = INT_MIN;

            // Try taking 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
                takeSum += stoneValue[i + k - 1];
                maxDiff = max(maxDiff, takeSum - dp[(i + k) % 4]);
            }
            dp[i % 4] = maxDiff;
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};