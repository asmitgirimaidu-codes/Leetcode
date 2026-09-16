class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int R = 2 * k;
        
        if (R > N || R < 0) return 0;
        
        // Compute Combination C(N, R) modulo 10^9 + 7
        vector<long long> C(R + 1, 0);
        C[0] = 1;
        
        for (int i = 1; i <= N; ++i) {
            for (int j = min(i, R); j > 0; --j) {
                C[j] = (C[j] + C[j - 1]) % MOD;
            }
        }
        
        return C[R];
    }
};