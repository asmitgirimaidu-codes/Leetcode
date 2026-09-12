#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals_input) {
        int n = intervals_input.size();
        // Store {left, right, weight, original_index}
        vector<vector<long long>> intervals(n, vector<long long>(4));
        for (int i = 0; i < n; ++i) {
            intervals[i][0] = intervals_input[i][0]; // left
            intervals[i][1] = intervals_input[i][1]; // right
            intervals[i][2] = intervals_input[i][2]; // weight
            intervals[i][3] = i;                     // original index
        }

        // Sort by right boundary
        sort(intervals.begin(), intervals.end(), [](const vector<long long>& a, const vector<long long>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            if (a[0] != b[0]) return a[0] < b[0];
            return a[3] < b[3];
        });

        // Extract just the right boundaries for binary search
        vector<long long> rights(n);
        for (int i = 0; i < n; ++i) rights[i] = intervals[i][1];

        // dp[count] stores {max_weight, indices_vector}
        // We can optimize space by iterating count from 4 down to 1
        struct State {
            long long weight = 0;
            vector<int> indices;
        };

        auto compareStates = [](const State& a, const State& b) {
            if (a.weight != b.weight) return a.weight < b.weight;
            return a.indices > b.indices; // Lexicographically smaller vector is preferred
        };

        // dp[c][i] -> max state using up to i intervals with c items chosen
        // To save space, we can use a 2D table: dp[c][i]
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int c = 1; c <= 4; ++c) {
            for (int i = 1; i <= n; ++i) {
                // Option 1: Don't pick the current interval (i-1)
                dp[c][i] = dp[c][i - 1];

                // Option 2: Pick the current interval (i-1)
                long long cur_weight = intervals[i - 1][2];
                int cur_left = intervals[i - 1][0];
                
                // Find the latest interval whose right boundary < cur_left
                // Binary search in `rights` up to index i-1
                auto it = lower_bound(rights.begin(), rights.begin() + i - 1, cur_left);
                int prev_idx = distance(rights.begin(), it); // number of valid previous intervals

                State candidate;
                candidate.weight = cur_weight + dp[c - 1][prev_idx].weight;
                candidate.indices = dp[c - 1][prev_idx].indices;
                candidate.indices.push_back(intervals[i - 1][3]);
                sort(candidate.indices.begin(), candidate.indices.end());

                if (compareStates(dp[c][i], candidate)) {
                    dp[c][i] = candidate;
                }
            }
        }

        State best_overall;
        for (int c = 0; c <= 4; ++c) {
            if (compareStates(best_overall, dp[c][n])) {
                best_overall = dp[c][n];
            }
        }

        return best_overall.indices;
    }
};