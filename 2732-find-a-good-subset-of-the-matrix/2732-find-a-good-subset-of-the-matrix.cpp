class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Map to store the first row index for each unique bitmask
        unordered_map<int, int> maskToIndex;
        
        for (int i = 0; i < m; ++i) {
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    mask |= (1 << j);
                }
            }
            
            // Check if current row is all zeros
            if (mask == 0) return {i};
            
            maskToIndex[mask] = i;
        }
        
        // Check all pairs of masks
        for (auto const& [mask1, i1] : maskToIndex) {
            for (auto const& [mask2, i2] : maskToIndex) {
                if ((mask1 & mask2) == 0) {
                    // Return indices in ascending order
                    if (i1 < i2) return {i1, i2};
                    else return {i2, i1};
                }
            }
        }
        
        return {};
    }
};