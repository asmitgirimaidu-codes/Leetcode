#include <vector>
#include <cstring>

class Solution {
public:
    int countTriplets(std::vector<int>& nums) {
        int max_val = 1 << 16;
        // cnt[v] stores the frequency of pairs (i, j) such that nums[i] & nums[j] == v
        std::vector<int> cnt(max_val, 0);

        for (int x : nums) {
            for (int y : nums) {
                cnt[x & y]++;
            }
        }

        int ans = 0;
        for (int x : nums) {
            for (int mask = 0; mask < max_val; mask++) {
                if ((mask & x) == 0) {
                    ans += cnt[mask];
                }
            }
        }

        return ans;
    }
};