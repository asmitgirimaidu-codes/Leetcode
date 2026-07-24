class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0];
        
        for (int i = 0; i < n; ++i) {
            // Check if it's the end of the current range
            if (i == n - 1 || nums[i + 1] != nums[i] + 1) {
                if (start == nums[i]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                
                // If there are more elements, start a new range
                if (i + 1 < n) {
                    start = nums[i + 1];
                }
            }
        }
        
        return result;
    }
};