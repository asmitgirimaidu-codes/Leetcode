class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first_max = 0;
        int second_max = 0;
        
        for (int num : nums) {
            if (num > first_max) {
                second_max = first_max;
                first_max = num;
            } else if (num > second_max) {
                second_max = num;
            }
        }
        
        return (first_max - 1) * (second_max - 1);
    }
};