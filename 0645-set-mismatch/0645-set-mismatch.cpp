class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        
        // Expected sums for numbers from 1 to n
        long long expectedSum = n * (n + 1) / 2;
        long long expectedSqSum = n * (n + 1) * (2 * n + 1) / 6;
        
        long long actualSum = 0;
        long long actualSqSum = 0;
        
        for (int num : nums) {
            actualSum += num;
            actualSqSum += (long long)num * num;
        }
        
        // Let x be the duplicate number and y be the missing number
        // actualSum - expectedSum = x - y
        long long sumDiff = actualSum - expectedSum;
        
        // actualSqSum - expectedSqSum = x^2 - y^2 = (x - y)(x + y)
        long long sqSumDiff = actualSqSum - expectedSqSum;
        
        // x + y = (x^2 - y^2) / (x - y)
        long long sumAdd = sqSumDiff / sumDiff;
        
        // Solve linear equations:
        // x = (sumDiff + sumAdd) / 2
        // y = sumAdd - x
        int duplicate = (sumDiff + sumAdd) / 2;
        int missing = sumAdd - duplicate;
        
        return {duplicate, missing};
    }
};