#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long all_sum = 0;
        long long f = 0;

        for (int i = 0; i < n; ++i) {
            all_sum += nums[i];
            f += (long long)i * nums[i];
        }

        long long max_val = f;
        for (int i = n - 1; i >= 1; --i) {
            f = f + all_sum - n * nums[i];
            max_val = max(max_val, f);
        }

        return max_val;
    }
};