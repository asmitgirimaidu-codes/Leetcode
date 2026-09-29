#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    int m, n;
    int memo[100][100][201]; // max dimensions are 100x100, max balance ~ 200

    bool dfs(int r, int c, int balance, const vector<vector<char>>& grid) {
        // If current character makes balance negative, invalid
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) return false;

        // If we reached the bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool res = false;
        // Move down
        if (r + 1 < m) {
            res = res || dfs(r + 1, c, balance, grid);
        }
        // Move right
        if (c + 1 < n && !res) {
            res = res || dfs(r, c + 1, balance, grid);
        }

        return memo[r][c][balance] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Length of path must be even
        if ((m + n - 1) % 2 != 0) return false;

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};