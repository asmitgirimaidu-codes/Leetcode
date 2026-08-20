#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate Least Common Multiple (LCM) with long long to avoid overflow
    long long lcm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

    // Helper function to calculate LCM of three numbers
    long long lcm3(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }

    // Count how many numbers <= x are divisible by a, b, or c
    long long count(long long x, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm3(a, b, c);

        return (x / a) + (x / b) + (x / c) 
             - (x / ab) - (x / bc) - (x / ac) 
             + (x / abc);
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1, high = 2e9, ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid, a, b, c) >= n) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid number
            } else {
                low = mid + 1;
            }
        }

        return static_cast<int>(ans);
    }
};