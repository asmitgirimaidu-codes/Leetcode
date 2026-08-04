#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min-heap to store {elevation, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr[0], r = curr[1], c = curr[2];
            
            // If we reach the bottom-right cell
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The time to reach the next cell is the maximum of the current time and the next cell's elevation
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        
        return -1;
    }
};