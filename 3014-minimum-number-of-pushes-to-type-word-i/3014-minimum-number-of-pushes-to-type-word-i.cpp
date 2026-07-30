class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        
        for (int i = 0; i < n; ++i) {
            // Determine how many pushes are needed based on the 8-key grouping
            totalPushes += (i / 8 + 1);
        }
        
        return totalPushes;
    }
};