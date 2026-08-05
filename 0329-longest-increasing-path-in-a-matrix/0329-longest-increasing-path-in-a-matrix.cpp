#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dfs(int r, int c, int m, int n, const vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }

        int maxLen = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                maxLen = max(maxLen, 1 + dfs(nr, nc, m, n, matrix, memo));
            }
        }

        return memo[r][c] = maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, m, n, matrix, memo));
            }
        }

        return ans;
    }
};