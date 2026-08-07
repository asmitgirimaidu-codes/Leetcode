#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);
        
        // Create an array of indices sorted by their corresponding values in ascending order
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        
        int max_jumps = 1;

        for (int i : indices) {
            dp[i] = 1; // At least we can visit the starting index itself
            
            // Check jumps to the left
            for (int j = i - 1; j >= max(0, i - d); --j) {
                if (arr[j] >= arr[i]) break; // Blocked by a taller or equal bar
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            
            // Check jumps to the right
            for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
                if (arr[j] >= arr[i]) break; // Blocked by a taller or equal bar
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            
            max_jumps = max(max_jumps, dp[i]);
        }
        
        return max_jumps;
    }
};