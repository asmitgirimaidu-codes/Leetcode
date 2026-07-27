class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0; // Represents dp[i-2]
        int rob2 = 0; // Represents dp[i-1]
        
        // [rob1, rob2, current_house, ...]
        for (int num : nums) {
            int current = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = current;
        }
        
        return rob2;
    }
};