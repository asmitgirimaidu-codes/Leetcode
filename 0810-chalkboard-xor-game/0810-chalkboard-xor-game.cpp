class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        // Alice wins if the total XOR sum is 0, or if the number of elements is even
        return xorSum == 0 || nums.size() % 2 == 0;
    }
};