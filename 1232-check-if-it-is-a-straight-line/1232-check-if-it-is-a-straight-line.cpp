class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        int x0 = points[0][0], y0 = points[0][1];
        int x1 = points[1][0], y1 = points[1][1];
        
        // Check slope consistency for every subsequent point using cross multiplication:
        // (y1 - y0) * (x - x0) == (y - y0) * (x1 - x0)
        for (int i = 2; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            if ((y1 - y0) * (x - x0) != (y - y0) * (x1 - x0)) {
                return false;
            }
        }
        
        return true;
    }
};