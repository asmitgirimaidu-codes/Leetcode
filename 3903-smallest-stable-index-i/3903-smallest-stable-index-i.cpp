class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // suffix_min[i] will store the minimum value from index i to n - 1
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }
        
        int prefix_max = 0;
        for (int i = 0; i < n; ++i) {
            prefix_max = max(prefix_max, nums[i]);
            
            // Check the instability score condition
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};