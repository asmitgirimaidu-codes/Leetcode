class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Base case: Check bounds and whether the current cell is water ('0')
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        
        // Mark the current land cell as visited by turning it into water ('0')
        grid[r][c] = '0';
        
        // Recursively visit all 4 adjacent directions (up, down, left, right)
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        // Traverse through every cell in the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Found an unvisited piece of land ('1')
                if (grid[r][c] == '1') {
                    islandCount++;
                    // Sink/visit the entire connected island using DFS
                    dfs(grid, r, c);
                }
            }
        }
        
        return islandCount;
    }
};