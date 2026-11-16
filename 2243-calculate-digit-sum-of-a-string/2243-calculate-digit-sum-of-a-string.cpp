#include <string>

class Solution {
public:
    string digitSum(string s, int k) {
        // Repeat the rounds while the length of s is strictly greater than k
        while (s.length() > k) {
            string next_s = "";
            
            // Divide s into consecutive groups of size k
            for (int i = 0; i < s.length(); i += k) {
                int group_sum = 0;
                
                // Calculate the sum of digits for the current group
                for (int j = i; j < min((int)s.length(), i + k); ++j) {
                    group_sum += s[j] - '0';
                }
                
                // Append the string representation of the sum to the next string
                next_s += to_string(group_sum);
            }
            
            // Update s with the newly formed string for the next round
            s = next_s;
        }
        
        return s;
    }
};