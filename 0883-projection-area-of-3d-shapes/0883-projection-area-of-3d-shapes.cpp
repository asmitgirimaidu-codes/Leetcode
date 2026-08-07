class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xyArea = 0;
        int yzArea = 0;
        int xzArea = 0;
        
        for (int i = 0; i < n; ++i) {
            int maxRow = 0;
            int maxCol = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    xyArea++;
                }
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            yzArea += maxRow;
            xzArea += maxCol;
        }
        
        return xyArea + yzArea + xzArea;
    }
};