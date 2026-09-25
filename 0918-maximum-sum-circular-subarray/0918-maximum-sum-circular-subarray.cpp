class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0];
        int curMax = 0;
        int minSum = nums[0];
        int curMin = 0;

        for (int num : nums) {
            // Kadane's algorithm for maximum subarray sum
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            // Kadane's algorithm for minimum subarray sum
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            totalSum += num;
        }

        // If all elements are negative, maxSum will be the maximum single element (negative),
        // and totalSum == minSum, meaning totalSum - minSum would incorrectly evaluate to 0.
        if (maxSum < 0) {
            return maxSum;
        }

        // The maximum circular sum is either the standard maximum subarray sum (non-circular)
        // or the total sum minus the minimum subarray sum (wrapping around).
        return max(maxSum, totalSum - minSum);
    }
};