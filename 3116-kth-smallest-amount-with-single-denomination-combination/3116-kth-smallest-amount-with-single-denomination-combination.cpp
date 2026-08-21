#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        long long low = 1;
        // The maximum possible answer can be min(coins) * k. 
        // Given constraints: min coin is 1, max k is 2 * 10^9, so max answer can be 2 * 10^9.
        // Wait, max coin value is up to 2000, and max k is 2 * 10^9, so max answer can be 2000 * 2 * 10^9 = 4 * 10^12.
        // Let's set high safely to 25LL * 10^10 or max coin * k.
        long long min_coin = *std::min_element(coins.begin(), coins.end());
        long long high = (long long)min_coin * k; 
        long long ans = high;
        
        // Helper function to compute Greatest Common Divisor
        auto gcd = [](long long a, long long b) {
            while (b) {
                a %= b;
                std::swap(a, b);
            }
            return a;
        };

        // Helper function to compute Least Common Multiple, capped at limit (high)
        auto lcm = [&](long long a, long long b, long long limit) {
            if (a == 0 || b == 0) return 0LL;
            long long g = gcd(a, b);
            if (a / g > limit / b) return limit + 1; // Overflow protection
            return (a * b) / g;
        };

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            int n = coins.size();

            // Iterate through all non-empty subsets using bitmasking
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int set_bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        set_bits++;
                        current_lcm = lcm(current_lcm, coins[i], mid);
                        if (current_lcm > mid) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (!overflow) {
                    if (set_bits % 2 == 1) {
                        count += mid / current_lcm;
                    } else {
                        count -= mid / current_lcm;
                    }
                }
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};