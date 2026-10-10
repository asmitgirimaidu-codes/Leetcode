class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        
        // Count frequencies of each absolute difference
        unordered_map<int, long long> diffCount;
        int maxDiff = 0;
        long long totalDiffSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diffCount[d]++;
            maxDiff = max(maxDiff, d);
            totalDiffSum += d;
        }
        
        // If total operations can reduce all differences to 0
        if (totalDiffSum <= totalK) {
            return 0;
        }
        
        // Greedily reduce from maxDiff down to 0
        for (int d = maxDiff; d > 0 && totalK > 0; --d) {
            if (diffCount.find(d) == diffCount.end()) continue;
            
            long long count = diffCount[d];
            long long operationsNeeded = min(totalK, count);
            
            // Reduce 'operationsNeeded' elements from diff 'd' to 'd - 1'
            diffCount[d] -= operationsNeeded;
            diffCount[d - 1] += operationsNeeded;
            totalK -= operationsNeeded;
        }
        
        // Calculate the final minimum sum of squared differences
        long long minSumSqDiff = 0;
        for (auto& [d, count] : diffCount) {
            if (d > 0 && count > 0) {
                minSumSqDiff += (long long)d * d * count;
            }
        }
        
        return minSumSqDiff;
    }
};