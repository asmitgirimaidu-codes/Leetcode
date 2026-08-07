class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0.0, y = 0.0;
        int n = positions.size();
        
        // Initial guess: Centroid of all points
        for (const auto& p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        
        double step = 100.0;
        double eps = 1e-7;
        
        // Directions for gradient descent check
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        // Gradient descent with decreasing step size
        while (step > eps) {
            bool improved = false;
            for (int i = 0; i < 4; ++i) {
                double nx = x + step * dx[i];
                double ny = y + step * dy[i];
                
                double currDist = 0.0, nextDist = 0.0;
                for (const auto& p : positions) {
                    currDist += std::hypot(x - p[0], y - p[1]);
                    nextDist += std::hypot(nx - p[0], ny - p[1]);
                }
                
                if (nextDist < currDist) {
                    x = nx;
                    y = ny;
                    improved = true;
                    break;
                }
            }
            
            if (!improved) {
                step /= 2.0;
            }
        }
        
        // Compute final minimum distance sum
        double minDistSum = 0.0;
        for (const auto& p : positions) {
            minDistSum += std::hypot(x - p[0], y - p[1]);
        }
        
        return minDistSum;
    }
};