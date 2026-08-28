#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int dist[16][16];
    int memo[16][1 << 15][2];
    int n;

    // BFS to find the shortest knight moves between source (x, y) and all pawns
    void bfs(int startIdx, int sx, int sy, const vector<vector<int>>& positions) {
        int d[50][50];
        memset(d, -1, sizeof(d));
        queue<pair<int, int>> q;
        
        q.push({sx, sy});
        d[sx][sy] = 0;
        
        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < 50 && nc >= 0 && nc < 50 && d[nr][nc] == -1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            dist[startIdx][i] = d[positions[i][0]][positions[i][1]];
        }
    }

    // Minimax DP with Bitmask
    int solve(int u, int mask, bool isAlice) {
        if (mask == 0) return 0;
        if (memo[u][mask][isAlice] != -1) return memo[u][mask][isAlice];

        int res = isAlice ? -1e9 : 1e9;

        for (int v = 0; v < n; ++v) {
            if ((mask & (1 << v)) != 0) {
                int nextMask = mask ^ (1 << v);
                if (isAlice) {
                    res = max(res, dist[u][v] + solve(v, nextMask, false));
                } else {
                    res = min(res, dist[u][v] + solve(v, nextMask, true));
                }
            }
        }

        return memo[u][mask][isAlice] = res;
    }

public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        n = positions.size();
        
        // Combine knight start position into positions list at index `n`
        vector<vector<int>> allPositions = positions;
        allPositions.push_back({kx, ky});

        // Precompute all-pairs shortest paths using BFS
        for (int i = 0; i <= n; ++i) {
            bfs(i, allPositions[i][0], allPositions[i][1], positions);
        }

        memset(memo, -1, sizeof(memo));

        // Start from the knight's position (index n), all pawns present (mask = (1 << n) - 1), Alice's turn
        return solve(n, (1 << n) - 1, true);
    }
};