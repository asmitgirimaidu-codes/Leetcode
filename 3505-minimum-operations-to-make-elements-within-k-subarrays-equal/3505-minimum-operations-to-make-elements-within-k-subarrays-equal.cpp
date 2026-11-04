#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int num_windows = n - x + 1;
        vector<long long> window_cost(num_windows, 0);

        // Helper structures for sliding window median and cost calculation
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;

        auto balance = [&]() {
            if (low.size() > high.size() + 1) {
                long long val = *low.rbegin();
                low.erase(low.find(val));
                sum_low -= val;
                high.insert(val);
                sum_high += val;
            } else if (high.size() > low.size()) {
                long long val = *high.begin();
                high.erase(high.begin());
                sum_high -= val;
                low.insert(val);
                sum_low += val;
            }
        };

        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sum_low += val;
            } else {
                high.insert(val);
                sum_high += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto it = low.find(val);
            if (it != low.end()) {
                low.erase(it);
                sum_low -= val;
            } else {
                it = high.find(val);
                if (it != high.end()) {
                    high.erase(it);
                    sum_high -= val;
                }
            }
            balance();
        };

        // Initialize the first window
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }

        // Calculate cost for the first window (median is *low.rbegin())
        long long median = *low.rbegin();
        window_cost[0] = (low.size() * median - sum_low) + (sum_high - high.size() * median);

        // Slide the window across the array
        for (int i = 1; i < num_windows; ++i) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);
            median = *low.rbegin();
            window_cost[i] = (low.size() * median - sum_low) + (sum_high - high.size() * median);
        }

        // DP to pick k non-overlapping windows separated by at least x indices
        // dp[j][i] = min cost using j windows up to window index i
        const long long INF = 1e18;
        vector<long long> dp(num_windows + 1, INF);
        vector<long long> next_dp(num_windows + 1, INF);

        dp[0] = 0;
        for (int j = 1; j <= k; ++j) {
            long long min_prev = INF;
            for (int i = 0; i <= num_windows; ++i) {
                next_dp[i] = min_prev;
                if (i < num_windows) {
                    long long prev_val = dp[i];
                    if (prev_val != INF) {
                        min_prev = min(min_prev, prev_val + window_cost[i]);
                    }
                }
            }
            // For the next window, we must respect the non-overlapping constraint (at least x distance)
            for (int i = 0; i <= num_windows; ++i) {
                dp[i] = next_dp[i];
            }
            if (j < k) {
                // Shift indices to account for the distance x between valid window starts
                vector<long long> temp(num_windows + 1, INF);
                long long best = INF;
                for (int i = 0; i < num_windows; ++i) {
                    if (dp[i] != INF) {
                        best = min(best, dp[i]);
                    }
                    if (i + x < num_windows) {
                        // The next valid window can start at i + x
                        // We will properly carry over the minimums
                    }
                }
            }
        }

        // Simpler DP transition approach using standard tabulation for k intervals:
        // dp[i][j]: min cost using j windows from the first i windows
        vector<vector<long long>> dp_table(k + 1, vector<long long>(num_windows + 1, INF));
        for (int i = 0; i <= num_windows; ++i) {
            dp_table[0][i] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            long long min_so_far = INF;
            for (int i = 1; i <= num_windows; ++i) {
                // If we can include window i-1 (0-indexed window_cost[i-1])
                // We need to jump back by at least x steps to avoid overlap
                long long prev_cost = (i - x >= 0) ? dp_table[j - 1][i - x] : (j - 1 == 0 ? 0 : INF);
                if (prev_cost != INF) {
                    min_so_far = min(min_so_far, prev_cost + window_cost[i - 1]);
                }
                dp_table[j][i] = min(dp_table[j][i - 1], min_so_far);
            }
        }

        return dp_table[k][num_windows];
    }
};