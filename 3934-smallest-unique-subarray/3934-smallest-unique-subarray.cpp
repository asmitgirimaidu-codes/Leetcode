#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1) return 1;

        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 100003ULL;
        const uint64_t BASE2 = 100019ULL;

        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        auto hasUniqueOfLength = [&](int len) -> bool {
            uint64_t h1 = 0, h2 = 0;
            for (int i = 0; i < len; ++i) {
                uint64_t val = static_cast<uint64_t>(nums[i]);
                h1 = (h1 * BASE1 + val) % MOD1;
                h2 = (h2 * BASE2 + val) % MOD2;
            }

            auto pack = [](uint64_t a, uint64_t b) -> uint64_t {
                return (a << 32) | b;
            };

            unordered_map<uint64_t, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);
            freq[pack(h1, h2)] = 1;

            for (int i = len; i < n; ++i) {
                uint64_t out_val = static_cast<uint64_t>(nums[i - len]);
                uint64_t in_val = static_cast<uint64_t>(nums[i]);

                uint64_t rem1 = (out_val * pow1[len - 1]) % MOD1;
                h1 = (h1 + MOD1 - rem1) % MOD1;
                h1 = (h1 * BASE1 + in_val) % MOD1;

                uint64_t rem2 = (out_val * pow2[len - 1]) % MOD2;
                h2 = (h2 + MOD2 - rem2) % MOD2;
                h2 = (h2 * BASE2 + in_val) % MOD2;

                ++freq[pack(h1, h2)];
            }

            for (const auto& [_, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLength(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};