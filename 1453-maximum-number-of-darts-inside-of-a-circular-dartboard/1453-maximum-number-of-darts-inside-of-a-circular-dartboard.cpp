class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        if (n <= 1) return n;
        
        int maxDarts = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double x1 = darts[i][0], y1 = darts[i][1];
                double x2 = darts[j][0], y2 = darts[j][1];
                
                double dSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                double d = std::sqrt(dSq);
                
                // If distance between two points is greater than 2*r, no circle of radius r can contain both
                if (d > 2.0 * r || d == 0.0) {
                    continue;
                }
                
                // Find the midpoint
                double midX = (x1 + x2) / 2.0;
                double midY = (y1 + y2) / 2.0;
                
                // Distance from midpoint to the circle centers
                double h = std::sqrt((double)r * r - (d / 2.0) * (d / 2.0));
                
                // Unit vector perpendicular to the line connecting (x1, y1) and (x2, y2)
                double nx = -(y2 - y1) / d;
                double ny = (x2 - x1) / d;
                
                // Two possible circle centers
                double cx1 = midX + h * nx;
                double cy1 = midY + h * ny;
                double cx2 = midX - h * nx;
                double cy2 = midY - h * ny;
                
                int count1 = 0, count2 = 0;
                for (int k = 0; k < n; ++k) {
                    double px = darts[k][0], py = darts[k][1];
                    if ((px - cx1) * (px - cx1) + (py - cy1) * (py - cy1) <= (double)r * r + 1e-6) {
                        count1++;
                    }
                    if ((px - cx2) * (px - cx2) + (py - cy2) * (py - cy2) <= (double)r * r + 1e-6) {
                        count2++;
                    }
                }
                
                maxDarts = std::max({maxDarts, count1, count2});
            }
        }
        
        return maxDarts;
    }
};