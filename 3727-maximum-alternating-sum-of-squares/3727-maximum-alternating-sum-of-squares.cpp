class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squared(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squared[i] = val * val;
        }
        
        sort(squared.begin(), squared.end());
        
        long long max_score = 0;
        // The first n / 2 elements are subtracted
        for (int i = 0; i < n / 2; ++i) {
            max_score -= squared[i];
        }
        // The remaining elements are added
        for (int i = n / 2; i < n; ++i) {
            max_score += squared[i];
        }
        
        return max_score;
    }
};