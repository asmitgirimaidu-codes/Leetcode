#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    int minimumDistance(std::string word) {
        auto getCoords = [](char c) {
            int idx = c - 'A';
            return std::make_pair(idx / 6, idx % 6);
        };

        auto getDist = [&](char a, char b) {
            if (a == '#') return 0; // Unused / free initial finger position
            auto [r1, c1] = getCoords(a);
            auto [r2, c2] = getCoords(b);
            return std::abs(r1 - r2) + std::abs(c1 - c2);
        };

        // dp[other_finger] where other_finger is represented from 0 to 25, or 26 for unplaced
        // Initialize with a large value representing infinity
        const int INF = 1e9;
        std::vector<int> dp(27, INF);
        
        // Before typing the first character, one finger can be placed at word[0] with 0 cost,
        // and the other finger is unplaced (represented as index 26, meaning '#' character).
        dp[26] = 0;

        for (int i = 1; i < word.length(); ++i) {
            char prev = word[i - 1];
            char curr = word[i];
            std::vector<int> next_dp(27, INF);

            int dist_move_prev = getDist(prev, curr);

            for (int other = 0; other < 27; ++other) {
                if (dp[other] == INF) continue;

                // Option 1: Move the finger that was at 'prev' to 'curr'
                // The other finger remains at 'other'
                next_dp[other == 26 ? 26 : other] = std::min(
                    next_dp[other == 26 ? 26 : other], 
                    dp[other] + dist_move_prev
                );

                // Option 2: Move the finger that was at 'other' to 'curr'
                // The finger that was at 'prev' now becomes the resting finger
                int new_other = (prev == '#') ? 26 : (prev - 'A');
                next_dp[new_other] = std::min(
                    next_dp[new_other], 
                    dp[other] + getDist(other == 26 ? '#' : (other + 'A'), curr)
                );
            }
            dp = std::move(next_dp);
        }

        int ans = INF;
        for (int x : dp) {
            ans = std::min(ans, x);
        }
        return ans;
    }
};