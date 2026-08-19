#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));

        std::queue<std::pair<int, int>> pacificQueue;
        std::queue<std::pair<int, int>> atlanticQueue;

        // 1. Add Pacific borders (top row and left column) and Atlantic borders (bottom row and right column)
        for (int i = 0; i < m; ++i) {
            pacificQueue.push({i, 0});
            pacific[i][0] = true;
            atlanticQueue.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; ++j) {
            pacificQueue.push({0, j});
            pacific[0][j] = true;
            atlanticQueue.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }

        // Helper function for BFS traversal
        auto bfs = [&](std::queue<std::pair<int, int>>& q, std::vector<std::vector<bool>>& visited) {
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        // Water can flow upstream if the neighbor's height is >= current cell's height
                        if (heights[nr][nc] >= heights[r][c]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        };

        // Run BFS for both oceans
        bfs(pacificQueue, pacific);
        bfs(atlanticQueue, atlantic);

        // Find cells that can reach both oceans
        std::vector<std::vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};