class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        
        // Step 1: Collect all coordinates in the matrix
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                result.push_back({r, c});
            }
        }
        
        // Step 2: Sort based on Manhattan distance from (rCenter, cCenter)
        auto comp = [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            int distA = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int distB = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return distA < distB;
        };
        
        sort(result.begin(), result.end(), comp);
        
        return result;
    }
};