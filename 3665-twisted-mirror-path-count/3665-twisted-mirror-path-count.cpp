#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // memo[r][c][d]: stores the final landing cell (r, c) and direction, or {-1, -1} if out of bounds.
        // d = 0: moving right, d = 1: moving down
        vector<vector<vector<pair<int, int>>>> memo(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2})));

        auto get_next = [&](int r, int c, int d, auto& self) -> pair<int, int> {
            if (r < 0 || r >= m || c < 0 || c >= n) return {-1, -1};
            if (memo[r][c][d] != make_pair(-2, -2)) return memo[r][c][d];

            // Mark as visited to prevent infinite loops if mirrors form a cycle
            memo[r][c][d] = {-1, -1};

            if (grid[r][c] == 0) {
                return memo[r][c][d] = {r, c};
            } else {
                // If cell is a mirror (1):
                // Entering moving right (d = 0) deflects down -> (r + 1, c) with d = 1
                // Entering moving down (d = 1) deflects right -> (r, c + 1) with d = 0
                int nr = r + (d == 0 ? 1 : 0);
                int nc = c + (d == 1 ? 1 : 0);
                int nd = (d == 0 ? 1 : 0);
                return memo[r][c][d] = self(nr, nc, nd, self);
            }
        };

        // dp[i][j][0]: ways to arrive at cell (i, j) facing right
        // dp[i][j][1]: ways to arrive at cell (i, j) facing down
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));

        // Base cases from start (0, 0)
        // Move right into (0, 1)
        if (n > 1) {
            auto [r, c] = get_next(0, 1, 0, get_next);
            if (r != -1 && c != -1) {
                dp[r][c][0] = (dp[r][c][0] + 1) % MOD;
            }
        }
        // Move down into (1, 0)
        if (m > 1) {
            auto [r, c] = get_next(1, 0, 1, get_next);
            if (r != -1 && c != -1) {
                dp[r][c][1] = (dp[r][c][1] + 1) % MOD;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int d = 0; d < 2; ++d) {
                    if (dp[i][j][d] == 0) continue;

                    // Try moving Right: next step tries to enter (i, j + 1) moving right (dir = 0)
                    if (j + 1 < n) {
                        auto [nr, nc] = get_next(i, j + 1, 0, get_next);
                        if (nr != -1 && nc != -1) {
                            dp[nr][nc][0] = (dp[nr][nc][0] + dp[i][j][d]) % MOD;
                        }
                    }

                    // Try moving Down: next step tries to enter (i + 1, j) moving down (dir = 1)
                    if (i + 1 < m) {
                        auto [nr, nc] = get_next(i + 1, j, 1, get_next);
                        if (nr != -1 && nc != -1) {
                            dp[nr][nc][1] = (dp[nr][nc][1] + dp[i][j][d]) % MOD;
                        }
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};