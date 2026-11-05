class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        
        // Get the rightmost set bit
        long long diff_bit = xor_sum & -xor_sum;
        
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if ((num & diff_bit) == 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};