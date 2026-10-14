#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Check if the sum is out of the valid range
        if (sum < 1 || sum > 9LL * num) {
            return "";
        }
        
        string result = "";
        for (int i = 0; i < num; ++i) {
            // We want to pick the largest possible digit for the current position (0 to 9)
            // such that the remaining sum can still be formed by the remaining (num - 1 - i) digits.
            int min_needed = std::max(0, sum - 9 * (num - 1 - i));
            int max_possible = std::min(9, sum);
            
            // To maximize the number lexicographically (or just maximize the value),
            // we greedily pick the largest digit in the valid range [min_needed, max_possible].
            int chosen_digit = max_possible;
            
            result +=to_string(chosen_digit);
            sum -= chosen_digit;
        }
        
        return result;
    }
};