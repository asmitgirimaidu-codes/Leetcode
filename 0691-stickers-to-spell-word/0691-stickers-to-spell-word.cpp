#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minStickers(std::vector<std::string>& stickers, std::string target) {
        int m = target.length();
        int n = 1 << m;
        std::vector<int> dp(n, -1);
        dp[0] = 0;

        // Count character frequencies for each sticker
        std::vector<std::vector<int>> stickerCounts;
        for (const std::string& sticker : stickers) {
            std::vector<int> count(26, 0);
            for (char c : sticker) {
                count[c - 'a']++;
            }
            stickerCounts.push_back(count);
        }

        // Helper function for memoized DFS / DP
        auto solve = [&](auto& self, int mask) -> int {
            if (dp[mask] != -1) return dp[mask];
            
            int ans = INT_MAX;
            for (const auto& sticker : stickerCounts) {
                int next_mask = mask;
                // Try applying the current sticker to the remaining characters in the target
                std::vector<int> targetCount(26, 0);
                for (int i = 0; i < m; ++i) {
                    if (!((mask >> i) & 1)) {
                        targetCount[target[i] - 'a']++;
                    }
                }

                bool used = false;
                for (int i = 0; i < 26; ++i) {
                    if (targetCount[i] > 0 && sticker[i] > 0) {
                        used = true;
                        break;
                    }
                }
                
                // If the sticker can contribute to the remaining target
                if (used) {
                    for (int i = 0; i < m; ++i) {
                        if (!((next_mask >> i) & 1)) {
                            int charIdx = target[i] - 'a';
                            if (sticker[charIdx] > 0) {
                                // Match this character from the sticker
                                // We need a modifiable representation or can just simulate character matching:
                                // To make it simpler, let's decrement sticker counts as we match.
                            }
                        }
                    }
                }
            }
            
            // Let's rewrite a cleaner transition loop below:
            return 0;
        };

        // Standard iterative / bitmask DP implementation
        std::vector<int> memo(n, -1);
        memo[0] = 0;

        for (int mask = 0; mask < n; ++mask) {
            if (memo[mask] == -1) continue;
            
            for (const auto& sticker : stickerCounts) {
                int nxt = mask;
                std::vector<int> count = sticker;
                
                for (int i = 0; i < m; ++i) {
                    if (!((nxt >> i) & 1)) { // If target[i] is still missing
                        if (count[target[i] - 'a'] > 0) {
                            count[target[i] - 'a']--;
                            nxt |= (1 << i);
                        }
                    }
                }
                
                if (memo[nxt] == -1 || memo[nxt] > memo[mask] + 1) {
                    memo[nxt] = memo[mask] + 1;
                }
            }
        }

        return memo[n - 1];
    }
};