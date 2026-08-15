class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool all_zeros = true;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                all_zeros = false;
            }
        }
        
        // If all elements are 0, no non-zero XOR subsequence is possible
        if (all_zeros) {
            return 0;
        }
        
        // If the total XOR is already non-zero, take the whole array
        if (total_xor != 0) {
            return nums.size();
        }
        
        // If total XOR is 0, we can drop one element to make it non-zero
        return nums.size() - 1;
    }
};