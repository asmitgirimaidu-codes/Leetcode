#include <vector>
#include <set>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSum = INT_MIN;

        // Fix the left column
        for (int c1 = 0; c1 < n; ++c1) {
            // Initialize row sums for the current pair of columns (c1, c2)
            std::vector<int> rowSums(m, 0);
            
            // Fix the right column
            for (int c2 = c1; c2 < n; ++c2) {
                for (int r = 0; r < m; ++r) {
                    rowSums[r] += matrix[r][c2];
                }

                // Find the max subarray sum no larger than k using prefix sum and set
                std::set<int> accuSet;
                accuSet.insert(0); // Base case for prefix sum starting from index 0
                int currentSum = 0;

                for (int sum : rowSums) {
                    currentSum += sum;
                    // We want currentSum - previousSum <= k => previousSum >= currentSum - k
                    auto it = accuSet.lower_bound(currentSum - k);
                    if (it != accuSet.end()) {
                        maxSum = std::max(maxSum, currentSum - *it);
                    }
                    accuSet.insert(currentSum);
                }
            }
        }

        return maxSum;
    }
};