#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        int m = primes.size();
        std::vector<int> dp(n);
        dp[0] = 1; // The 1st super ugly number is always 1

        // indices[j] tracks the current index in dp for primes[j]
        std::vector<int> indices(m, 0);

        for (int i = 1; i < n; ++i) {
            long long next_ugly = LLONG_MAX;

            // Find the minimum next candidate
            for (int j = 0; j < m; ++j) {
                long long candidate = (long long)dp[indices[j]] * primes[j];
                next_ugly = std::min(next_ugly, candidate);
            }

            dp[i] = next_ugly;

            // Advance pointers for all primes that produced this minimum value to avoid duplicates
            for (int j = 0; j < m; ++j) {
                if ((long long)dp[indices[j]] * primes[j] == next_ugly) {
                    indices[j]++;
                }
            }
        }

        return dp[n - 1];
    }
};