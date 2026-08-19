#include <vector>
#include <queue>

class Solution {
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        // Min-priority queue stores tuples of {height, row, col}
        using Cell = std::pair<int, std::pair<int, int>>;
        std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> pq;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        // Step 1: Add all outer boundary cells to the priority queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Process cells from the boundary inwards
        while (!pq.empty()) {
            auto [h, coord] = pq.top();
            pq.pop();
            int r = coord.first;
            int c = coord.second;

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // If neighbor is lower than current boundary, water can be trapped
                    if (heightMap[nr][nc] < h) {
                        waterTrapped += h - heightMap[nr][nc];
                    }
                    // The effective height of the neighbor becomes the max of its own height and the current boundary
                    pq.push({std::max(heightMap[nr][nc], h), {nr, nc}});
                }
            }
        }

        return waterTrapped;
    }
};