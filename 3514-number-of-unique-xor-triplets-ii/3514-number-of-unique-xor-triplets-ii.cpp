class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048; // nums[i] <= 1500 < 2^11

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            vector<vector<bool>> ndp = dp;

            for (int cnt = 0; cnt <= 3; cnt++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[cnt][x]) continue;

                    // Take this index once
                    if (cnt + 1 <= 3)
                        ndp[cnt + 1][x ^ v] = true;

                    // Take this index twice (v ^ v = 0)
                    if (cnt + 2 <= 3)
                        ndp[cnt + 2][x] = true;

                    // Take this index three times (v ^ v ^ v = v)
                    if (cnt + 3 <= 3)
                        ndp[cnt + 3][x ^ v] = true;
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (bool ok : dp[3]) {
            if (ok) ans++;
        }
        return ans;
    }
};