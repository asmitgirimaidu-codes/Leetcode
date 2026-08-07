class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalArea = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                if (v > 0) {
                    // Add top and bottom faces
                    totalArea += 2;
                    // Add 4 sides per cube in the tower
                    totalArea += 4 * v;
                    
                    // Subtract adjacent shared faces (down and right neighbors to avoid double counting)
                    if (i + 1 < n) {
                        totalArea -= 2 * std::min(v, grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        totalArea -= 2 * std::min(v, grid[i][j + 1]);
                    }
                }
            }
        }
        
        return totalArea;
    }
};