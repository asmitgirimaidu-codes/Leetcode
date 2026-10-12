#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        int n = nums.size();
        // Count the number of set bits for each bit position (0 to 30)
        std::vector<int> bit_counts(31, 0);
        for (int x : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((x >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }

        long long total_sum = 0;
        long long MOD = 1e9 + 7;

        // Greedily construct the k numbers to maximize the sum of squares
        for (int step = 0; step < k; ++step) {
            long long current_val = 0;
            for (int i = 0; i <= 30; ++i) {
                if (bit_counts[i] > 0) {
                    current_val |= (1LL << i);
                    bit_counts[i]--;
                }
            }
            total_sum = (total_sum + (current_val * current_val) % MOD) % MOD;
        }

        return total_sum;
    }
};