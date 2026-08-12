#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumScore(std::vector<std::vector<int>>& grid) {
        const int n = grid.size();
        
        // prefix[j][i] := the sum of the first i elements in the j-th column
        std::vector<std::vector<long long>> prefix(n, std::vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];
            }
        }
        
        std::vector<long long> prevPick(n + 1, 0);
        std::vector<long long> prevSkip(n + 1, 0);
        
        for (int j = 1; j < n; ++j) {
            std::vector<long long> currPick(n + 1, 0);
            std::vector<long long> currSkip(n + 1, 0);
            
            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        // 1. The current height is greater than the previous height.
                        long long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        currPick[curr] = std::max(currPick[curr], prevSkip[prev] + score);
                        currSkip[curr] = std::max(currSkip[curr], prevSkip[prev] + score);
                    } else {
                        // 2. The previous height is greater than or equal to the current height.
                        long long score = prefix[j][prev] - prefix[j][curr];
                        currPick[curr] = std::max(currPick[curr], prevPick[prev] + score);
                        currSkip[curr] = std::max(currSkip[curr], prevPick[prev]);
                    }
                }
            }
            prevPick = std::move(currPick);
            prevSkip = std::move(currSkip);
        }
        
        return *std::max_element(prevPick.begin(), prevPick.end());
    }
};