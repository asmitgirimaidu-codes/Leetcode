#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // divisors[L] stores all proper divisors of length L (strictly less than L)
        vector<vector<int>> divisors(n + 1);
        for (int l = 1; l <= n; ++l) {
            for (int d = 1; d < l; ++d) {
                if (l % d == 0) {
                    divisors[l].push_back(d);
                }
            }
        }
        
        // cost[i][j] stores the min changes to make s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = 1e9;
                
                // Try all valid divisors d of the length
                for (int d : divisors[len]) {
                    int current_changes = 0;
                    // Check each group defined by step d
                    for (int start = 0; start < d; ++start) {
                        int left = i + start;
                        int right = j - (d - 1 - start);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                current_changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_changes = min(min_changes, current_changes);
                }
                cost[i][j] = min_changes;
            }
        }
        
        // dp[i][parts] = min changes to partition suffix s[i...] into parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 0; i < n; ++i) {
                // We need at least enough characters left for the remaining parts (each part needs length >= 2)
                for (int j = i + 1; j < n - (k - parts); ++j) {
                    if (dp[i][parts - 1] != 1e9) {
                        dp[j + 1][parts] = min(dp[j + 1][parts], dp[i][parts - 1] + cost[i][j]);
                    }
                }
            }
        }
        
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[i][k - 1] + cost[i][n - 1]);
        }
        
        return ans;
    }
};