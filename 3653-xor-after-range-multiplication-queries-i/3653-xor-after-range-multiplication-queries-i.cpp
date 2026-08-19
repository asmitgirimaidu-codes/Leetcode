#include <vector>

class Solution {
public:
    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int finalXor = 0;
        for (int x : nums) {
            finalXor ^= x;
        }
        
        return finalXor;
    }
};