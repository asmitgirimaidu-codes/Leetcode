class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        // dp[r] keeps track of the count of subarrays ending at the previous step with product mod k equal to r
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int rem = num % k;
            
            // A new subarray starting and ending at the current element
            next_dp[rem]++;
            
            // Extend all previous subarrays ending at the last index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }
            
            dp = move(next_dp);
            
            // Add counts of all remainders at the current step to the total answer
            for (int r = 0; r < k; ++r) {
                ans[r] += dp[r];
            }
        }
        
        return ans;
    }
};