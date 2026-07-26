class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int globalMax = *max_element(nums.begin(), nums.end());
        int globalMin = *min_element(nums.begin(), nums.end());
        return (long long)(globalMax - globalMin) * k;
    }
};