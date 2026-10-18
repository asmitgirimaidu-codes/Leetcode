#include <vector>

class Solution {
private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    // Helper function to calculate number of ways recursively
    long long solve(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        std::vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = solve(left) % MOD;
        long long rightWays = solve(right) % MOD;

        int L = left.size();
        int R = right.size();

        // ways = comb(L + R, L) * leftWays * rightWays
        long long ways = (table[L + R][L] * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;

        return ways;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        
        // Initialize Pascal's triangle for combinations
        table.resize(n + 1, std::vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 because the problem asks for *reorderings* (excluding the original array itself)
        return (solve(nums) - 1 + MOD) % MOD;
    }
};