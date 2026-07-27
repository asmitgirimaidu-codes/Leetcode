class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        // 1. Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // 2. Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // 3. Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};