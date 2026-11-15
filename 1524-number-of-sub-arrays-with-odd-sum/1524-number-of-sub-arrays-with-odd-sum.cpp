class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, evenCount = 1;
        long long currentSum = 0;
        long long result = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;

            if (currentSum % 2 == 1) {
                // If current prefix sum is odd, add the number of previous even prefix sums
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                // If current prefix sum is even, add the number of previous odd prefix sums
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }

        return result;
    }
};