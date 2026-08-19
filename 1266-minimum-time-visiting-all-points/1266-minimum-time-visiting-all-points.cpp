class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        for (size_t i = 1; i < points.size(); ++i) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            
            // The time to move between two points is max(dx, dy) 
            // because diagonal moves cover 1 unit in both x and y simultaneously.
            totalTime += max(dx, dy);
        }
        
        return totalTime;
    }
};