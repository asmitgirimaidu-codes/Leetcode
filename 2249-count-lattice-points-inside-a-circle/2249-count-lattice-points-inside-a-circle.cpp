class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> uniquePoints;
        
        for (const auto& circle : circles) {
            int cx = circle[0];
            int cy = circle[1];
            int r = circle[2];
            
            // Iterate through the bounding box of the circle
            for (int x = cx - r; x <= cx + r; ++x) {
                for (int y = cy - r; y <= cy + r; ++y) {
                    // Check if the point (x, y) is inside or on the circle
                    int dx = x - cx;
                    int dy = y - cy;
                    if (dx * dx + dy * dy <= r * r) {
                        uniquePoints.insert({x, y});
                    }
                }
            }
        }
        
        return uniquePoints.size();
    }
};