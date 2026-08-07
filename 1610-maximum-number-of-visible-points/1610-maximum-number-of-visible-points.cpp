class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int sameLocationCount = 0;
        
        for (const auto& p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];
            
            if (dx == 0 && dy == 0) {
                sameLocationCount++;
                continue;
            }
            
            double rad = std::atan2(dy, dx);
            double deg = rad * 180.0 / M_PI;
            angles.push_back(deg);
        }
        
        sort(angles.begin(), angles.end());
        
        int n = angles.size();
        for (int i = 0; i < n; ++i) {
            angles.push_back(angles[i] + 360.0);
        }
        
        int maxVisible = 0;
        int left = 0;
        
        for (int right = 0; right < angles.size(); ++right) {
            while (angles[right] - angles[left] > angle) {
                left++;
            }
            maxVisible = std::max(maxVisible, right - left + 1);
        }
        
        return maxVisible + sameLocationCount;
    }
};