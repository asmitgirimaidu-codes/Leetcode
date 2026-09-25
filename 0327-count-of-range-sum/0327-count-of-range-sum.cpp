#include <vector>

class Solution {
private:
    int countWhileMergeSort(std::vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) + 
                    countWhileMergeSort(sums, mid, end, lower, upper);
        
        int j = mid, k = mid, t = mid;
        // The right index pointers for counting valid range sums
        for (int i = start; i < mid; ++i) {
            while (k < end && sums[k] - sums[i] < lower) k++;
            while (j < end && sums[j] - sums[i] <= upper) j++;
            count += j - k;
        }

        // Standard merge step
        std::vector<long long> cache(end - start);
        int r = 0, idx = start;
        int p = start, q = mid;
        while (p < mid && q < end) {
            if (sums[p] < sums[q]) {
                cache[r++] = sums[p++];
            } else {
                cache[r++] = sums[q++];
            }
        }
        while (p < mid) cache[r++] = sums[p++];
        while (q < end) cache[r++] = sums[q++];

        for (int i = 0; i < r; ++i) {
            sums[start + i] = cache[i];
        }

        return count;
    }

public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        std::vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countWhileMergeSort(sums, 0, n + 1, lower, upper);
    }
};