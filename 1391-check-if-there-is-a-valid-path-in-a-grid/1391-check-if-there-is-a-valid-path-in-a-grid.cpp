class Solution {
private:
    // Define the valid directions for each street type: { {dx, dy}, ... }
    const vector<pair<int, int>> dirs[7] = {
        {},
        {{0, -1}, {0, 1}},   // 1: left, right
        {{-1, 0}, {1, 0}},   // 2: up, down
        {{0, -1}, {1, 0}},   // 3: left, down
        {{0, 1}, {1, 0}},    // 4: right, down
        {{0, -1}, {-1, 0}},  // 5: left, up
        {{0, 1}, {-1, 0}}    // 6: right, up
    };

    bool hasValidConnection(int uType, int vType, int dr, int dc) {
        // dr, dc is the direction from u to v. 
        // v must have an opening back towards u (i.e., opposite direction -dr, -dc).
        for (auto& d : dirs[vType]) {
            if (d.first == -dr && d.second == -dc) {
                return true;
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        auto dfs = [&](auto& self, int r, int c) -> bool {
            if (r == m - 1 && c == n - 1) return true;
            visited[r][c] = true;
            
            int uType = grid[r][c];
            for (auto& d : dirs[uType]) {
                int nr = r + d.first;
                int nc = c + d.second;
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int vType = grid[nr][nc];
                    if (hasValidConnection(uType, vType, d.first, d.second)) {
                        if (self(self, nr, nc)) return true;
                    }
                }
            }
            return false;
        };
        
        return dfs(dfs, 0, 0);
    }
};