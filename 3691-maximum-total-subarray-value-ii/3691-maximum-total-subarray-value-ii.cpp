class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sparse table for range maximum and range minimum
        int K = 0;
        while ((1 << (K + 1)) <= n) K++;
        
        vector<vector<int>> stMax(K + 1, vector<int>(n));
        vector<vector<int>> stMin(K + 1, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }
        
        for (int j = 1; j <= K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                stMax[j][i] = max(stMax[j - 1][i], stMax[j - 1][i + (1 << (j - 1))]);
                stMin[j][i] = min(stMin[j - 1][i], stMin[j - 1][i + (1 << (j - 1))]);
            }
        }
        
        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
        };
        
        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[j][l], stMin[j][r - (1 << j) + 1]);
        };
        
        auto getVal = [&](int l, int r) {
            return (long long)(queryMax(l, r) - queryMin(l, r));
        };
        
        // Max-heap to store triples: {value, l, r}
        priority_queue<tuple<long long, int, int>> pq;
        for (int l = 0; l < n; ++l) {
            pq.push({getVal(l, n - 1), l, n - 1});
        }
        
        long long totalValue = 0;
        while (k > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();
            
            totalValue += val;
            k--;
            
            if (r > l) {
                pq.push({getVal(l, r - 1), l, r - 1});
            }
        }
        
        return totalValue;
    }
};