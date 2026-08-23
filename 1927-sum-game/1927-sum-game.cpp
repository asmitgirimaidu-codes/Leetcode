class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int count1 = 0, count2 = 0;
        
        // Calculate sums and '?' counts for the left half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                count1++;
            } else {
                sum1 += num[i] - '0';
            }
        }
        
        // Calculate sums and '?' counts for the right half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                count2++;
            } else {
                sum2 += num[i] - '0';
            }
        }
        
        // If the total number of '?' is odd, Alice wins.
        if ((count1 + count2) % 2 != 0) {
            return true;
        }
        
        // Check if Bob can balance the equation
        return (sum1 - sum2) != 9 * (count2 - count1) / 2;
    }
};