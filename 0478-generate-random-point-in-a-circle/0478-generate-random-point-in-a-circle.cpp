#include <vector>
#include <cmath>
#include <cstdlib>

class Solution {
    double rad, xc, yc;
public:
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        // Uniform random radius scaled by sqrt for uniform distribution over area
        double r = rad * std::sqrt((double)rand() / RAND_MAX);
        // Uniform random angle between 0 and 2*pi
        double theta = ((double)rand() / RAND_MAX) * 2.0 * M_PI;
        
        double x = xc + r * std::cos(theta);
        double y = yc + r * std::sin(theta);
        
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */