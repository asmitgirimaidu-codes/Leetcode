class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add building 1 with height 0 and building n with max possible height
        restrictions.push_back({1, 0});
        bool hasN = false;
        for (const auto& r : restrictions) {
            if (r[0] == n) {
                hasN = true;
                break;
            }
        }
        if (!hasN) {
            restrictions.push_back({n, n - 1});
        }
        
        // Sort restrictions by building ID
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Forward pass: adjust heights from left to right
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }
        
        // Backward pass: adjust heights from right to left
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }
        
        // Find the maximum possible building height between any two consecutive restrictions
        int maxHeight = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0];
            int h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0];
            int h2 = restrictions[i + 1][1];
            
            // Peak height formula between two restrictions
            int dist = id2 - id1;
            int peak = (h1 + h2 + dist) / 2;
            maxHeight = max(maxHeight, peak);
        }
        
        return maxHeight;
    }
};