#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1; // Any single element subarray is product equivalent

        // Maximum LCM of elements <= 10 is lcm(1..10) = 2520.
        // We cap the running product safely above 2520 * 2520 to prevent overflow
        // while keeping the exact equality check valid.
        const long long MAX_LCM = 2520LL;
        const long long PRODUCT_CAP = MAX_LCM * MAX_LCM * 10LL;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod <= PRODUCT_CAP / x) {
                    prod *= x;
                } else {
                    prod = PRODUCT_CAP + 1;
                }

                g = (j == i) ? nums[j] : std::gcd(g, nums[j]);
                l = std::lcm(l, x);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                // Once prod exceeds max possible l * g (at most 2520 * max_gcd <= 2520 * 10),
                // expanding j further can only keep prod large while l <= 2520 and g <= 10.
                if (prod > MAX_LCM * 10LL && l <= MAX_LCM) {
                    break;
                }
            }
        }

        return ans;
    }
};