class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        for (int x : nums) {
            int digit_sum = 0;
            int temp = x;
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }
            min_val = min(min_val, digit_sum);
        }
        return min_val;
    }
};