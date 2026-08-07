class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if (n <= 3) return false;
        
        for (int i = 3; i < n; ++i) {
            // Case 1: 4th line crosses the 1st line
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }
            
            // Case 2: 5th line meets the 1st line
            if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            
            // Case 3: 6th line crosses the 1st line or further loops
            if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 1] <= distance[i - 3] &&
                distance[i] >= distance[i - 2] - distance[i - 4] && distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }
        
        return false;
    }
};