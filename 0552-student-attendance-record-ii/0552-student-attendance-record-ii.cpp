#include <vector>

class Solution {
public:
    int checkRecord(int n) {
        long long MOD = 1e9 + 7;
        
        // dp[countA][endingL]
        // countA: 0 or 1 (absences)
        // endingL: 0, 1, or 2 (consecutive lates at the end)
        long long dp[2][3] = {0};
        
        // Base case for length 0 (empty string)
        dp[0][0] = 1; // 0 absences, 0 trailing L's
        
        for (int i = 1; i <= n; ++i) {
            long long next_dp[2][3] = {0};
            
            // 1. Append 'P' (Present)
            // 'P' resets consecutive L's to 0, absence count remains the same.
            for (int a = 0; a < 2; ++a) {
                for (int l = 0; l < 3; ++l) {
                    next_dp[a][0] = (next_dp[a][0] + dp[a][l]) % MOD;
                }
            }
            
            // 2. Append 'A' (Absent)
            // 'A' increments absence count (from 0 to 1) and resets consecutive L's to 0.
            for (int l = 0; l < 3; ++l) {
                next_dp[1][0] = (next_dp[1][0] + dp[0][l]) % MOD;
            }
            
            // 3. Append 'L' (Late)
            // 'L' increments consecutive L's (l -> l + 1), absence count remains the same.
            for (int a = 0; a < 2; ++a) {
                for (int l = 0; l < 2; ++l) {
                    next_dp[a][l + 1] = (next_dp[a][l + 1] + dp[a][l]) % MOD;
                }
            }
            
            // Copy next_dp to dp for the next iteration
            for (int a = 0; a < 2; ++a) {
                for (int l = 0; l < 3; ++l) {
                    dp[a][l] = next_dp[a][l];
                }
            }
        }
        
        // Sum up all valid states for length n
        long long total_combinations = 0;
        for (int a = 0; a < 2; ++a) {
            for (int l = 0; l < 3; ++l) {
                total_combinations = (total_combinations + dp[a][l]) % MOD;
            }
        }
        
        return total_combinations;
    }
};