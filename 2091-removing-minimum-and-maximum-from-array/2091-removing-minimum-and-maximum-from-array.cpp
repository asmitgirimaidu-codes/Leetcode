class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0, maxIdx = 0;
        
        // Step 1: Find the index of the minimum and maximum elements
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // Ensure minIdx is the smaller index for easier boundary checks
        if (minIdx > maxIdx) {
            swap(minIdx, maxIdx);
        }

        // Step 2: Calculate the cost for the three scenarios
        int opt1 = maxIdx + 1;                  // Both removed from the front
        int opt2 = n - minIdx;                  // Both removed from the back
        int opt3 = (minIdx + 1) + (n - maxIdx); // One from front, one from back

        // Step 3: Return the minimum of the three options
        return min({opt1, opt2, opt3});
    }
};