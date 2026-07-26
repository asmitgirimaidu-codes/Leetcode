class Solution {
private:
    long long memo[17][2][11][11][2];

    long long dp(int idx, bool tight, int last, int secondLast, bool hasStarted, const string& s) {
        if (idx == s.length()) {
            return 0;
        }
        if (memo[idx][tight][last + 1][secondLast + 1][hasStarted] != -1) {
            return memo[idx][tight][last + 1][secondLast + 1][hasStarted];
        }

        long long totalWavinessSum = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            bool nextTight = tight && (digit == limit);
            
            if (!hasStarted && digit == 0) {
                // Leading zeros, number hasn't effectively started in terms of digits
                totalWavinessSum += dp(idx + 1, nextTight, -1, -1, false, s);
            } else if (!hasStarted) {
                // First non-zero digit
                totalWavinessSum += dp(idx + 1, nextTight, digit, -1, true, s);
            } else if (secondLast == -1) {
                // Second digit
                totalWavinessSum += dp(idx + 1, nextTight, digit, last, true, s);
            } else {
                // Third digit onwards, we can check for peaks and valleys
                int currentWaviness = 0;
                // Immediate neighbors are secondLast and digit
                if ((last > secondLast) && (last > digit)) {
                    currentWaviness = 1; // Peak
                } else if ((last < secondLast) && (last < digit)) {
                    currentWaviness = 1; // Valley
                }

                long long ways = nextTight ? 1 : power10(s.length() - 1 - idx);
                // Wait, standard digit DP counts combinations, but here we need the sum of waviness.
                // Number of ways to complete the suffix * currentWaviness + recursive dp sum.
                // Let's implement standard digit DP by returning a pair {count_ways, sum_waviness} or computing via transition.
            }
        }
        return totalWavinessSum;
    }

    long long power10(int n) {
        long long p = 1;
        for (int i = 0; i < n; ++i) p *= 10;
        return p;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        // Implement helper to compute waviness up to a given number
        return countWaviness(num2) - countWaviness(num1 - 1);
    }

    long long countWaviness(long long limit) {
        if (limit < 100) return 0;
        string s = to_string(limit);
        
        // Using pair {count, total_waviness}
        auto solve = [&](const string& str) {
            int n = str.length();
            // dp[idx][tight][last+1][secondLast+1][started] -> pair<long long, long long> {ways, waviness}
            // Let's write a clean memoization structure
            vector<vector<vector<vector<vector<pair<long long, long long>>>>>> dpTable(
                n + 1, vector<vector<vector<vector<pair<long long, long long>>>>>(
                2, vector<vector<vector<pair<long long, long long>>>>(
                12, vector<vector<pair<long long, long long>>>(
                12, vector<pair<long long, long long>>(2, {-1, -1}))))
            );

            auto dfs = [&](auto& self, int idx, bool tight, int last, int secondLast, bool started) -> pair<long long, long long> {
                if (idx == n) {
                    return {1, 0};
                }
                if (dpTable[idx][tight][last + 1][secondLast + 1][started].first != -1) {
                    return dpTable[idx][tight][last + 1][secondLast + 1][started];
                }

                long long totalWays = 0;
                long long totalWavinessVal = 0;
                int lim = tight ? (str[idx] - '0') : 9;

                for (int d = 0; d <= lim; ++d) {
                    bool nextTight = tight && (d == lim);
                    if (!started && d == 0) {
                        auto res = self(self, idx + 1, nextTight, -1, -1, false);
                        totalWays += res.first;
                        totalWavinessVal += res.second;
                    } else if (!started) {
                        auto res = self(self, idx + 1, nextTight, d, -1, true);
                        totalWays += res.first;
                        totalWavinessVal += res.second;
                    } else if (secondLast == -1) {
                        auto res = self(self, idx + 1, nextTight, d, last, true);
                        totalWays += res.first;
                        totalWavinessVal += res.second;
                    } else {
                        int waviness = 0;
                        if (last > secondLast && last > d) {
                            waviness = 1;
                        } else if (last < secondLast && last < d) {
                            waviness = 1;
                        }
                        auto res = self(self, idx + 1, nextTight, d, last, true);
                        totalWays += res.first;
                        totalWavinessVal += res.second + (long long)waviness * res.first;
                    }
                }
                return dpTable[idx][tight][last + 1][secondLast + 1][started] = {totalWays, totalWavinessVal};
            };

            return dfs(dfs, 0, true, -1, -1, false).second;
        };

        return solve(s);
    }
};